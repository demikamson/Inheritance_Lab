#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;



class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
protected:
    double balance;

public:
    // Constructors
    BankAccount();
    BankAccount(string accNum, string name, double bal);
    BankAccount(const BankAccount& other); // Copy Constructor
    virtual ~BankAccount(); // Destructor

    // Accessors (Getters)
    string getAccountNumber() const;
    string getAccountHolderName() const;
    double getBalance() const;

    // Mutators (Setters)
    void setAccountHolderName(string name);
    void deposit(double amount);
     virtual void withdraw(double amount);

    // Operator Overloads
    BankAccount& operator=(const BankAccount& other);
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // Static Helper Methods
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};
#endif // BANKACCOUNT_H