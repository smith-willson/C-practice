#include <iostream>
using namespace std;
class Base {
public:
    Base()  { cout << "B+ "; }
    ~Base() { cout << "B- "; }
};

class Child : public Base {
    Base obj;
public:
    Child()  { cout << "C+ "; }
    ~Child() { cout << "C- "; }
};

int main() {
    Child c;
    return 0;
}