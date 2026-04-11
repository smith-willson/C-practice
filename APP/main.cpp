#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <commctrl.h>
#include <shellapi.h>
#include <string>
#include <vector>
#include "ProjectManager.h"

#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "shell32.lib")

// Global UI Handles
HWND hList, hEditName, hEditTitle, hEditBudget;
HFONT hFont;
HBRUSH hBackBrush = CreateSolidBrush(RGB(25, 25, 25)); 
ProjectManager manager;

#define IDT_TIMER_SYNC 1001

void ShowNotification(HWND hwnd, const std::wstring& title, const std::wstring& message) {
    NOTIFYICONDATAW nid = { sizeof(nid) };
    nid.hWnd = hwnd;
    nid.uFlags = NIF_INFO;
    nid.dwInfoFlags = NIIF_INFO;
    wcscpy_s(nid.szInfoTitle, title.c_str());
    wcscpy_s(nid.szInfo, message.c_str());
    Shell_NotifyIconW(NIM_ADD, &nid);
    Shell_NotifyIconW(NIM_DELETE, &nid);
}

void RefreshProjectList() {
    SendMessage(hList, LVM_DELETEALLITEMS, 0, 0); 
    int i = 0;
    for (const auto& p : manager.projects) {
        LVITEMW lvi = { 0 };
        lvi.mask = LVIF_TEXT;
        lvi.iItem = i;
        lvi.iSubItem = 0;
        
        std::wstring name(p.clientName.begin(), p.clientName.end());
        lvi.pszText = (LPWSTR)name.c_str();
        SendMessageW(hList, LVM_INSERTITEMW, 0, (LPARAM)&lvi);

        std::wstring title(p.title.begin(), p.title.end());
        LVITEMW lviDesc = { LVIF_TEXT, i, 1 }; 
        lviDesc.pszText = (LPWSTR)title.c_str();
        SendMessageW(hList, LVM_SETITEMTEXTW, i, (LPARAM)&lviDesc);

        std::wstring budgetStr = std::to_wstring((int)p.budget) + L" $";
        LVITEMW lviBudget = { LVIF_TEXT, i, 2 };
        lviBudget.pszText = (LPWSTR)budgetStr.c_str();
        SendMessageW(hList, LVM_SETITEMTEXTW, i, (LPARAM)&lviBudget);
        i++;
    }
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CTLCOLORSTATIC: {
            HDC hdcStatic = (HDC)wp;
            SetTextColor(hdcStatic, RGB(220, 220, 220));
            SetBkMode(hdcStatic, TRANSPARENT);
            return (INT_PTR)hBackBrush;
        }
        case WM_CREATE: {
            hFont = CreateFontW(18, 0, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE, ANSI_CHARSET, 
                                OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
                                DEFAULT_PITCH | FF_SWISS, L"Segoe UI");

            // Input Fields
            CreateWindowW(L"Static", L"Client Name", WS_VISIBLE | WS_CHILD, 20, 20, 100, 20, hwnd, NULL, NULL, NULL);
            hEditName = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 45, 150, 25, hwnd, NULL, NULL, NULL);

            CreateWindowW(L"Static", L"Project Title", WS_VISIBLE | WS_CHILD, 185, 20, 100, 20, hwnd, NULL, NULL, NULL);
            hEditTitle = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 185, 45, 180, 25, hwnd, NULL, NULL, NULL);

            CreateWindowW(L"Static", L"Budget ($)", WS_VISIBLE | WS_CHILD, 380, 20, 80, 20, hwnd, NULL, NULL, NULL);
            hEditBudget = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 380, 45, 80, 25, hwnd, NULL, NULL, NULL);

            // Buttons
            CreateWindowW(L"Button", L"ADD", WS_VISIBLE | WS_CHILD | BS_FLAT, 480, 43, 70, 30, hwnd, (HMENU)1, NULL, NULL);
            CreateWindowW(L"Button", L"DELETE", WS_VISIBLE | WS_CHILD | BS_FLAT, 555, 43, 70, 30, hwnd, (HMENU)2, NULL, NULL);

            // Table
            hList = CreateWindowExW(0, WC_LISTVIEWW, L"", WS_VISIBLE | WS_CHILD | LVS_REPORT | LVS_SINGLESEL | WS_BORDER, 20, 90, 605, 300, hwnd, NULL, NULL, NULL);
            SendMessage(hList, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);

            LVCOLUMNW lvc = { LVCF_TEXT | LVCF_WIDTH, 0, 150, (LPWSTR)L"Client Name" };
            SendMessageW(hList, LVM_INSERTCOLUMNW, 0, (LPARAM)&lvc);
            lvc.pszText = (LPWSTR)L"Description"; lvc.cx = 320;
            SendMessageW(hList, LVM_INSERTCOLUMNW, 1, (LPARAM)&lvc);
            lvc.pszText = (LPWSTR)L"Budget"; lvc.cx = 100;
            SendMessageW(hList, LVM_INSERTCOLUMNW, 2, (LPARAM)&lvc);

            EnumChildWindows(hwnd, [](HWND child, LPARAM font) -> BOOL {
                SendMessage(child, WM_SETFONT, font, TRUE);
                return TRUE;
            }, (LPARAM)hFont);

            SetTimer(hwnd, IDT_TIMER_SYNC, 60000, NULL);
            manager.loadFromFile();
            RefreshProjectList();
            break;
        }
        case WM_COMMAND:
            if (LOWORD(wp) == 1) { // ADD Logic
                wchar_t bName[100], bTitle[100], bBudget[50];
                GetWindowTextW(hEditName, bName, 100);
                GetWindowTextW(hEditTitle, bTitle, 100);
                GetWindowTextW(hEditBudget, bBudget, 50);

                Project p;
                std::wstring wsName(bName), wsTitle(bTitle), wsBudget(bBudget);
                if (wsName.empty() || wsTitle.empty()) break;

                p.clientName = std::string(wsName.begin(), wsName.end());
                p.title = std::string(wsTitle.begin(), wsTitle.end());
                p.budget = std::stod(wsBudget.empty() ? L"0" : wsBudget);
                p.status = "Active";

                manager.addProject(p);
                RefreshProjectList();
                SetWindowTextW(hEditName, L""); SetWindowTextW(hEditTitle, L""); SetWindowTextW(hEditBudget, L"");
            }
            if (LOWORD(wp) == 2) { // DELETE Logic
                int selected = SendMessage(hList, LVM_GETNEXTITEM, -1, LVNI_SELECTED);
                if (selected != -1) {
                    manager.projects.erase(manager.projects.begin() + selected);
                    manager.saveToFile();
                    RefreshProjectList();
                    ShowNotification(hwnd, L"Project Removed", L"Selected project was deleted from the database.");
                }
            }
            break;
        case WM_TIMER:
            if (wp == IDT_TIMER_SYNC) {
                ShowNotification(hwnd, L"Sync Complete", L"System is synced with database.txt");
            }
            break;
        case WM_DESTROY:
            DeleteObject(hBackBrush);
            DeleteObject(hFont);
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    INITCOMMONCONTROLSEX icex = { sizeof(icex), ICC_WIN95_CLASSES };
    InitCommonControlsEx(&icex);
    WNDCLASSW wc = { 0 };
    wc.hbrBackground = hBackBrush;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"ModernFreelance";
    wc.lpfnWndProc = WindowProcedure;
    RegisterClassW(&wc);
    CreateWindowW(L"ModernFreelance", L"Freelance Pro v2.1", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 660, 480, NULL, NULL, hInst, NULL);
    MSG msg = { 0 };
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}