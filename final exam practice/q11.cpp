#include <iostream>
using namespace std;

// CHECKLIST:
// ✅ operator+ inside class
// ✅ operator<< as friend outside class
// ✅ friend returns ostream&
// ✅ return *this for = operator

class Vector {
public:
    float x, y;

    Vector(float a = 0, float b = 0) { x = a; y = b; }

    Vector operator+(Vector& v2) {              // ✅ overload +
        return Vector(x + v2.x, y + v2.y);
    }

    Vector operator=(Vector& v2) {              // ✅ overload =
        x = v2.x;
        y = v2.y;
        return *this;                           // ✅ return *this
    }

    friend ostream& operator<<(ostream& out, Vector& v) { // ✅ friend
        out << "(" << v.x << ", " << v.y << ")";
        return out;                             // ✅ return out
    }
};

int main() {
    Vector v1(1, 2), v2(3, 4);
    Vector v3 = v1 + v2;
    cout << v3 << endl;                         // prints: (4, 6)
}