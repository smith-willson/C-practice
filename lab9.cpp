// #include <iostream>
// using namespace std;

// class Node {
// public:
//     string data;
//     int priority;

//     Node(string d = "", int p = 0) {
//         data = d;
//         priority = p;
//     }
// };

// class Priority_Queue {
//     Node arr[5];   // bounded queue
//     int size;

// public:
//     Priority_Queue() {
//         size = 0;
//     }

//     void Enqueue(string d, int p) {
//         if (size == 5) {
//             cout << "Queue Full\n";
//             return;
//         }

//         int i;
//         for (i = size - 1; i >= 0; i--) {
//             if (arr[i].priority < p) {
//                 arr[i + 1] = arr[i];
//             } else {
//                 break;
//             }
//         }

//         arr[i + 1] = Node(d, p);
//         size++;
//     }

//     void Dequeue() {
//         if (size == 0) {
//             cout << "Queue Empty\n";
//             return;
//         }

//         cout << "Removed: " << arr[0].data 
//              << " (Priority: " << arr[0].priority << ")\n";

//         for (int i = 0; i < size - 1; i++) {
//             arr[i] = arr[i + 1];
//         }

//         size--;
//     }
// };

// #include <iostream>
// using namespace std;
// class Date {
// public:
//     int day, month, year;

//     Date(int d=0, int m=0, int y=0) {
//         day = d;
//         month = m;
//         year = y;
//     }

//     void input() {
//         cin >> day >> month >> year;
//     }

//     void display() {
//         cout << day << "/" << month << "/" << year;
//     }
// };

// class Salary {
// public:
//     float gross, deduction, net;

//     Salary(float g=0, float d=0) {
//         gross = g;
//         deduction = d;
//         net = gross - deduction;
//     }

//     void input() {
//         cin >> gross >> deduction;
//         net = gross - deduction;
//     }

//     void display() {
//         cout << "Gross: " << gross 
//              << " Deduction: " << deduction 
//              << " Net: " << net << endl;
//     }
// };

// class Employee {
//     int empNo;
//     char* name;
//     Date doj;
//     Salary sal;

// public:
//     Employee() {
//         name = new char[50];
//     }

//     ~Employee() {
//         delete[] name;
//     }

//     int getEmpNo() {
//         return empNo;
//     }

//     void input() {
//         cout << "Enter Emp No: ";
//         cin >> empNo;

//         cout << "Enter Name: ";
//         cin >> name;

//         cout << "Enter Date (d m y): ";
//         doj.input();

//         cout << "Enter Salary (gross deduction): ";
//         sal.input();
//     }

//     void display() {
//         cout << "\nEmp No: " << empNo;
//         cout << "\nName: " << name;
//         cout << "\nDate of Joining: ";
//         doj.display();
//         cout << endl;
//         sal.display();
//     }
// };

// #include <iostream>
// using namespace std;

// class Database {
//     Employee* emp;
//     int size;

// public:
//     Database() {
//         emp = nullptr;
//         size = 0;
//     }

//     void Add() {
//         Employee* temp = new Employee[size + 1];

//         for (int i = 0; i < size; i++) {
//             temp[i] = emp[i];
//         }

//         temp[size].input();

//         delete[] emp;
//         emp = temp;
//         size++;
//     }

//     void Search(int id) {
//         for (int i = 0; i < size; i++) {
//             if (emp[i].getEmpNo() == id) {
//                 emp[i].display();
//                 return;
//             }
//         }
//         cout << "Not Found\n";
//     }

//     void Delete(int id) {
//         int index = -1;

//         for (int i = 0; i < size; i++) {
//             if (emp[i].getEmpNo() == id) {
//                 index = i;
//                 break;
//             }
//         }

//         if (index == -1) {
//             cout << "Not Found\n";
//             return;
//         }

//         Employee* temp = new Employee[size - 1];

//         for (int i = 0, j = 0; i < size; i++) {
//             if (i != index) {
//                 temp[j++] = emp[i];
//             }
//         }

//         delete[] emp;
//         emp = temp;
//         size--;

//         cout << "Deleted Successfully\n";
//     }

//     void DisplayAll() {
//         for (int i = 0; i < size; i++) {
//             emp[i].display();
//         }
//     }
// };


