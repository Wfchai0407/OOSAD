#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <utility>
#include "User.h"
#include "Passenger.h"
#include "BusOperator.h"
#include "Admin.h"
#include "Bus.h"
#include "Ticket.h"

class BusTicketSystem {
private:
    std::vector<User*> users;
    std::vector<std::pair<std::string, std::string>> supportResponses; // userId, message
    std::map<std::string, double> routes;  // routeId, price
    std::map<std::string, int> routePrices;  // routeId, availableSeats
    bool isLoggedIn;
    User* currentUser;

    // Helper functions
    std::string generateId(const std::string& prefix) const;
    bool validateCredentials(const std::string& username, const std::string& password) const;

public:
    BusTicketSystem();
    ~BusTicketSystem();

    // User Management
    bool registerUser(const std::string& username, const std::string& password, const std::string& userType);
    bool login(const std::string& username, const std::string& password);
    void logout();
    std::string getUserType(const std::string& username) const;
    User* getCurrentUser() const;

    // Bus Management
    void displayAvailableBuses() const;
    void displaySeatAvailability(const std::string& routeId) const;
    void updateBusSchedule(const std::string& routeId, const std::string& schedule);
    void addNewRoute(const std::string& routeId, double price);
    void removeRoute(const std::string& routeId);

    // Route Management
    std::string getRouteId(const std::string& source, const std::string& destination) const;
    double getRoutePrice(const std::string& routeId) const;
    bool isRouteAvailable(const std::string& routeId) const;

    // Ticket Management
    bool bookTicket(const std::string& routeId, const std::string& userId);
    void cancelTicket(const std::string& ticketId);
    std::vector<Ticket*> getUserBookings(const std::string& userId) const;
    void updateTicketStatus(const std::string& ticketId, const std::string& status);

    // Support System
    void submitSupportTicket(const std::string& userId, const std::string& message);
    void respondToSupportTicket(const std::string& userId, const std::string& response);
    std::vector<std::pair<std::string, std::string>> viewSupportTickets() const;

    // System Statistics
    int getTotalBookings() const;
    double getTotalRevenue() const;
    int getActiveUsers() const;
}; 