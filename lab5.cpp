#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
Q1:
If A is derived from B and B is derived from C, then for object of A:
- Constructor order: C -> B -> A
- Destructor order: A -> B -> C

Q2:
To keep base class public members accessible inside derived class,
but not publicly accessible through derived class objects,
use protected inheritance.

Syntax:
class Derived : protected Base
{
    // ...
};
*/

// ----------------------------- Q3 -----------------------------
class Student {
protected:
    string name;
    int rollNo;
    float marks1, marks2, marks3, marks4, marks5; // 5 courses, each out of 100

public:
    Student() : name(""), rollNo(0), marks1(0), marks2(0), marks3(0), marks4(0), marks5(0) {}

    Student(const string& n, int r, float m1, float m2, float m3, float m4, float m5)
        : name(n), rollNo(r), marks1(m1), marks2(m2), marks3(m3), marks4(m4), marks5(m5) {}

    float BaseTotal() const {
        return marks1 + marks2 + marks3 + marks4 + marks5;
    }

    virtual float CalculatePercentage() const {
        // Base class behavior (for reference only)
        return (BaseTotal() / 500.0f) * 100.0f;
    }

    virtual void Display() const {
        cout << "Name: " << name << ", Roll No: " << rollNo << "\n";
        cout << "Base Total Marks: " << BaseTotal() << "/500\n";
        cout << fixed << setprecision(2)
             << "Percentage: " << CalculatePercentage() << "%\n";
    }

    virtual ~Student() {}
};

class ScienceStudent : public Student {
private:
    float practicalMarks; // out of 150

public:
    ScienceStudent() : Student(), practicalMarks(0) {}

    ScienceStudent(const string& n, int r, float m1, float m2, float m3, float m4, float m5, float practical)
        : Student(n, r, m1, m2, m3, m4, m5), practicalMarks(practical) {}

    float CalculatePercentage() const override {
        float total = BaseTotal() + practicalMarks; // out of 650
        return (total / 650.0f) * 100.0f;
    }

    void Display() const override {
        cout << "Science Student\n";
        cout << "Name: " << name << ", Roll No: " << rollNo << "\n";
        cout << "Theory Total: " << BaseTotal() << "/500\n";
        cout << "Practical Marks: " << practicalMarks << "/150\n";
        cout << "Grand Total: " << (BaseTotal() + practicalMarks) << "/650\n";
        cout << fixed << setprecision(2)
             << "Percentage: " << CalculatePercentage() << "%\n";
    }
};

class ArtsStudent : public Student {
private:
    float optionalMarks; // out of 100

public:
    ArtsStudent() : Student(), optionalMarks(0) {}

    ArtsStudent(const string& n, int r, float m1, float m2, float m3, float m4, float m5, float optionalM)
        : Student(n, r, m1, m2, m3, m4, m5), optionalMarks(optionalM) {}

    float CalculatePercentage() const override {
        float total = BaseTotal() + optionalMarks; // out of 600
        return (total / 600.0f) * 100.0f;
    }

    void Display() const override {
        cout << "Arts Student\n";
        cout << "Name: " << name << ", Roll No: " << rollNo << "\n";
        cout << "Theory Total: " << BaseTotal() << "/500\n";
        cout << "Optional Course Marks: " << optionalMarks << "/100\n";
        cout << "Grand Total: " << (BaseTotal() + optionalMarks) << "/600\n";
        cout << fixed << setprecision(2)
             << "Percentage: " << CalculatePercentage() << "%\n";
    }
};

// -------------------------- Q4 and Q5 -------------------------
class Post {
protected:
    string name;
    string to;
    float stampCost;

public:
    Post() : name(""), to(""), stampCost(1.0f) {}

    virtual void Read() {
        cout << "Enter sender name: ";
        getline(cin, name);
        cout << "Enter receiver address: ";
        getline(cin, to);
        cout << "Enter stamp cost: ";
        cin >> stampCost;
        cin.ignore(10000, '\n');
    }

    virtual void Print() const {
        cout << "\nSender Name: " << name << "\n";
        cout << "Receiver Address: " << to << "\n";
        cout << "Stamp Cost: $" << fixed << setprecision(2) << stampCost << "\n";
        cout << "Total Cost: $" << fixed << setprecision(2) << TotalCost() << "\n";
    }

