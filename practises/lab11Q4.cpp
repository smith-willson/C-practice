#include <iostream>
using namespace std;

class Base {
public:
    int val;
    Base() : val(0) {}
};

class A : virtual public Base {};
class B : virtual public Base {};  // fixed added virtual 

class C : public A, public B {};

int main() {
    C obj;
    obj.val = 10;
    cout << obj.val << endl;
}