#include <iostream>
#include "lab12(Q3).h"
using namespace std;

int main() {
    Matrix<int> m1, m2, sum;

    cout << "Enter first matrix:\n";
    m1.input();

    cout << "Enter second matrix:\n";
    m2.input();

    sum = m1 + m2;

    cout << "Sum Matrix:\n";
    sum.display();

    cout << "Determinant of first matrix: ";
    cout << m1.determinant()<<endl;

    cout << "Determinant of second Matrix: ";
    cout << m2.determinant()<<endl;

    return 0;
}