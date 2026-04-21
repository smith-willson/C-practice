// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     vector<int> v;
//     int num;

//     cout << "Enter 5 numbers: ";
//     for (int i = 0; i < 5; i++)
//     {
//         cin >> num;
//         v.push_back(num);
//     }

//     cout << "\nNumbers: ";
//     for (int x : v)
//     {
//         cout << x << " ";
//     }

//     int sum = 0;
//     int largest = v[0];

//     for (int x : v)
//     {
//         sum += x;

//         if (x > largest)
//         {
//             largest = x;
//         }
//     }

//     cout << "\nSum = " << sum;
//     cout << "\nlargest = " << largest;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int num;
    int even = 0;
    int odd = 0;
    int largest = v[0];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    cout << "\nReverse order: ";
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }

    for (int x : v)
    {
        if (x % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    for (int x : v)
    {
        if (x < largest)
        {
            largest = x;
        }
    }
    cout << "\nEven Count = " << even;
    cout << "\nOdd Count = " << odd;
    cout << "\nlargest = " << largest;
    return 0;
}