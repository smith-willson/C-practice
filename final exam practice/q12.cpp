#include <iostream>
using namespace std;

// CHECKLIST:
// ✅ : public BaseClass
// ✅ Base constructor called with : Base(args)
// ✅ virtual destructor in base
// ✅ override methods in child

class Person {
public:
    string name;
    int age;

    Person(string n, int a) {                   // ✅ base constructor
        name = n;
        age = a;
    }

    virtual void display() {                    // ✅ virtual
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual ~Person() {}                        // ✅ virtual destructor
};

class Student : public Person {                 // ✅ : public Person
    string degree;
public:
    Student(string n, int a, string d)
        : Person(n, a) {                        // ✅ call base constructor
        degree = d;
    }

    void display() {                            // ✅ override
        Person::display();                      // ✅ call parent method
        cout << "Degree: " << degree << endl;
    }
};

int main() {
    Student s("Ali", 20, "CS");
    s.display();
}