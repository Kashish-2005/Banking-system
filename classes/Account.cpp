#include "Account.h"
#include <iostream>
#include <ctime>

std::string getCurrentDate(){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[20];
    strftime(buf , sizeof(buf) ,"%Y-%m-%d", ltm );
    return std::string(buf);
}

Account::Account(const std::string& accNu , const std::string& name , double bal) 
        : accountNumber(accNu) , holderName(name) , balance(bal) {}

Account::~Account(){
    Transaction* curr = transactionHead;
    while(curr){
        Transaction* toDelete = curr;
        curr = curr->getNext();
        delete toDelete;
    }
}
std::string Account::getaccountNumber() const{
    return accountNumber;
}
std::string Account::getholderName() const{
    return holderName;
}
double Account::getbalance() const{
    return balance;
}

void Account::setholderName(const std::string& name){
    holderName = name;
}


void Account::deposit(double amount){
    if(amount>0){
        balance+=amount;
        addTransaction("Deposit" , amount);
        std::cout << "Deposit successful. Current balance: " << balance << std::endl;
    }
    else{
        std::cout << "Invalid deposit amount." << std::endl;
    }
}

bool Account::withdraw(double amount){
    if(balance >= amount && amount > 0){
        balance-=amount;
        addTransaction("withdraw" , amount);
        std::cout << "Withdrawal successful. Current balance: " << balance << std::endl;
        return true;
    }
    else{
        std::cout << "Insufficient balance or invalid amount." << std::endl;
        return false;
    }
}

void Account::display() const{
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Holder Name: " << holderName << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}

void Account::addTransaction(const std::string& type , double amount , const std::string& details){
    Transaction* newTxn = new Transaction(type , amount , getCurrentDate(), details);
    newTxn->setNext(transactionHead);
    transactionHead = newTxn;
}

void Account::displayTransactionHistory() const {
    if (!transactionHead) {
        std::cout << "No transactions found.\n";
        return;
    }
    std::cout << "Transaction History:\n";
    Transaction* curr = transactionHead;
    while (curr) {
        std::cout << curr->getDate() << " - " << curr->getType() << ": " << curr->getAmount();
        if (!curr->getDetails().empty())
            std::cout << " (" << curr->getDetails() << ")";
        std::cout << std::endl;
        curr = curr->getNext();
    }
}