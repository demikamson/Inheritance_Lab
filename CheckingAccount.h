#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
    private:
        double transactionFee;
    public:
        CheckingAccount(string accNum, string name, double bal, double fee);


         virtual void withdraw(double amount) override;

};











        #endif