    virtual float TotalCost() const {
        return stampCost;
    }

    virtual ~Post() {}
};

class RegisteredPost : public Post {
protected:
    float weight;
    float registrationCost;

public:
    RegisteredPost() : Post(), weight(20.0f), registrationCost(10.0f) {}

    void Read() override {
        Post::Read();
        cout << "Enter weight (grams): ";
        cin >> weight;
        cout << "Enter registration cost: ";
        cin >> registrationCost;
        cin.ignore(10000, '\n');
    }

    void Print() const override {
        Post::Print();
        cout << "Weight: " << weight << " g\n";
        cout << "Registration Cost: $" << fixed << setprecision(2) << registrationCost << "\n";
        cout << "Total Cost (Registered): $" << fixed << setprecision(2) << TotalCost() << "\n";
    }

    float TotalCost() const override {
        return stampCost + registrationCost;
    }
};

class InsuredRegisteredPost : public RegisteredPost {
private:
    float amtInsured;

public:
    InsuredRegisteredPost() : RegisteredPost(), amtInsured(20.0f) {}

    void Read() override {
        RegisteredPost::Read();
        cout << "Enter insured amount: ";
        cin >> amtInsured;
        cin.ignore(10000, '\n');
    }

    void Print() const override {
        cout << "\nPost Details..\n";
        cout << "---------------------------\n";
        cout << "Sender Name: " << name << "\n";
        cout << "Receiver Address: " << to << "\n";
        cout << "Stamp Cost: $" << fixed << setprecision(2) << stampCost << "\n";
        cout << "Weight: " << weight << " g\n";
        cout << "Registration Cost: $" << fixed << setprecision(2) << registrationCost << "\n";
        cout << "Insured Amount: $" << fixed << setprecision(2) << amtInsured << "\n";
        cout << "Total Cost: $" << fixed << setprecision(2) << TotalCost() << "\n";
        cout << "---------------------------\n";
    }

    float TotalCost() const override {
        return stampCost + registrationCost + amtInsured;
    }
};

// ----------------------------- Q7 -----------------------------
class Product {
protected:
    string name;
    int productId;

public:
    Product() : name(""), productId(0) {}
    Product(const string& n, int id) : name(n), productId(id) {}

    virtual void ShowData() const {
        cout << "Name: " << name << ", Product ID: " << productId << "\n";
    }

    virtual ~Product() {}
};

class UtilityItem : public Product {
private:
    float discount;

public:
    UtilityItem() : Product(), discount(0) {}
    UtilityItem(const string& n, int id, float d) : Product(n, id), discount(d) {}

    void ShowData() const override {
        cout << "Utility Item -> ";
        Product::ShowData();
        cout << "Discount: " << fixed << setprecision(2) << discount << "%\n";
    }
};

class FoodItem : public Product {
private:
    string expiryDate;

public:
    FoodItem() : Product(), expiryDate("") {}
    FoodItem(const string& n, int id, const string& exp) : Product(n, id), expiryDate(exp) {}

    void ShowData() const override {
        cout << "Food Item -> ";
        Product::ShowData();
        cout << "Expiry Date: " << expiryDate << "\n";
    }
};

// -------------------------- Driver/Test ------------------------
int main() {
    cout << "===== Q3: Student Hierarchy Test =====\n";
    ScienceStudent s1("Ali", 101, 78, 82, 75, 80, 85, 130);
    ArtsStudent a1("Sara", 202, 88, 79, 84, 77, 81, 90);
    s1.Display();
    cout << "\n";
    a1.Display();

    cout << "\n\n===== Q4 & Q5: Post Hierarchy Test =====\n";
    InsuredRegisteredPost envelope;
    envelope.Read();
    envelope.Print();

    cout << "\n===== Q7: Product Hierarchy Test =====\n";
    UtilityItem u1("Detergent", 501, 15.0f);
    FoodItem f1("Biscuits", 801, "2026-12-31");
    u1.ShowData();
    cout << "\n";
    f1.ShowData();

    return 0;
}
