#include <iostream> // Required for input/output operations
#include <string>   // Required for using string data type
using namespace std;

class BankAccount {
private:
    string accountHolderName; // To store the name of the account holder
    string accountNumber;     // To store the account number
    float balance;            // To store the current balance of the account
    int pin;                  // To store the PIN for account security

public:
    // Constructor to initialize account details
    BankAccount(string name, string accNumber, float initialBalance, int accPin) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
        pin = accPin;
    }

    // Function to display account details
    void displayAccountDetails() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Holder: " << accountHolderName << endl; // Print account holder's name
        cout << "Account Number: " << accountNumber << endl;     // Print account number
        cout << "Balance: $" << balance << endl;                // Print current balance
    }

    // Function to deposit money into the account
    void deposit(float amount) {
        if (amount > 0) { // Check if the deposit amount is valid
            balance += amount; // Add the amount to the balance
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl; // Display error for invalid amount
        }
    }

    // Function to withdraw money from the account
    void withdraw(float amount, int enteredPin) {
        if (enteredPin == pin) { // Verify the entered PIN
            if (amount > 0 && amount <= balance) { // Check if the amount is valid and sufficient
                balance -= amount; // Deduct the amount from the balance
                cout << "Withdrawal successful! Remaining balance: $" << balance << endl;
            } else {
                cout << "Insufficient balance or invalid amount!" << endl;
            }
        } else {
            cout << "Incorrect PIN!" << endl; // Display error for incorrect PIN
        }
    }

    // Function to check balance securely
    void checkBalance(int enteredPin) {
        if (enteredPin == pin) { // Verify the entered PIN
            cout << "Your current balance is: $" << balance << endl; // Display the balance
        } else {
            cout << "Incorrect PIN!" << endl; // Display error for incorrect PIN
        }
    }

    // Function to change ATM PIN securely
    void changePin(int oldPin, int newPin) {
        if (oldPin == pin) { // Verify the old PIN
            pin = newPin; // Update to the new PIN
            cout << "PIN changed successfully!" << endl;
        } else {
            cout << "Incorrect old PIN!" << endl; // Display error for incorrect old PIN
        }
    }

    // Function to check if the account number matches
    bool matchAccount(string accNumber) {
        return accountNumber == accNumber; // Return true if the account number matches
    }
};

int main() {
    // Create an array of 3 bank accounts with predefined data
    BankAccount accounts[3] = {
        BankAccount("Asif ALi", "1001", 1000.0, 1234),   // Account 1
        BankAccount("Moazam Ali", "1002", 1500.0, 5678), // Account 2
        BankAccount("Kashif Ali", "1003", 2000.0, 4321) // Account 3
    };

    string enteredAccountNumber; // To store the account number entered by the user1
    int choice, pin, newPin;     // Variables for menu choice, PIN, and new PIN
    float amount;                // Variable to store deposit/withdrawal amount

    // Greet the user and prompt for account number
    cout << "\n--- Welcome to the Bank Management System ---\n";
    cout << "Enter your account number: ";
    cin >> enteredAccountNumber;

    // Find the account corresponding to the entered account number
    BankAccount *currentAccount = nullptr; // Pointer to hold the current account
    for (int i = 0; i < 3; i++) {
        if (accounts[i].matchAccount(enteredAccountNumber)) { // Check if account number matches
            currentAccount = &accounts[i]; // Point to the matched account
            break;
        }
    }

    if (currentAccount == nullptr) { // If no matching account is found
        cout << "Account not found! Exiting...\n";
        return 0; // Exit the program
    }

    do {
        // Display menu for user actions
        cout << "\n--- Menu ---\n";
        cout << "1. Display Account Details\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Change ATM PIN\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            currentAccount->displayAccountDetails(); // Display account details
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            currentAccount->deposit(amount); // Call deposit function
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            cout << "Enter your PIN: ";
            cin >> pin;
            currentAccount->withdraw(amount, pin); // Call withdraw function
            break;
        case 4:
            cout << "Enter your PIN: ";
            cin >> pin;
            currentAccount->checkBalance(pin); // Call balance check function
            break;
        case 5:
            cout << "Enter your old PIN: ";
            cin >> pin;
            cout << "Enter your new PIN: ";
            cin >> newPin;
            currentAccount->changePin(pin, newPin); // Call PIN change function
            break;
        case 6:
            cout << "Thank you for using the system. Goodbye!\n"; // Exit message
            break;
        default:
            cout << "Invalid choice! Please try again.\n"; // Error for invalid choice
        }
    } while (choice != 6); // Repeat until the user chooses to exit
	return 0;
}
