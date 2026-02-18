#include "SavingsAccount.h"
#include <iostream>
using namespace std;


SavingsAccount::SavingsAccount(string accNum, string name, double bal, double rate)
    : BankAccount(accNum, name, bal)  // Call parent constructor
{
    interestRate = rate;  // Initialize interest rate
}

void SavingsAccount::calculateInterest() {
    double interest = balance * (interestRate / 100);
    balance += interest;
    cout << "Interest of $" << interest << " added to account. New balance: $" << balance << endl;
}