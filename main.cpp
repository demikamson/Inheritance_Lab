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
using namespace std;

int main() {
    vector<BankAccount> accounts;
    int option;

    do {
        // Display user menu's choice
        cout << "Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Display all accounts" << endl;
        cout << "6. Compare two accounts" << endl;
        cout << "7. Exit Program" << endl;

        cout << "Select an option: (1-7)" << endl;
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
                // Create a new account
                BankAccount newAccount = BankAccount::createAccountFromInput();
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Account creation failed. Invalid Input" << endl;
                    break;
                }

                accounts.push_back(newAccount);
                cout << "Account created successfully." << endl;
                break;
            }

            case 2: {
                // Deposit funds
                cout << "Enter account number: " << endl;
                string accNum;
                cin >> accNum;

                int index = -1;
                // Search for the account
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
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
                    accounts[index] += amount; // Use overloaded += operator
                }
                break;
            }

            case 3: {
                // Withdraw funds
                cout << "Enter account number: " << endl;
                string accNum;
                cin >> accNum;

                int index = -1;
                // Search for the account
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
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
                    accounts[index] -= amount; // Use overloaded -= operator
                }
                break;
            }

            case 4: {
                // Check balance
                cout << "Enter account number: " << endl;
                string accNum;
                cin >> accNum;
                int index = -1;
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    cout << "Account not found." << endl;
                } else {
                    BankAccount::printAccount(accounts[index]);
                }
                break;
            }

            case 5: {
                // Display all accounts
                if (accounts.size() == 0) {
                    cout << "No accounts found." << endl;
                    break;
                }
                cout << "All Accounts:" << endl;
                for (int i = 0; i < accounts.size(); i++) {
                    BankAccount::printAccount(accounts[i]);
                    cout << endl;
                }
                break;
            }

            case 6: {
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
                    if (accounts[i].getAccountNumber() == accNum1) {
                        index1 = i;
                        break;
                    }
                }

                // Find second account
                int index2 = -1;
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccountNumber() == accNum2) {
                        index2 = i;
                        break;
                    }
                }

                if (index1 == -1 || index2 == -1) {
                    cout << "One or both accounts not found." << endl;
                    break;
                }

                // Use comparison operators
                if (accounts[index1] == accounts[index2]) {
                    cout << "Accounts are the same." << endl;
                } else {
                    cout << "Accounts are different." << endl;
                }

                if (accounts[index1] < accounts[index2]) {
                    cout << "First account has less balance." << endl;
                } else if (accounts[index1] > accounts[index2]) {
                    cout << "First account has more balance." << endl;
                } else {
                    cout << "Both accounts have equal balance." << endl;
                }

                break;
            }

            case 7: {
                cout << "Exiting program." << endl;
                break;
            }

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 7); // Loop until user chooses to exit
    return 0;
}
