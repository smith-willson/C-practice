#include <iostream>
using namespace std;

// CHECKLIST:
//  Base class has pure virtual function (= 0)
//  Cannot create object of base class
//  Every derived class MUST implement it

class Shape {
public:
    virtual float area() = 0;       //  pure virtual
    void display() {                //  concrete method (allowed)
        cout << "Area: " << area() << endl;
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) { radius = r; }
    float area() {                  //  must implement
        return 3.14 * radius * radius;
    }
};

// class Rectangle : public Shape {
//     float w, h;
// public:
//     Rectangle(float a, float b) { w = a; h = b; }
//     float area() {                  //  must implement
//         return w * h;
//     }
// };

int main() {
    // Shape s;   cannot instantiate abstract class
    // Shape* arr[2];
    // arr[0] = new Circle(5);
    // arr[1] = new Rectangle(4, 6);

    // for(int i = 0; i < 2; i++)
    //     arr[i]->display();

    // for(int i = 0; i < 2; i++)
    //     delete arr[i];

    Circle s1(5);
    s1.display();


    return 0;

}