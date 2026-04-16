#include <iostream>
using namespace std;
class notification
{
public:
    void virtual send(string msg)
    {
        cout << "GENERIC NOTIFICATION\n"
             << msg << endl;
    }
    virtual ~notification() {};
};

class EmailNotification : public notification
{
public:
    void send(string msg) override
    {
        cout << "Email: " << msg << endl;
    }
    virtual ~EmailNotification() {};
};

class SecureEmailNotification : public EmailNotification
{
public:
    void send(string msg) override final
    {
        cout << "SECURE EMAIL (encrypted): " << msg << endl;
    }
    virtual ~SecureEmailNotification() {};
};

// 6. Attempted illegal override (commented out)
class HackedEmailNotification : public SecureEmailNotification
{
public:
    /*
    // ❌ This will cause COMPILE-TIME ERROR because send() is final in SecureEmailNotification
    void send(string msg) override {
        cout << "Hacked Email: " << msg << endl;
    }
    */

    // Explanation:
    // The function send() is marked as final in SecureEmailNotification,
    // so it cannot be overridden in any derived class.
};

int main()
{
    notification *n1[3];

    n1[0] = new notification();
    n1[1] = new EmailNotification();
    n1[2] = new SecureEmailNotification();

    for (int i = 0; i < 3; i++)
    {
        n1[i]->send("Hello mf");
    }

    for (int i = 0; i < 3; i++)
    {
        delete n1[i];
    }

    return 0;
}