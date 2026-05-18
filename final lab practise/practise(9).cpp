#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

struct User
{
    string username;
    string password;
    string hint;
};

int loadUser(User users[], int maxSize)
{
    ifstream file("users.txt");
    int count = 0;

    while (getline(file, users[count].username, ','))
    {
        getline(file, users[count].password, ',');
        getline(file, users[count].hint);
        count++;
    }

    file.close();

    return count;
}

string getPassword()
{
    string pass = "";
    bool hidden = true;
    char ch;

    while (true)
    {
        ch = _getch();

        if (ch == '\r')
        {
            if (pass.length() < 5)
            {
                cout << RED << "\n password must be 5 characters long.\n password: " << RESET;

                pass = "";
                continue;
            }
            break;
        }

        else if (ch == '\t')
        {
            hidden = !hidden;
            for (int i = 0; i < pass.length(); i++)
                cout << "\b \b";
            for (char c : pass)
                cout << (hidden ? '*' : c);
        }
        else if (ch == '\b' && !pass.empty())
        {
            pass.pop_back();
            cout << "\b \b";
        }
        else if (ch != '\b')
        {
            pass += ch;
            cout << (hidden ? '*' : ch);
        }
    }
    cout << endl;
    return pass;
}

void login(User users[], int totalUsers)
{
    string userInput, passInput;
    int attempt = 3;

    while (attempt > 0)
    {
        cout << endl;
        cout << CYAN << "\nEnter Username: " << RESET;
        getline(cin, userInput);
        while (userInput.empty())
            getline(cin, userInput);

        cout << CYAN << "enter password: " << RESET;
        passInput = getPassword();

        bool found = false;
        for (int i = 0; i < totalUsers; i++)
        {
            if (userInput == users[i].username && passInput == users[i].password)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << GREEN << BOLD << "\n login successful! welcome " << userInput << RESET << endl;
            return;
        }

        else
        {
            attempt--;
            cout << RED << "invalid username or password! " << RESET << endl;
            cout << YELLOW << attempt << " attempt(s) left" << RESET << endl;

            if (attempt == 1)
            {
                cout << YELLOW << "forgot password? (y/n): " << RESET;
                char ans;
                cin >> ans;
                cin.ignore();
                if (ans == 'y' || ans == 'Y')
                {
                    cout << CYAN << "Enter Username to get Hint: " << RESET;
                    string hintUser;
                    getline(cin, hintUser);

                    bool hintfound = false;
                    for (int i = 0; i < totalUsers; i++)
                    {
                        if (hintUser == users[i].username)
                        {
                            cout << YELLOW << "hint: " << users[i].hint << RESET << endl;
                            hintfound = true;
                            break;
                        }
                    }
                    if (!hintfound)
                        cout << RED << "USERNAME NOT FOUND" << RESET << endl;
                }
            }
        }
    }

    cout << RED << BOLD << "\nACCESS DENIED! ACCOUNT LOCKED." << RESET << endl;
}

void registerUser(User users[], int &totalUsers)
{
    string newUsername, newPassword, newHint;

    cout << endl;
    cout << CYAN << "Enter New User: " << RESET;
    getline(cin, newUsername);
    while (newUsername.empty())
        getline(cin, newUsername);
    for (int i = 0; i < totalUsers; i++)
    {
        if (users[i].username == newUsername)
        {
            cout << RED << "username already exists!" << RESET << endl;
            return;
        }
    }

    cout << CYAN << "enter password: " << RESET;
    newPassword = getPassword();

    cout << CYAN << "Enter a hint for your password: " << RESET;
    getline(cin, newHint);
    while (newHint.empty())
        getline(cin, newHint);

    ofstream file("users.txt", ios::app);
    file << newUsername << "," << newPassword << "," << newHint << endl;

    if (file)
    {
        users[totalUsers].username = newUsername;
        users[totalUsers].password = newPassword;
        users[totalUsers].hint = newHint;
        totalUsers++;
        cout << GREEN << "Registration successful!" << RESET << endl;
    }
    else
    {
        cout << RED << "Failed to open users file." << RESET << endl;
    }
}
int main()
{
    User users[100];
    int totalUsers = loadUser(users, 100);

    cout << BOLD << CYAN << "========login Menu=======" << RESET << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1)
        login(users, totalUsers);
    else if (choice == 2)
        registerUser(users, totalUsers);
    else
        cout << GREEN << "Goodbye!" << RESET << endl;

    return 0;
}