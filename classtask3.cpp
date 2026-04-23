#include <iostream>
using namespace std;

class BankAccount {
protected:
    int Acc_ID;
    double Balance;

public:
    BankAccount(int id = 0, double bal = 0.0) {
        Acc_ID = id;
        Balance = bal;
    }

    virtual double calculate_interest() = 0;

    BankAccount& operator+=(double amount) {
        Balance += amount;
        return *this;
    }

    BankAccount& operator-=(double amount) {
        if (amount <= Balance)
            Balance -= amount;
        else
            cout << "Insufficient balance\n";
        return *this;
    }

    bool operator>(const BankAccount& other) {
        return Balance > other.Balance;
    }

    bool operator<(const BankAccount& other) {
        return Balance < other.Balance;
    }

    bool operator==(const BankAccount& other) {
        return Balance == other.Balance;
    }


    virtual ~BankAccount() {}
};

// Derived class
class Saving_Acc : public BankAccount {
    double interest_rate;

public:
    Saving_Acc(int id, double bal, double rate)
        : BankAccount(id, bal) {
        interest_rate = rate;
    }

    double calculate_interest() override {
        return Balance * interest_rate;
    }
};

int main() {
    // Create accounts
    Saving_Acc acc1(101, 1000, 0.05);
    Saving_Acc acc2(102, 1500, 0.04);

    // Interest calculation 
    cout << "\nInterest of acc1: " << acc1.calculate_interest() << endl;
    cout << "Interest of acc2: " << acc2.calculate_interest() << endl;

    // Equality check
    if (acc1 == acc2)
        cout << "Balances are equal\n";
    else
        cout << "Balances are not equal\n";

    return 0;
}