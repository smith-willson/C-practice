#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

class calculator {
    private:
        int a, b, c;
    public:

        int add(int a, int b){
           return a + b;
        }

        int add(double a, double b){
           return a + b;
        }

        int add(int a, int b, int c){
            return  a + b + c;
        }

};

class Area {
public:

    // Square
    double calculateArea(int side) {
            
        return side * side * side;
    }

    // CUBOID
    double calculateArea(int length, int width, int height) {
        return length * width * height;
    }

    // VOLUME
    double calculateArea(double radius, int height) {
        return 3.14159 * radius * radius * height;
    }
};




int main() {
    // Math m;

    // cout << m.add(2, 3) << endl;      // calls first
    // cout << m.add(2, 3, 4) << endl;  // calls second

    calculator C;
    cout<<"THE ADDITION IS EQUAL TO: "<< C.add(3, 4)<< endl; 
    cout<<"THE ADDITION IS EQUAL TO: "<< C.add(3.7, 4.8)<< endl; 
    cout<<"THE ADDITION IS EQUAL TO: "<< C.add(3, 4, 9)<< endl; 



    Area a;
    cout<< "Cube: "<< a.calculateArea(5) << endl;
    cout<< "CUDOID: "<< a.calculateArea(5, 9)<< endl;
    cout<< "Cylinder: "<< a.calculateArea(5.9)<< endl;


    return 0;
}