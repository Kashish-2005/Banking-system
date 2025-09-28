#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string type;      // "Deposit", "Withdraw", "Transfer"
    double amount;
    std::string date;
    std::string details;   // Optional: recipient for transfer, etc.
    Transaction* next;     // Pointer to next transaction node

public:
    Transaction(const std::string& t, double amt, const std::string& d, const std::string& det = "");
    ~Transaction();

    // Getters
    std::string getType() const;
    double getAmount() const;
    std::string getDate() const;
    std::string getDetails() const;
    Transaction* getNext() const;

    // Setter for next pointer
    void setNext(Transaction* txn);
};

#endif
