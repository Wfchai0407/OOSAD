#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>
#include <string>

class Admin : public User {
private:
    std::string adminId;
    std::vector<std::string> supportTickets;

public:
    Admin(const std::string& username, const std::string& password);
    ~Admin();

    // F13: Edit Price
    void editPrice(const std::string& routeId, double newPrice);
    
    // F14: Manage Routes
    void addRoute(const std::string& departure, const std::string& arrival, double price);
    void removeRoute(const std::string& routeId);
    void modifyRoute(const std::string& routeId, const std::string& departure, const std::string& arrival);
    
    // F15: Customer Support
    void respondToSupport(const std::string& ticketId, const std::string& response);
    void viewSupportTickets() const;
    
    // Additional functionality
    std::string getAdminId() const;
    void addSupportTicket(const std::string& ticket);
    void generateReport() const;
};

#endif // ADMIN_H 