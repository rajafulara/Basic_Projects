#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class to represent a bank account
class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;
public:
    // Constructor
    BankAccount(string accNumber, string ownerName, double balance = 0.0) {
        this->accountNumber = accNumber;
        this->ownerName = ownerName;
        this->balance = balance;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Current balance: " << balance << endl;
        } else {
            cout << "Invalid amount for deposit.\n";
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount for withdrawal.\n";
        }
    }

    // Function to check the current balance
    double getBalance() const {
        return balance;
    }

    // Function to display account details
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

// Function to find account by account number
BankAccount* findAccount(vector<BankAccount>& accounts, string accNumber) {
    auto it = find_if(accounts.begin(), accounts.end(), [&](const BankAccount& acc) {
        return acc.getAccountNumber() == accNumber;
    });

    if (it != accounts.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}

int main() {
    vector<BankAccount> accounts;

    int choice;
    string accNumber;
    string ownerName;
    double amount;

    do {
        // Menu
        cout << "\nBanking System Menu\n";
        cout << "1. Create an Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Owner Name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, ownerName);
                accounts.push_back(BankAccount(accNumber, ownerName));
                cout << "Account created successfully.\n";
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                {
                    BankAccount* acc = findAccount(accounts, accNumber);
                    if (acc) {
                        acc->deposit(amount);
                    } else {
                        cout << "Account not found.\n";
                    }
                }
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                {
                    BankAccount* acc = findAccount(accounts, accNumber);
                    if (acc) {
                        acc->withdraw(amount);
                    } else {
                        cout << "Account not found.\n";
                    }
                }
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                {
                    BankAccount* acc = findAccount(accounts, accNumber);
                    if (acc) {
                        acc->display();
                    } else {
                        cout << "Account not found.\n";
                    }
                }
                break;
            case 5:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}
