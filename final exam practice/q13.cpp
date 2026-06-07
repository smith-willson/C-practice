#include <iostream>
using namespace std;

// CHECKLIST:
// ✅ virtual keyword in B and C (not D)
// ✅ A's constructor called from D directly
// ✅ only ONE copy of A in memory

class A {
public:
    int data;
    A(int d) { data = d; }
};

class B : virtual public A {                    // ✅ virtual
public:
    B(int d) : A(d) {}
};

class C : virtual public A {                    // ✅ virtual
public:
    C(int d) : A(d) {}
};

class D : public B, public C {
public:
    D(int d) : A(d), B(d), C(d) {}             // ✅ A called from D
};

int main() {
    D obj(42);
    cout << obj.data << endl;                   // ✅ no ambiguity
}