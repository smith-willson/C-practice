#include <iostream>
using namespace std;

class car
{
public:
    string brand;
    string model;
    int year;

    car(string B = "", string M = "", int Y = 0000)
    {
        brand = B;
        model = M;
        year = Y;
    }

    void set()
    {
        cout << "What is the brand name: ";
        cin >> brand;
        cout << "what is the modal: ";
        cin >> model;
        cout << "Wnat is the year of model: ";
        cin >> year;

        cout << endl;
    }

    void display()
    {
        cout << "BRAND: " << brand << endl;
        cout << "MODEL: " << model << endl;
        cout << "YEAR: " << year << endl;
    }
};
int main()
{
    car c1;

    c1.set();
    c1.display();

    return 0;
}