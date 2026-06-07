#include <iostream>
using namespace std;

// CHECKLIST:
// ✅ throw inside function
// ✅ try block in main
// ✅ catch with & (reference)
// ✅ e.what() to print message
// ✅ catch(...) for unknown errors

class BankAccount {
    float balance;
public:
    BankAccount(float b) {
        if(b < 0)
            throw invalid_argument("Balance cannot be negative"); // ✅ throw
        balance = b;
    }

    void deposit(float amount) {
        if(amount <= 0)
            throw invalid_argument("Amount must be positive");    // ✅ throw
        balance += amount;
    }

    void withdraw(float amount) {
        if(amount > balance)
            throw out_of_range("Insufficient funds");             // ✅ throw
        balance -= amount;
    }

    void display() { cout << "Balance: " << balance << endl; }
};

int main() {
    try {                                        // ✅ try block
        BankAccount acc(1000);
        acc.deposit(500);
        acc.withdraw(200);
        acc.display();
        acc.withdraw(9999);                      // triggers exception
    }
    catch(invalid_argument& e) {                 // ✅ catch with &
        cout << "Invalid: " << e.what() << endl; // ✅ e.what()
    }
    catch(out_of_range& e) {
        cout << "Range Error: " << e.what() << endl;
    }
    catch(...) {                                 // ✅ catch anything
        cout << "Unknown error" << endl;
    }
}