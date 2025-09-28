#include "Transaction.h"

Transaction::Transaction(const std::string& t, double amt, const std::string& d, const std::string& det)
    : type(t), amount(amt), date(d), details(det), next(nullptr) {}

Transaction::~Transaction() {}

std::string Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getDate() const { return date; }
std::string Transaction::getDetails() const { return details; }
Transaction* Transaction::getNext() const { return next; }
void Transaction::setNext(Transaction* txn) { next = txn; }
