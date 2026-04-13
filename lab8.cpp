// #include <iostream>
// #define PI 3.14159
// using namespace std;

// class Shape {
// protected:
//     float Area;
// public:
//     Shape() { Area = 0; }
//     virtual void Calculate_Area() = 0; // pure virtual
//     virtual void Display() {
//         cout << "Area = " << Area << endl;
//     }
// };

// class Circle : public Shape {
//     float radius;
// public:
//     Circle(float r) { radius = r; }
//     void Calculate_Area() { Area = PI * radius * radius; }
//     void Display() {
//         cout << "Circle Radius: " << radius << ", Area = " << Area << endl;
//     }
// };

// class Rectangle : public Shape {
//     float Length, Breadth;
// public:
//     Rectangle(float l, float b) { Length = l; Breadth = b; }
//     void Calculate_Area() { Area = Length * Breadth; }
//     void Display() {
//         cout << "Rectangle " << Length << "x" << Breadth
//              << ", Area = " << Area << endl;
//     }
// };


// int main() {
//     Shape *p;
//     Circle C1(5);
//     Rectangle R1(4, 6);

//     p = &C1;
//     p->Calculate_Area();
//     p->Display();

//     p = &R1;
//     p->Calculate_Area();
//     p->Display();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class DateTime {
//     int day, month, year, hours, minutes, seconds;
// public:
//     DateTime() { day=month=year=hours=minutes=seconds=0; }

//     void SetValue(int d, int m, int y) {
//         day=d; month=m; year=y;
//         hours=minutes=seconds=0;
//     }
//     void SetValue(int d, int m, int y, int h) {
//         day=d; month=m; year=y; hours=h;
//         minutes=seconds=0;
//     }
//     void SetValue(int d, int m, int y, int h, int min) {
//         day=d; month=m; year=y; hours=h; minutes=min;
//         seconds=0;
//     }
//     void SetValue(int d, int m, int y, int h, int min, int s) {
//         day=d; month=m; year=y; hours=h; minutes=min; seconds=s;
//     }
//     void Display() {
//         cout << day << "/" << month << "/" << year
//              << " " << hours << ":" << minutes << ":" << seconds << endl;
//     }
// };

// class abc {
// public:
//     virtual void func() = 0; // pure virtual
// };

// class xyz : public abc {
// public:
//     void func() { cout << "this is function of xyz"; }
// };

// int main() {
//     abc obj1;  //  ERROR here
//     xyz obj2;  //  fine
//     obj1.func();
//     obj2.func();
//     return 0;
// }

