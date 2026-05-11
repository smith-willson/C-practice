// // // #include <iostream>
// // // using namespace std;

// // // template <class T>
// // // T findMax(T arr[], int size) {
// // //     T max = arr[0];
// // //     for(int i = 1; i < size; i++) {
// // //         if(arr[i] > max)
// // //             max = arr[i];
// // //     }
// // //     return max;
// // // }

// // template <class T>
// // class Matrix {
// //     T a[2][2];

// // public:
// //     void input() {
// //         for(int i=0;i<2;i++)
// //             for(int j=0;j<2;j++)
// //                 cin >> a[i][j];
// //     }

// //     void display() {
// //         for(int i=0;i<2;i++) {
// //             for(int j=0;j<2;j++)
// //                 cout << a[i][j] << " ";
// //             cout << endl;
// //         }
// //     }

// //     T determinant() {
// //         return (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
// //     }

// //     Matrix operator+(Matrix m) {
// //         Matrix temp;
// //         for(int i=0;i<2;i++)
// //             for(int j=0;j<2;j++)
// //                 temp.a[i][j] = a[i][j] + m.a[i][j];
// //         return temp;
// //     }

// //     Matrix operator-(Matrix m) {
// //         Matrix temp;
// //         for(int i=0;i<2;i++)
// //             for(int j=0;j<2;j++)
// //                 temp.a[i][j] = a[i][j] - m.a[i][j];
// //         return temp;
// //     }
// // };

// int main() {
//     Matrix<int> m1, m2, sum;

//     cout << "Enter first matrix:\n";
//     m1.input();

//     cout << "Enter second matrix:\n";
//     m2.input();

//     sum = m1 + m2;

//     cout << "Sum Matrix:\n";
//     sum.display();

//     cout << "Determinant of first matrix: ";
//     cout << m1.determinant();

//     return 0;
// }

// int main() {
//     Matrix<float> m1, m2, sum, diff;

//     cout << "Enter Matrix 1:\n";
//     m1.input();

//     cout << "Enter Matrix 2:\n";
//     m2.input();

//     cout << "Determinant m1: " << m1.determinant() << endl;
//     cout << "Determinant m2: " << m2.determinant() << endl;

//     sum = m1 + m2;
//     diff = m1 - m2;

//     cout << "Sum:\n";
//     sum.display();

//     cout << "Difference:\n";
//     diff.display();

//     return 0;
// }

// Assume Complex_No class already defined with + and - operators

// int main() {
//     Matrix<Complex_No> m1, m2, sum, diff;

//     cout << "Enter Matrix 1:\n";
//     m1.input();

//     cout << "Enter Matrix 2:\n";
//     m2.input();

//     sum = m1 + m2;
//     diff = m1 - m2;

//     cout << "Sum:\n";
//     sum.display();

//     cout << "Difference:\n";
//     diff.display();

//     return 0;
// }