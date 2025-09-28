#include "Auth.h"
#include <fstream>
#include <sstream>

Auth::Auth(const std::string& filename) : filename(filename){
    loadUsers(filename);
}
// Loads users from the file into the users vector
void Auth::loadUsers(const std::string& filename){
    users.clear();
    std::ifstream infile(filename);
    std::string line;
    while(std::getline(infile , line)){
        std::istringstream iss(line);
        std::string uname , pwd;
        if(iss >> uname >> pwd){
            users.emplace_back(uname , pwd);
        }
    }
}

// Returns true if username/password match a user
bool Auth::login(const std::string& username , const std::string& password) const{
    for(const auto& user:users){
        if(user.getUsername() == username && user.checkPassword(password)){
            return true;
        }
    }
    return false;
}

// Registers a new user if username is not taken, appends to file
bool Auth::registerUser(const std::string& username , const std::string& password){
    for(const auto& user:users){
        if(user.getUsername() == username){
            return false;
        }
    }

    //add to memory
    users.emplace_back(username , password);
    //append to file
    std::ofstream outfile(filename , std::ios::app);
    if(outfile.is_open()){
        outfile << username << " " << password << "\n";
        outfile.close();
        return true;
    }
    return false;
}