#ifndef AUTH_H
#define AUTH_H

#include "User.h"
#include <vector>
#include <string>

class Auth{
    private:
    std::vector<User> users;
    std::string filename;
    void loadUsers(const std::string& filename); // Loads users from file
public:
    Auth(const std::string& filename = "users.txt");
    bool login(const std::string& username, const std::string& password) const;
    bool registerUser(const std::string& username, const std::string& password);
};

#endif