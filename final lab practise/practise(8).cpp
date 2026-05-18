#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class loginsystem
{
private:
    string username;
    string password;

public:
    loginsystem()
    {
        username = "admin";
        password = "12345";
    }

    void login()
    {
        string userInput;
        string passInput;
        int attempt = 3;
        while (attempt > 0)
        {
            passInput = "";
            bool hidden = true;

            cout << "Enter your username: ";
            cin >> userInput;

            cout << "Enter your Password: ";
            char ch;

            while (true)
            {
                ch = _getch();

                if (ch == '\r')
                {
                    if (passInput.length() < 5)
                    {
                        cout << "\nThe Password should be 5 digits long try again ....." << endl;
                        passInput = "";
                        continue;
                    }
                    break;
                }

                else if (ch == '\t')
                {
                    hidden = !hidden;

                    for (int i = 0; i < passInput.length(); i++)
                        cout << "\b \b";

                    for (char c : passInput)
                    {
                        if (hidden)
                            cout << '*';
                        else
                            cout << c;
                    }
                }

                else if (ch == '\b' && !passInput.empty())
                {
                    passInput.pop_back();

                    cout << "\b \b";
                }

                else if (ch != '\b')
                {
                    passInput += ch;

                    if (hidden)
                    {

                        cout << '*';
                    }

                    else
                        cout << ch;
                }
            }

            cout << endl;

            if (userInput == username && passInput == password)
            {
                cout << "login Successful!" << endl;
                return;
            }
            else
            {
                attempt--;
                cout << "Invalid Username or Password!" << endl;
                cout << attempt << " Attempt(s) left" << endl;
            }
        }

        cout << "Access denied!" << endl;
    }
};

int main()
{

    loginsystem obj;

    obj.login();

    return 0;
}
