#include <iostream>
using namespace std;

class Matrix {
private:
    float r11, r12, r21, r22;
    int rows, cols; // for dimension check

public:
    
    Matrix(float a = 0, float b = 0, float c = 0, float d = 0) {
        r11 = a; r12 = b;
        r21 = c; r22 = d;
        rows = 2;
        cols = 2;
    }

    
    float determinant() const {
        return (r11 * r22 - r12 * r21);
    }

    
    Matrix operator+(const Matrix& m) {
        if (this->rows != m.rows || this->cols != m.cols) {
            cout << "Matrix dimensions not equal. Cannot add.\n";
            return Matrix();
        }

        return Matrix(
            r11 + m.r11,
            r12 + m.r12,
            r21 + m.r21,
            r22 + m.r22
        );
    }

    
    bool operator>(const Matrix& m) {
        return this->determinant() > m.determinant();
    }

    
    bool operator==(const Matrix& m) {
        return this->determinant() == m.determinant();
    }

    
    void display() const {
        cout << r11 << " " << r12 << endl;
        cout << r21 << " " << r22 << endl;
    }
};

int main() {
    Matrix m1(1.5, 2.5, 3.5, 4.5);
    Matrix m2(5.1, 6.2, 7.3, 8.4);

    cout << "Matrix 1:\n";
    m1.display();

    cout << "\nMatrix 2:\n";
    m2.display();

    
    Matrix sum = m1 + m2;
    cout << "\nSum:\n";
    sum.display();

    
    if (m1 > m2)
        cout << "\nMatrix 1 has greater determinant\n";
    else
        cout << "\nMatrix 2 has greater or equal determinant\n";

    
    if (m1 == m2)
        cout << "Determinants are equal\n";
    else
        cout << "Determinants are not equal\n";

    return 0;
}