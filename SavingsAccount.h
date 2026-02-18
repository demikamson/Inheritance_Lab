#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
    private:
        double interestRate;
    public:
        
        SavingsAccount(string accNum, string name, double bal, double rate);

        void calculateInterest();

};
    

#endif // SAVINGSACCOUNT_H