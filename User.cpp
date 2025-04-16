#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& userType)
    : username(username), password(password), userType(userType), isLoggedIn(false) {}

bool User::login(const std::string& username, const std::string& password) {
    if (this->username == username && this->password == password) {
        isLoggedIn = true;
        return true;
    }
    return false;
}

void User::logout() {
    isLoggedIn = false;
}

bool User::verifyUser() const {
    return !username.empty() && !password.empty();
}

bool User::verifyPassword(const std::string& password) const {
    return this->password == password;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getUserType() const {
    return userType;
}

bool User::getLoginStatus() const {
    return isLoggedIn;
}

void User::setUsername(const std::string& username) {
    this->username = username;
}

void User::setPassword(const std::string& password) {
    this->password = password;
} 