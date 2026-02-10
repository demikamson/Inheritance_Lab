#include "BankAccount.h"
#include <iostream>
#include <vector>
using namespace std;

// Default constructor - initializes account with empty values and zero balance
BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    balance = 0.0;
}

// Parameterized constructor - creates account with specified values
BankAccount::BankAccount(string accNum, string name, double bal) {
    accountNumber = accNum;
    accountHolderName = name;
    balance = bal;
}

string BankAccount::getAccountNumber() const {
    return accountNumber;
}

string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

// Setter for account holder name
void BankAccount::setAccountHolderName(string name) {
    accountHolderName = name;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid deposit amount. Amount must be greater than zero." << endl;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal of $ " << amount << " successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid withdrawal amount. Amount must be greater than zero and less than or equal to the current balance." << endl;
    }
}

// Copy Constructor
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
}

// Destructor
BankAccount::~BankAccount() {
    cout << "Account" << accountNumber << " destroyed." << endl;
}

// Assignment Operator
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this == &other) {
        return *this;
    }
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
    return *this;
}

// Overloaded += operator for deposit
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        cout << "Invalid amount! Amount must be greater than  zero." << endl;
    }
    return *this;
}

// Overloaded -= operator for withdrawal
BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    } else {
        cout << "Invalid amount! Amount must be  less than account balance" << endl;
    }
    return *this;
}

// Comparison Operators
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

// Static method to print account details
void BankAccount::printAccount(const BankAccount& account) {
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Account Holder Name: " << account.accountHolderName << endl;
    cout << "Balance: $" << account.balance << endl;
}

// Static method to create account from user input
BankAccount BankAccount::createAccountFromInput() {
    cout << "Enter account number: ";
    string accNum;
    cin >> accNum;
    cout << "Enter account holder name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Enter initial balance: $";
    double bal;
    cin >> bal;

    return BankAccount(accNum, name, bal);
}