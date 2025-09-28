#include "User.h"

// Constructor to set username and password
User::User(const std::string& uname, const std::string& pwd)
    : username(uname), password(pwd) {}

// Returns the username
std::string User::getUsername() const {
    return username;
}

// Checks if the given password matches the user's password
bool User::checkPassword(const std::string& pwd) const {
    return password == pwd;
}
