#include <iostream>
#include <cstring>
using namespace std;
class student
{
private:
    char *name;
    int rollNo;
    double marks[5];
    float percentage;

public:
    student()
    {
        name = new char[1];
        name[0] = '\0';
        rollNo = 0;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = 0;
        }
        percentage = 0.0;
    }

    student(const char *n, int r, double m[], float p)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        rollNo = r;

        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }

        percentage = p;
    }

    student(const student &obj)
    {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);

        rollNo = obj.rollNo;

        for (int i = 0; i < 5; i++)
        {
            marks[i] = obj.marks[i];
        }

        percentage = obj.percentage;
    }

    ~student()
    {
        delete[] name;
    }

    void SetName(const char *n)
    {
        delete[] name;

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void SetRollno(int r)
    {
        rollNo = r;
    }

    void SetMarks(double m[])
    {
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }
    }

    void SetPercentage(float p)
    {
        percentage = p;
    }

    char *GetName()
    {
        return name;
    }

    int GetRollno()
    {
        return rollNo;
    }

    double *GetMarks()
    {
        return marks;
    }

    float GetPercentage()
    {
        return percentage;
    }

    void CalculatePercentage()
    {
        double total = 0;

        for (int i = 0; i < 5; i++)
        {
            total += marks[i];
        }

        percentage = (total / 500.0) * 100;
    }

    void Grade()
    {
        CalculatePercentage();

        cout << "Percentage: " << percentage << "%" << endl;

        if (percentage >= 80)
        {
            cout << "Grade: A" << endl;
        }
        else if (percentage >= 70)
        {
            cout << "Grade: B" << endl;
        }
        else if (percentage >= 60)
        {
            cout << "Grade: C" << endl;
        }
        else if (percentage >= 50)
        {
            cout << "Grade: D" << endl;
        }
        else
        {
            cout << "Grade: F" << endl;
        }
    }

    double HighestMarks()
    {
        double highest = marks[0];

        for (int i = 1; i < 5; i++)
        {
            if (marks[i] > highest)
            {
                highest = marks[i];
            }
        }

        return highest;
    }

    void Display()
    {
        cout << "\n===== STUDENT INFORMATION =====" << endl;

        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;

        cout << "Marks: ";

        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }

        cout << endl;

        Grade();

        cout << "Highest Marks: " << HighestMarks() << endl;
    }
};

int main()
{
    int n;
    cout << "\n\n===== ALL STUDENTS DATA =====\n";
    cout << "How many Student you want to store: ";
    cin >> n;

    student *students = new student[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << ":" << endl;

        students[i].Display();
    }

    delete[] students;

    return 0;
}