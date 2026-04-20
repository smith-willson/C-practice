#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int num;

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    cout << "\nNumbers: ";
    for (int x : v)
    {
        cout << x << " ";
    }

    int sum = 0;
    int largest = v[0];

    for (int x : v)
    {
        sum += x;

        if (x > largest)
        {
            largest = x;
        }
    }

    cout << "\nSum = " << sum;
    cout << "\nlargest = " << largest;

    return 0;
}