#include <iostream>
#include <cstring>
using namespace std;

class student
{
private:
    char *name;
    int rollNo;
    double totmarks[5];
    double obtmarks[5];
    float percentage;

public:
    student()
    {
        name = new char[1];
        name[0] = '\0';

        rollNo = 0;

        for (int i = 0; i < 5; i++)
        {
            totmarks[i] = 0;
            obtmarks[i] = 0;
        }

        percentage = 0.0;
    }

    
    student(const char *n, int r, double tm[], double om[])
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        rollNo = r;

        for (int i = 0; i < 5; i++)
        {
            totmarks[i] = tm[i];
            obtmarks[i] = om[i];
        }

        percentage = 0.0;
        CalculatePercentage();
    }

    
    student(const student &obj)
    {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);

        rollNo = obj.rollNo;

        for (int i = 0; i < 5; i++)
        {
            totmarks[i] = obj.totmarks[i];
            obtmarks[i] = obj.obtmarks[i];
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

    void SettotMarks(double tm[])
    {
        for (int i = 0; i < 5; i++)
        {
            totmarks[i] = tm[i];
        }
    }

    void SetobtMarks(double om[])
    {
        for (int i = 0; i < 5; i++)
        {
            obtmarks[i] = om[i];
        }
    }

    
    const char *GetName()
    {
        return name;
    }

    int GetRollno()
    {
        return rollNo;
    }

    double *GettotMarks()
    {
        return totmarks;
    }

    double *GetobtMarks()
    {
        return obtmarks;
    }

    float GetPercentage()
    {
        return percentage;
    }

    
    void CalculatePercentage()
    {
        double totalObt = 0;
        double totalMarks = 0;

        for (int i = 0; i < 5; i++)
        {
            totalObt += obtmarks[i];
            totalMarks += totmarks[i];
        }

        percentage = (totalObt / totalMarks) * 100;
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
        double highest = obtmarks[0];

        for (int i = 1; i < 5; i++)
        {
            if (obtmarks[i] > highest)
            {
                highest = obtmarks[i];
            }
        }

        return highest;
    }

    
    void Display()
    {
        cout << "\n===== STUDENT INFORMATION =====" << endl;

        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;

        cout << "Obtained Marks: ";
        for (int i = 0; i < 5; i++)
        {
            cout << obtmarks[i] << " ";
        }

        cout << endl;

        Grade();

        cout << "Highest Marks: " << HighestMarks() << endl;
    }
};

int main()
{
    int n;

    cout << "How many students you want to store: ";
    cin >> n;

    student *students = new student[n];

    for (int i = 0; i < n; i++)
    {
        char name[100];
        int roll;
        double obt[5];
        double total[5];

        cout << "\nEnter Data for Student " << i + 1 << endl;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter Obtained Marks of 5 Subjects:\n";

        for (int j = 0; j < 5; j++)
        {
            cout << "Subject " << j + 1 << ": ";
            cin >> obt[j];

            total[j] = 100;
        }

        students[i].SetName(name);
        students[i].SetRollno(roll);
        students[i].SetobtMarks(obt);
        students[i].SettotMarks(total);
    }

    cout << "\n\n===== ALL STUDENTS DATA =====\n";

    for (int i = 0; i < n; i++)
    {
        students[i].Display();
    }

    delete[] students;

    return 0;
}