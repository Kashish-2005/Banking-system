#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <list>
#include <string>

class Bank {
    private:
    std::list<Account> accounts;

    std::list<Account>::iterator findAccount(const std::string& accNu);    
    std::list<Account>::const_iterator findAccount(const std::string& accNum) const;
    public:
    void createAcc(const std::string& accNu , const std::string& name , double bal);
    bool deposit(const std::string& accNu , double amount);
    bool withdraw(const std::string& accNu , double amount);
    void displayAcc(const std::string& accNu) const;
    void displayAll() const;
    bool closeAcc(const std::string& accNu);
    void displayAccountTransactions(const std::string& accNu) const;
};

#endif