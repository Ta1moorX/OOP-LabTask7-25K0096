#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

    Account(int num, double bal, string name, string type) {
        accountNumber = num;
        balance = bal;
        accountHolderName = name;
        accountType = type;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "No interest for base account." << endl;
    }

    virtual void printStatement() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder: " << accountHolderName << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder: " << accountHolderName << endl;
        cout << "Type: " << accountType << endl;
    }
};

class SavingsAccount : public Account {
public:
    double interestRate;
    double minimumBalance;

    SavingsAccount(int num, double bal, string name, double rate, double minBal)
        : Account(num, bal, name, "Savings") {
        interestRate = rate;
        minimumBalance = minBal;
    }

    void withdraw(double amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Cannot withdraw! Minimum balance of " << minimumBalance << " must be maintained." << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest Added: " << interest << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

class CheckingAccount : public Account {
public:
    double overdraftLimit;

    CheckingAccount(int num, double bal, string name, double overdraft)
        : Account(num, bal, name, "Checking") {
        overdraftLimit = overdraft;
    }

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Exceeds overdraft limit!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void calculateInterest() override {
        cout << "No interest for Checking Account." << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public Account {
public:
    string maturityDate;
    double fixedInterestRate;

    FixedDepositAccount(int num, double bal, string name, string matDate, double rate)
        : Account(num, bal, name, "Fixed Deposit") {
        maturityDate = matDate;
        fixedInterestRate = rate;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity date: " << maturityDate << endl;
    }

    void calculateInterest() override {
        double interest = balance * fixedInterestRate / 100;
        balance += interest;
        cout << "Fixed Interest Added: " << interest << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
    }
};

int main() {
    SavingsAccount s(1001, 5000, "Alice", 5.0, 1000);
    CheckingAccount c(1002, 3000, "Bob", 500);
    FixedDepositAccount f(1003, 10000, "Charlie", "2026-12-31", 8.0);

    cout << "====== Savings Account ======" << endl;
    s.printStatement();
    s.deposit(2000);
    s.withdraw(500);
    s.withdraw(5600);
    s.calculateInterest();
    cout << endl;

    cout << "====== Checking Account ======" << endl;
    c.printStatement();
    c.deposit(1000);
    c.withdraw(3800);
    c.withdraw(1000);
    c.calculateInterest();
    cout << endl;

    cout << "====== Fixed Deposit Account ======" << endl;
    f.printStatement();
    f.withdraw(1000);
    f.calculateInterest();
    cout << endl;

    cout << "====== Polymorphism Demo ======" << endl;
    Account* accounts[3];
    accounts[0] = &s;
    accounts[1] = &c;
    accounts[2] = &f;

    for (int i = 0; i < 3; i++) {
        accounts[i]->getAccountInfo();
        accounts[i]->calculateInterest();
        cout << endl;
    }

    return 0;
}
