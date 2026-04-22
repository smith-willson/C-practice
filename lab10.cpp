// #include <iostream>
// #include <stdexcept>
// using namespace std;

// class Timer {
//     int hour, minute, second;

// public:
//     Timer() {
//         hour = minute = second = 0;
//     }

//     void Tick() {
//         second++;

//         if (second == 60) {
//             second = 0;
//             minute++;
//         }

//         if (minute == 60) {
//             minute = 0;
//             hour++;
//         }

//         if (hour == 24) {
//             throw overflow_error("Timer overflow");
//         }
//     }

//     void display() {
//         cout << hour << ":" << minute << ":" << second << endl;
//     }
// };

// int main() {
//     Timer t;

//     try {
//         while (true) {
//             t.Tick();
//             t.display();
//         }
//     }
//     catch (overflow_error e) {
//         cout << e.what();
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class TimerException {
// public:
//     const char* what() {
//         return "Timer Overflow Exception";
//     }
// };

// class Timer {
//     int hour, minute, second;

// public:
//     Timer() {
//         hour = minute = second = 0;
//     }

//     void Tick() {
//         second++;

//         if (second == 60) {
//             second = 0;
//             minute++;
//         }

//         if (minute == 60) {
//             minute = 0;
//             hour++;
//         }

//         if (hour == 24) {
//             throw TimerException();
//         }
//     }

//     void display() {
//         cout << hour << ":" << minute << ":" << second << endl;
//     }
// };

// int main() {
//     Timer t;

//     try {
//         while (true) {
//             t.Tick();
//             t.display();
//         }
//     }
//     catch (TimerException e) {
//         cout << e.what();
//     }

//     return 0;
// }



// #include <iostream>
// using namespace std;

// class StackException {
// public:
//     const char* what() {
//         return "Stack Error";
//     }
// };

// class Stack {
//     int arr[5];
//     int top;

// public:
//     Stack() {
//         top = -1;
//     }

//     void Push(int val) {
//         if (top == 4) {
//             throw StackException();
//         }
//         arr[++top] = val;
//     }

//     void Pop() {
//         if (top == -1) {
//             throw StackException();
//         }
//         cout << "Popped: " << arr[top--] << endl;
//     }
// };

// int main() {
//     Stack s;

//     try {
//         s.Push(10);
//         s.Push(20);
//         s.Push(30);
//         s.Push(40);
//         s.Push(50);
//         s.Push(60); // overflow
//     }
//     catch (StackException e) {
//         cout << e.what() << endl;
//     }

//     try {
//         s.Pop();
//         s.Pop();
//         s.Pop();
//         s.Pop();
//         s.Pop();
//         s.Pop(); // underflow
//     }
//     catch (StackException e) {
//         cout << e.what();
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

class DateException {
    string msg;

public:
    DateException(string m) {
        msg = m;
    }

    string what() {
        return msg;
    }
};

class Date {
    int d, m, y;

public:
    void SetDate() {
        cout << "Enter date (dd mm yyyy): ";
        cin >> d >> m >> y;

        if (m < 1 || m > 12) {
            throw DateException("Invalid Month\n");
        }

        if (d < 1 || d > 31) {
            throw DateException("Invalid Day\n");
        }

        if (y < 0) {
            throw DateException("Invalid Year\n");
        }

        cout << "Valid Date: " << d << "/" << m << "/" << y << endl;
    }
};

int main() {
    Date date;

    try {
        date.SetDate();
    }
    catch (DateException e) {
        cout << e.what();
    }

    return 0;
}