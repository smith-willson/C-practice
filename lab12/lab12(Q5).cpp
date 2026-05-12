#include <iostream>
using namespace std;

class Complex_No {
private:
    float real;
    float imag;

public:
   
    Complex_No() {
        real = 0;
        imag = 0;
    }

    
    Complex_No(float r, float i) {
        real = r;
        imag = i;
    }

    
    Complex_No operator+(const Complex_No& other) {
        return Complex_No(real + other.real, imag + other.imag);
    }

    
    Complex_No operator-(const Complex_No& other) {
        return Complex_No(real - other.real, imag - other.imag);
    }

    
    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};


template <class T>
class Matrix {
private:
    T data[2][2];

public:
    // Constructor
    Matrix(T a, T b, T c, T d) {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }

    // Default constructor
    Matrix() {}

    
    void Display() {
        for (int i = 0; i < 2; i++) {
            cout << "| ";
            for (int j = 0; j < 2; j++) {
                data[i][j].display();
                cout << "\t";
            }
            cout << "|" << endl;
        }
    }

    
    Matrix<T> operator+(const Matrix<T>& other) {
        return Matrix<T>(
            data[0][0] + other.data[0][0],
            data[0][1] + other.data[0][1],
            data[1][0] + other.data[1][0],
            data[1][1] + other.data[1][1]
        );
    }

    
    Matrix<T> operator-(const Matrix<T>& other) {
        return Matrix<T>(
            data[0][0] - other.data[0][0],
            data[0][1] - other.data[0][1],
            data[1][0] - other.data[1][0],
            data[1][1] - other.data[1][1]
        );
    }
};


int main() {
    Matrix<Complex_No> m1(
        Complex_No(1, 2),  Complex_No(3, 4),
        Complex_No(5, 6),  Complex_No(7, 8)
    );

    Matrix<Complex_No> m2(
        Complex_No(2, -1), Complex_No(1, 3),
        Complex_No(4, -2), Complex_No(6, 1)
    );

    cout << "Matrix 1:" << endl;
    m1.Display();

    cout << "\nMatrix 2:" << endl;
    m2.Display();

    cout << "\nM1 + M2:" << endl;
    (m1 + m2).Display();

    cout << "\nM1 - M2:" << endl;
    (m1 - m2).Display();

    return 0;
}