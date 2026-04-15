#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
protected:
    string color;

public:
    Shape(string c = "")
    {
        color = c;
    }

    virtual void input()
    {
        cout << "What is the color of shape: ";
        getline(cin >> ws, color);
    }

    virtual void display()
    {
        cout << "Color: " << color << endl;
    }

    virtual double volume()
    {
        return 0;
    }

    virtual double surfaceArea()
    {
        return 0;
    }

    virtual double Area()
    {
        return 0;
    }

    virtual double peri()
    {
        return 0;
    }

    virtual ~Shape() {}
};

class Rectangle : public Shape
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

    double Area() override
    {
        return width * length;
    }

    double peri() override
    {
        return 2 * (width + length);
    }

    void display() override
    {
        Shape::display();
        cout << "Length    : " << length << endl;
        cout << "Width     : " << width << endl;
        cout << "Area      : " << Area() << endl;
        cout << "Perimeter : " << peri() << endl;
    }

    virtual ~Rectangle() {}
};

class Triangle : public Shape
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

    double Area() override
    {
        return 0.5 * base * height;
    }

    double peri() override
    {
        return side1 + side2 + side3;
    }

    void display() override
    {
        Shape::display();
        cout << "Base      : " << base << endl;
        cout << "Height    : " << height << endl;
        cout << "Area      : " << Area() << endl;
        cout << "Perimeter : " << peri() << endl;
    }

    virtual ~Triangle() {}
};

class cylinder : public Shape
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

    double Area() override
    {
        return 3.14159 * radius * radius * height;
    }

    double peri() override
    {
        return 2 * 3.14159 * radius * height;
    }

    void display() override
    {
        Shape::display();
        cout << "Radius    : " << radius << endl;
        cout << "Height    : " << height << endl;
        cout << "Area      : " << Area() << endl;
        cout << "Perimeter : " << peri() << endl;
    }

    virtual ~cylinder() {}
};

class sphere : public Shape
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
        cout << "Volume    : " << Area() << endl;
        cout << "Surface Area : " << peri() << endl;
    }

    virtual ~sphere() {}
};

class Regularpentagon : public Shape
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

    double Area() override
    {
        return (5 * side * side / 4) * sqrt(5 + 2 * sqrt(5));
    }

    double peri() override
    {
        return 5 * side;
    }
};

int main(){
    Shape* shapes[5];

    shapes[0] = new Rectangle();
    shapes[1] = new Triangle();
    shapes[2] = new cylinder();
    shapes[3] = new sphere();
    shapes[4] = new Regularpentagon();

    for (int i = 0; i < 5; i++){
        cout<<"\n=================================" <<endl;
        shapes[i]->input();
    }

    for (int i = 0; i < 5; i++){
        cout<<"\n=================================" <<endl;
        shapes[i]->display();
    }

    for (int i = 0; i < 5; i++){
        delete shapes[i];
    }

    return 0;
}



