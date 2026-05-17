#include <iostream>
#include <cstring>
using namespace std;

class post
{
protected:
    char name[50];
    char to[100];
    float StampCost;

public:
    post()
    {
        strcpy(name, "");
        strcpy(to, "");
        StampCost = 1.0;
    }

    void read()
    {

        cout << "Enter the Sender name: ";
        cin.getline(name, 50);

        cout << "Enter the Receiver's Address: ";
        cin.getline(to, 100);

        cout << "Enter the Stamp's cost: ";
        cin >> StampCost;
    }

    void print()
    {
        cout << "Sender: " << name << endl;
        cout << "Receiver'address: " << to << endl;
        cout << "Stamp's Cost: " << StampCost << " $" << endl;
    }

    float totalCost()
    {
        return StampCost;
    }
};

class RegisteredPost : public post
{
protected:
    float weight;
    float regCost;

public:
    RegisteredPost()
    {
        weight = 20.0;
        regCost = 10;
    }

    void read()
    {
        post::read();
        cout << "Enter the weight of the package: ";
        cin >> weight;

        cout << "Enter the registration Cost: ";
        cin >> regCost;
    }

    void print()
    {
        post::print();
        cout << "Weight of the package: " << weight << " gm" << endl;
        cout << "Registration Cost: " << regCost << " $" << endl;
    }

    float totalCost()
    {
        return post::totalCost() + regCost;
    }
};

class InsuredRgisteredPost : public RegisteredPost
{
protected:
    float AmtInsured;

public:
    InsuredRgisteredPost()
    {
        AmtInsured = 20.0;
    }

    void read()
    {
        RegisteredPost::read();
        cout << "Enter the Insurence of Package: ";
        cin >> AmtInsured;
    }

    void print()
    {
        RegisteredPost::print();
        cout << "The Insurance Issued: " << AmtInsured << " $" << endl;
    }

    float totalCost()
    {
        return RegisteredPost::totalCost() + AmtInsured;
    }
};

#include <iostream>
using namespace std;
int main()
{
    InsuredRgisteredPost envelope;
    envelope.read();
    cout << "Post Details..\n";
    envelope.print();
    return 0;
}