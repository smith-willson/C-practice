#include <iostream>
using namespace std;
template <class T>
class Matrix {
    T a[2][2];

public:
    void input() {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                cin >> a[i][j];
    }

    void display() {
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    T determinant() {
        return (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
    }

    Matrix operator+(Matrix m) {
        Matrix temp;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                temp.a[i][j] = a[i][j] + m.a[i][j];
        return temp;
    }

    Matrix operator-(Matrix m) {
        Matrix temp;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                temp.a[i][j] = a[i][j] - m.a[i][j];
        return temp;
    }
};
