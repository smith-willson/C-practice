#include <iostream>
using namespace std;

class Person {
protected:
    string name;0
public:
    Person(string n) : name(n) {}

    virtual void introduce() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
protected:
    int studentID;
public:
    Student(string n, int id) : Person(n), studentID(id) {}
};

class Teacher : virtual public Person {
protected:
    int employeeID;
public:
    Teacher(string n, int id) : Person(n), employeeID(id) {}
};

class TeachingAssistant : public Student, public Teacher {
public:
    TeachingAssistant(string n, int sid, int eid)
        : Person(n), Student(n, sid), Teacher(n, eid) {}

    void introduce() override {
        cout << "Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Employee ID: " << employeeID << endl;
    }
};

int main() {
    TeachingAssistant ta("Ali", 101, 5001);
    ta.introduce();
}