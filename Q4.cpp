#include <iostream>
using namespace std;
class Student{
    public:
        string name;
        int roll_no;
        float CGPA;




};

void print(Student S){
    cout<<S.name<<"\n";
    cout<<S.roll_no<<"\n";
    cout<<S.CGPA<<"\n";
}


int main(){


    Student S1; // this is pass by Value;
    S1.name = "Himanu";
    S1.roll_no = 1;
    S1.CGPA = 4.00;
    
    Student S2; // this is pass by Value;
    S2.name = "Haseeb";
    S2.roll_no = 2;
    S2.CGPA = 3.7;

    print(S1);
    print(S2);

    return 0;
}