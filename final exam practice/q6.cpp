#include <iostream>
using namespace std;
class divider
{
public:
    int first;
    int second;

    divider(int x, int y)
    {
        first = x;
        second = y;
    }

    float divide()
    {
        if (second == 0)
        {
            throw invalid_argument("Cannot divide by zero");
        }
        return static_cast<float>(first) / second;
    }

    void display()
    {
        cout << first << " / " << second << " = " << divide() << endl;
    }
};

int main()
{
    try
    {
        divider d1(36, 0);
        d1.display();
    }
    catch (invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    divider d2(36, 18);
    d2.display();
}