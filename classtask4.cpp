#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

    // Helper to normalize time
    void normalize() {
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
        if (minutes < 0) {
            int borrow = (abs(minutes) + 59) / 60;
            hours -= borrow;
            minutes += borrow * 60;
        }
    }

public:
    // Constructor
    Time(int h = 0, int m = 0) {
        hours = h;
        minutes = m;
        normalize();
    }

    // + operator
    Time operator+(const Time& t) {
        Time temp;
        temp.hours = this->hours + t.hours;
        temp.minutes = this->minutes + t.minutes;
        temp.normalize();
        return temp;
    }

    // - operator
    Time operator-(const Time& t) {
        Time temp;
        temp.hours = this->hours - t.hours;
        temp.minutes = this->minutes - t.minutes;
        temp.normalize();
        return temp;
    }

    // > operator
    bool operator>(const Time& t) {
        if (hours > t.hours) return true;
        if (hours == t.hours && minutes > t.minutes) return true;
        return false;
    }

    // << operator (friend)
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << setw(2) << setfill('0') << t.hours << ":"
            << setw(2) << setfill('0') << t.minutes;
        return out;
    }
};

int main() {
    Time t1(2, 50);
    Time t2(1, 30);

    Time sum = t1 + t2;
    Time diff = t1 - t2;

    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    if (t1 > t2)
        cout << "Time 1 is greater than Time 2" << endl;
    else
        cout << "Time 1 is not greater than Time 2" << endl;

    return 0;
}