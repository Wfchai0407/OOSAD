#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;
    std::string userType;
    bool isLoggedIn;

public:
    User(const std::string& username, const std::string& password, const std::string& userType = "User");
    virtual ~User() = default;

    // Basic user operations
    virtual bool login(const std::string& username, const std::string& password);
    virtual void logout();
    virtual bool verifyUser() const;
    virtual bool verifyPassword(const std::string& password) const;

    // Getters
    std::string getUsername() const;
    std::string getUserType() const;
    bool getLoginStatus() const;

    // Setters
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
};

#endif // USER_H 