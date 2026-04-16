#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(string c = "") : color(c) {}

    virtual void input() {
        cout << "What is the color of shape: ";
        getline(cin >> ws, color);
    }

    virtual void display() {
        cout << "Color: " << color << endl;
    }

    virtual ~Shape() {}
};

class Shape2D : public Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Shape3D : public Shape {
public:
    virtual double volume() = 0;
    virtual double surfaceArea() = 0;
};

class Rectangle : public Shape2D
{
protected:
    double length;
    double width;

public:
    void input() override
    {
        Shape::input();
        do
        {
            cout << "Enter width (> 0): ";
            cin >> width;
        } while (width <= 0);
        do
        {
            cout << "Enter length (> 0): ";
            cin >> length;
        } while (length <= 0);
    }

    double area() override
    {
        return width * length;
    }

    double perimeter() override
    {
        return 2 * (width + length);
    }

    void display() override
    {
        Shape::display();
        cout << "Length    : " << length << endl;
        cout << "Width     : " << width << endl;
        cout << "Area      : " << area() << endl;
        cout << "Perimeter : " << perimeter() << endl;
    }

    virtual ~Rectangle() {}
};

class Triangle : public Shape2D
{
protected:
    double base;
    double height;
    double side1;
    double side2;
    double side3;

public:
    void input() override
    {
        Shape::input();
        do
        {
            cout << "Enter base (> 0): ";
            cin >> base;
        } while (base <= 0);
        do
        {
            cout << "Enter height (> 0): ";
            cin >> height;
        } while (height <= 0);
        do
        {
            cout << "Enter side 1 (> 0): ";
            cin >> side1;
        } while (side1 <= 0);
        do
        {
            cout << "Enter side 2 (> 0): ";
            cin >> side2;
        } while (side2 <= 0);
        do
        {
            cout << "Enter side 3 (> 0): ";
            cin >> side3;
        } while (side3 <= 0);
    }

    double area() override
    {
        return 0.5 * base * height;
    }

    double perimeter() override
    {
        return side1 + side2 + side3;
    }

    void display() override
    {
        Shape::display();
        cout << "Base      : " << base << endl;
        cout << "Height    : " << height << endl;
        cout << "Area      : " << area() << endl;
        cout << "Perimeter : " << perimeter() << endl;
    }

    virtual ~Triangle() {}
};

class Regularpentagon : public Shape2D
{
protected:
    double side;

public:
    void input() override
    {
        Shape::input();
        do
        {
            cout << "Enter length of side( >= 0): ";
            cin >> side;
        } while (side <= 0);
    }

    double area() override
    {
        return (5 * side * side / 4) * sqrt(5 + 2 * sqrt(5));
    }

    double perimeter() override
    {
        return 5 * side;
    }

    void display() override {
    Shape::display();
    cout << "Side      : " << side << endl;
    cout << "Area      : " << area() << endl;
    cout << "Perimeter : " << perimeter() << endl;
    }
};

class cylinder : public Shape3D
{
protected:
    double radius;
    double height;

public:
    void input() override
    {
        Shape::input();
        do
        {
            cout << "Enter radius (> 0): ";
            cin >> radius;
        } while (radius <= 0);
        do
        {
            cout << "Enter height (> 0): ";
            cin >> height;
        } while (height <= 0);
    }

    double volume() override {
    return 3.14159 * radius * radius * height;
}

    double surfaceArea() override {
    return 2 * 3.14159 * radius * (height + radius);
}

    void display() override
    {
        Shape::display();
        cout << "Radius    : " << radius << endl;
        cout << "Height    : " << height << endl;
        cout << "Volume        : " << volume() << endl;
        cout << "Surface Area  : " << surfaceArea() << endl;
    }

    virtual ~cylinder() {}
};

class sphere : public Shape3D
{
protected:
    double radius;

public:
    void input() override
    {
        Shape ::input();
        do
        {
            cout << "Enter radius (> 0): ";
            cin >> radius;
        } while (radius <= 0);
    }

    double volume() override
    {
        return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
    }

    double surfaceArea() override
    {
        return 4 * 3.14159 * radius * radius;
    }

    void display() override
    {
        Shape::display();
        cout << "Radius    : " << radius << endl;
        cout << "Volume        : " << volume() << endl;
        cout << "Surface Area  : " << surfaceArea() << endl;
    }

    virtual ~sphere() {}
};

int main(){

    Shape2D* shapes2D[3];
        shapes2D[0] = new Regularpentagon();
        shapes2D[1] = new Rectangle();
        shapes2D[2] = new Triangle();

    for (int i = 0; i < 3; i++){
        cout<<"\n=================================" <<endl;
        shapes2D[i]->input();
    }

    for (int i = 0; i < 3; i++){
        cout<<"\n=================================" <<endl;
        shapes2D[i]->display();
    }

    for (int i = 0; i < 3; i++){
        delete shapes2D[i];
    }

    Shape3D* shapes3D[2];
        shapes3D[0] = new cylinder();
        shapes3D[1] = new sphere();

    for (int i = 0; i < 2; i++){
        cout<<"\n=================================" <<endl;
        shapes3D[i]->input();
    }

    for (int i = 0; i < 2; i++){
        cout<<"\n=================================" <<endl;
        shapes3D[i]->display();
    }

    for (int i = 0; i < 2; i++){
        delete shapes3D[i];
    }

    return 0;
}



