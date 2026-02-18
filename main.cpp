/*
 * Name: Demi Kamson
 * Date: February 1, 2026
 * Program: Bank Account Management System
 * Purpose: Implements a BankAccount class with basic banking operations
 *          including deposit, withdraw, and balance checking. Manages
 *          multiple accounts using a vector with a menu-driven interface.
 */

#include <iostream>
#include <vector>
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main() {
    vector<BankAccount*> accounts;
    int option;

    do {
        // Display user menu's choice
        cout << "Menu:" << endl;
        cout << "1. Create Basic Account" << endl;
        cout << "2. Create Checking Account" << endl;
        cout << "3. Create Savings Account" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << "6. Check Balance" << endl;
        cout << "7. Display all accounts" << endl;
        cout << "8. Calculate Interest (Savings)" << endl;
        cout << "9. Compare two accounts" << endl;
        cout << "10. Exit Program" << endl;
        cout << "Select an option: (1-10)" << endl;
        cin >> option;

        // Input validation for menu selection
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
            continue;
        }

        switch (option) {
            case 1: {
    // Create a basic account
    BankAccount* newAccount = new BankAccount();  // Create on heap with 'new'
    
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
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Account creation failed. Invalid Input" << endl;
        delete newAccount;  // Clean up memory
        break;
    }
    
    newAccount = new BankAccount(accNum, name, bal);
    accounts.push_back(newAccount);  // Push pointer to vector
    cout << "Basic account created successfully." << endl;
    break;
}
            case 2: {
    // Create Checking Account
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
    
    cout << "Enter transaction fee: $";
    double fee;
    cin >> fee;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Account creation failed. Invalid Input" << endl;
        break;
    }
    
    BankAccount* newAccount = new CheckingAccount(accNum, name, bal, fee);
    accounts.push_back(newAccount);
    cout << "Checking account created successfully." << endl;
    break;
}

case 3: {
    // Create Savings Account
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
    
    cout << "Enter interest rate (%): ";
    double rate;
    cin >> rate;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Account creation failed. Invalid Input" << endl;
        break;
    }
    
    BankAccount* newAccount = new SavingsAccount(accNum, name, bal, rate);
    accounts.push_back(newAccount);
    cout << "Savings account created successfully." << endl;
    break;
}

case 4: {
    // Deposit funds
    cout << "Enter account number: " << endl;
    string accNum;
    cin >> accNum;

    int index = -1;
    // Search for the account
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accNum) {  // Use -> for pointers
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found." << endl;
    } else {
        cout << "Enter deposit amount: ";
        double amount;
        cin >> amount;
        *accounts[index] += amount;  // Dereference pointer
    }
    break;
}

case 5: {
    // Withdraw funds
    cout << "Enter account number: " << endl;
    string accNum;
    cin >> accNum;

    int index = -1;
    // Search for the account
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accNum) {  // Use -> for pointers
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found." << endl;
    } else {
        cout << "Enter withdrawal amount: ";
        double amount;
        cin >> amount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            break;
        }
        accounts[index]->withdraw(amount);  // Use -> for pointers (polymorphism!)
    }
    break;
}

case 6: {
    // Check balance
    cout << "Enter account number: " << endl;
    string accNum;
    cin >> accNum;
    int index = -1;
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accNum) {  // Use -> for pointers
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found." << endl;
    } else {
        BankAccount::printAccount(*accounts[index]);  // Dereference pointer
    }
    break;
}

case 7: {
    // Display all accounts
    if (accounts.size() == 0) {
        cout << "No accounts found." << endl;
        break;
    }
    cout << "All Accounts:" << endl;
    for (int i = 0; i < accounts.size(); i++) {
        BankAccount::printAccount(*accounts[i]);  // Dereference pointer
        cout << endl;
    }
    break;
}

case 8: {
    // Calculate Interest (Savings accounts only)
    cout << "Enter account number: " << endl;
    string accNum;
    cin >> accNum;
    
    int index = -1;
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accNum) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        cout << "Account not found." << endl;
    } else {
        // Try to cast to SavingsAccount
        SavingsAccount* savingsAcc = dynamic_cast<SavingsAccount*>(accounts[index]);
        
        if (savingsAcc != nullptr) {
            savingsAcc->calculateInterest();
        } else {
            cout << "This is not a savings account. Cannot calculate interest." << endl;
        }
    }
    break;
}

case 9: {
    // Compare two accounts
    if (accounts.size() < 2) {
        cout << "Need at least 2 accounts to compare." << endl;
        break;
    }

    cout << "Enter first account number: ";
    string accNum1;
    cin >> accNum1;

    cout << "Enter second account number: ";
    string accNum2;
    cin >> accNum2;

    // Find first account
    int index1 = -1;
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accNum1) {  // Use -> for pointers
            index1 = i;
            break;
        }
    }

    // Find second account
    int index2 = -1;
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accNum2) {  // Use -> for pointers
            index2 = i;
            break;
        }
    }

    if (index1 == -1 || index2 == -1) {
        cout << "One or both accounts not found." << endl;
        break;
    }

    // Use comparison operators (dereference pointers)
    if (*accounts[index1] == *accounts[index2]) {
        cout << "Accounts are the same." << endl;
    } else {
        cout << "Accounts are different." << endl;
    }

    if (*accounts[index1] < *accounts[index2]) {
        cout << "First account has less balance." << endl;
    } else if (*accounts[index1] > *accounts[index2]) {
        cout << "First account has more balance." << endl;
    } else {
        cout << "Both accounts have equal balance." << endl;
    }

    break;
}

case 10: {
    // Clean up memory before exiting
    for (int i = 0; i < accounts.size(); i++) {
        delete accounts[i];  // Delete each pointer
    }
    cout << "Exiting program." << endl;
    break;
}
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 10); // Loop until user chooses to exit
    return 0;
}
