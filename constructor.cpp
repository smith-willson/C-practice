#include <iostream>
using namespace std;
class Student
{ // Encapsulation.........
protected:
    string StudentID;
    string password;

public:
    string name;
    string department;
    int roll_no;
    float CGPA;
    int Batch;

    Student(string StudentID, string password, int roll_no, string name, string department, float CGPA, int Batch)
    { // constructor intialization..

        this -> StudentID = StudentID;
        this -> password = password;
        this -> name = name;
        this -> roll_no = roll_no;
        this -> CGPA = CGPA;
        this -> department = department;
        this -> Batch = Batch;
    }
    // Setter functions
    void setStudentID(string id)
    {
        StudentID = id;
    }
    // getter functions
    string getStudentID()
    {
        return StudentID;
    }

    void setpassword(string pass)
    {
        password = pass;
    }

    string getpassword()
    {
        return password;
    }
};

void input(Student &S)
{
    string ID;
    cout << "Enter your StudentID: ";
    cin >> ID;
    S.setStudentID(ID); // Important point
    string pass;
    cout << "Enter your Password: ";
    cin >> pass;
    S.setpassword(pass); // that's how to cin into protected variables
    cout << "Enter your name: ";
    cin >> S.name;
    cout << "Enter your Roll_no: ";
    cin >> S.roll_no;
    cout << "Enter your Department: ";
    cin >> S.department;
    cout << "Enter your Batch: ";
    cin >> S.Batch;
    cout << "Enter your CGPA: ";
    cin >> S.CGPA;
    cout << "\nADDED SUCCESSFULLY..........\n\n\n";
}

void print(Student &S)
{
    cout << "StudentID = " << S.getStudentID() << "\n"
         << "password = " << S.getpassword() << "\n"
         << "Name = " << S.name << "\n"
         << "Department = " << S.department << "\n"
         << "Batch = " << S.Batch << "\n"
         << "CGPA = " << S.CGPA << "\n"
         << "Roll_no = " << S.roll_no << "\n";
}

int main()
{   
    Student S1("", "", 0, "", "", 0.0, 0); // construction Initailization
    input(S1);
    print(S1);












    
    return 0;
}