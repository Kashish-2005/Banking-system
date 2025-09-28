#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Transaction.h"
#include <string>

class Account{
    private:
    std:: string accountNumber;
    std:: string holderName;
    double balance;
    Transaction* transactionHead;

    public:
    Account(const std::string& accNu , const std::string& name , double bal );
    ~Account();
    std::string getaccountNumber() const;
    std::string getholderName() const;
    double getbalance() const;

    void setholderName(const std::string& name);

    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
    void addTransaction(const std::string& type, double amount, const std::string& details = "");
    void displayTransactionHistory() const;
    Transaction* getTransactionHead() const { return transactionHead; }

};

#endif