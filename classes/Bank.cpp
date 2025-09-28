#include "Bank.h"
#include <iostream>

std::list<Account>::iterator Bank::findAccount(const std::string& accNu){
    for(auto it = accounts.begin() ; it!=accounts.end() ; it++){
        if(it->getaccountNumber() == accNu){
            return it;
        }
    }
    return accounts.end();
}
std::list<Account>::const_iterator Bank::findAccount(const std::string& accNum) const {
    for (auto it = accounts.cbegin(); it != accounts.cend(); ++it) {
        if (it->getaccountNumber() == accNum) {
            return it;
        }
    }
    return accounts.cend();
}
void Bank::createAcc(const std::string& accNu , const std::string& name , double bal){
    accounts.emplace_back(accNu , name , bal);
    std::cout << "Account created successfully.\n";
}

bool Bank::deposit(const std::string& accNu , double amount){
    auto it = findAccount(accNu);
    if(it != accounts.end()){
        it->deposit(amount);
        return true;
    }
    std::cout << "Account not found.\n";
    return false;
}
bool Bank::withdraw(const std::string& accNu , double amount){
    auto it = findAccount(accNu);
    if(it != accounts.end()){
        it->withdraw(amount);
        return true;
    }
    std::cout << "Account not found.\n";
    return false;
}

void Bank::displayAcc(const std::string& accNu) const{
    //didnot use findaccount function bcz const present
    for(const auto& acc:accounts){
        if(acc.getaccountNumber() == accNu){
            acc.display();
            return ;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::displayAll() const{
    for(const auto& acc:accounts){
        acc.display();
        std::cout << "-------------------\n";
    }
}

bool Bank::closeAcc(const std::string& accNu){
    auto it = findAccount(accNu);
    if(it != accounts.end()){
        accounts.erase(it);
        std::cout << "Account closed successfully.\n";
        return true;
    }
    std::cout << "Account not found.\n";
    return false;
}

void Bank::displayAccountTransactions(const std::string& accNum) const {
    auto it = findAccount(accNum); // calls the const version
    if (it != accounts.cend()) {
        it->displayTransactionHistory();
    } else {
        std::cout << "Account not found.\n";
    }
}
