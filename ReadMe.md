# BankAccount Class

A C++ class for managing bank accounts with basic banking operations.

## Data Dictionary

| Attribute           | Data Type     | Description                           |
|---------------------|---------------|---------------------------------------|
| `accountNumber`     | `std::string` | Unique identifier for the account     |
| `accountHolderName` | `std::string` | Name of the account holder            |
| `balance`           | `double`      | Current account balance in dollars    |

## Methods List

| Method Signature                                      | Return Type   | Description                                    |
|-------------------------------------------------------|---------------|------------------------------------------------|
| `BankAccount()`                                       | (Constructor) | Default constructor, initializes empty account |
| `BankAccount(string accNum, string name, double bal)` | (Constructor) | Parameterized constructor with initial values  |
| `getAccountNumber() const`                            | `string`      | Returns the account number                     |
| `getAccountHolderName() const`                        | `string`      | Returns the account holder's name              |
| `getBalance() const`                                  | `double`      | Returns the current balance                    |
| `setAccountHolderName(string name)`                   | `void`        | Updates the account holder's name              |
| `deposit(double amount)`                              | `void`        | Adds money to the account                      |
| `withdraw(double amount)`                             | `void`        | Removes money from the account                 |