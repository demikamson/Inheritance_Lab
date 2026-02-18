#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount(string accNum, string name, double bal, double fee)
    : BankAccount(accNum, name, bal)  // Call parent constructor
{
    transactionFee = fee;  // Initialize transaction fee
}
void CheckingAccount::withdraw(double amount) {
    double total=amount+transactionFee;
    if (total >0 && total <= balance) {
        balance-= total;
        cout << "Withdrawal of $" << amount << " with transaction fee of $" << transactionFee << " fee successful. New balance: $" << balance << endl;
    }else{
        cout << "Invalid withdrawal amount. Amount must be greater than zero and less than or equal to the current balance." << endl;
    }
        
    }



