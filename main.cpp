#include "Bank.h"
#include "Auth.h"
#include <iostream>
#include <limits>

int main() {
     Auth auth("users.txt"); // Handles user authentication
    std::string username, password;
    int preChoice;

    std::cout << "=== Welcome to the Banking System ===\n";
    // Registration/Login menu loop
    do {
        std::cout << "1. Login\n2. Register\n0. Exit\nEnter your choice: ";
        std::cin >> preChoice;
        if (preChoice == 2) {
            // Registration flow
            std::cout << "Choose a username: ";
            std::cin >> username;
            std::cout << "Choose a password: ";
            std::cin >> password;
            if (auth.registerUser(username, password)) {
                std::cout << "Registration successful! You can now log in.\n";
            } else {
                std::cout << "Username already exists. Try another.\n";
            }
        }
    } while (preChoice == 2);

    if (preChoice == 0) {
        std::cout << "Exiting...\n";
        return 0;
    }

    // Login flow
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (!auth.login(username, password)) {
        std::cout << "Invalid credentials. Exiting...\n";
        return 1;
    }

    std::cout << "Login successful!\n";
    
    Bank bank;
    int choice;
    std::string accNum, name;
    double amount;

    do {
        std::cout << "\n--- Bank Menu ---\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Display Account\n";
        std::cout << "5. Display All Accounts\n";
        std::cout << "6. Close Account\n";
        std::cout << "7. View Transaction History\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear input buffer in case of invalid input
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
        }

        switch(choice) {
            case 1:
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                std::cout << "Enter account holder name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter initial balance: ";
                std::cin >> amount;
                bank.createAcc(accNum, name, amount);
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                bank.deposit(accNum, amount);
                break;
            case 3:
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                bank.withdraw(accNum, amount);
                break;
            case 4:
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                bank.displayAcc(accNum);
                break;
            case 5:
                bank.displayAll();
                break;
            case 6:
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                bank.closeAcc(accNum);
                break;
            case 7:
                std::cout << "Enter account number: ";
                std::cin >> accNum;
                bank.displayAccountTransactions(accNum);
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
