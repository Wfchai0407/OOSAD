#include "BusTicketSystem.h"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

BusTicketSystem::BusTicketSystem() : isLoggedIn(false), currentUser(nullptr) {}

BusTicketSystem::~BusTicketSystem() {
    for (auto user : users) {
        delete user;
    }
    users.clear();
}

std::string BusTicketSystem::generateId(const std::string& prefix) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1000, 9999);
    
    std::stringstream ss;
    ss << prefix << std::setfill('0') << std::setw(4) << dis(gen);
    return ss.str();
}

bool BusTicketSystem::validateCredentials(const std::string& username, const std::string& password) const {
    auto it = std::find_if(users.begin(), users.end(),
        [&username, &password](const User* user) {
            return user->getUsername() == username && user->verifyPassword(password);
        });
    return it != users.end();
}

bool BusTicketSystem::registerUser(const std::string& username, const std::string& password, const std::string& userType) {
    // Check if username already exists
    auto it = std::find_if(users.begin(), users.end(),
        [&username](const User* user) { return user->getUsername() == username; });
    
    if (it != users.end()) {
        return false; // Username already exists
    }

    // Create new user based on type
    User* newUser = nullptr;
    if (userType == "admin") {
        newUser = new Admin(username, password);
    } else if (userType == "passenger") {
        newUser = new Passenger(username, password);
    } else {
        return false; // Invalid user type
    }

    users.push_back(newUser);
    return true;
}

bool BusTicketSystem::login(const std::string& username, const std::string& password) {
    auto it = std::find_if(users.begin(), users.end(),
        [&username, &password](const User* user) {
            return user->getUsername() == username && user->verifyPassword(password);
        });

    if (it != users.end()) {
        currentUser = *it;
        isLoggedIn = true;
        return true;
    }
    return false;
}

void BusTicketSystem::logout() {
    currentUser = nullptr;
    isLoggedIn = false;
}

std::string BusTicketSystem::getUserType(const std::string& username) const {
    auto it = std::find_if(users.begin(), users.end(),
        [&username](const User* user) { return user->getUsername() == username; });
    
    if (it != users.end()) {
        return (*it)->getUserType();
    }
    return "";
}

User* BusTicketSystem::getCurrentUser() const {
    return currentUser;
}

void BusTicketSystem::displayAvailableBuses() const {
    for (const auto& route : routes) {
        std::cout << "Route ID: " << route.first
                  << ", Price: $" << route.second
                  << ", Available Seats: " << routePrices.at(route.first) << std::endl;
    }
}

void BusTicketSystem::displaySeatAvailability(const std::string& routeId) const {
    if (routes.find(routeId) != routes.end()) {
        std::cout << "Available seats for route " << routeId << ": "
                  << routePrices.at(routeId) << std::endl;
    }
}

void BusTicketSystem::updateBusSchedule(const std::string& routeId, const std::string& schedule) {
    // Implementation can be added based on requirements
}

void BusTicketSystem::addNewRoute(const std::string& routeId, double price) {
    routes[routeId] = price;
    routePrices[routeId] = 50; // Default 50 seats
}

void BusTicketSystem::removeRoute(const std::string& routeId) {
    routes.erase(routeId);
    routePrices.erase(routeId);
}

std::string BusTicketSystem::getRouteId(const std::string& source, const std::string& destination) const {
    // Simple implementation - can be enhanced based on requirements
    return source + "_to_" + destination;
}

double BusTicketSystem::getRoutePrice(const std::string& routeId) const {
    auto it = routes.find(routeId);
    return it != routes.end() ? it->second : 0.0;
}

bool BusTicketSystem::isRouteAvailable(const std::string& routeId) const {
    return routes.find(routeId) != routes.end() && routePrices.at(routeId) > 0;
}

bool BusTicketSystem::bookTicket(const std::string& routeId, const std::string& userId) {
    if (!isRouteAvailable(routeId)) {
        return false;
    }
    
    routePrices[routeId]--;
    return true;
}

void BusTicketSystem::cancelTicket(const std::string& ticketId) {
    // Implementation depends on ticket storage mechanism
}

std::vector<Ticket*> BusTicketSystem::getUserBookings(const std::string& userId) const {
    // Implementation depends on ticket storage mechanism
    return std::vector<Ticket*>();
}

void BusTicketSystem::updateTicketStatus(const std::string& ticketId, const std::string& status) {
    // Implementation depends on ticket storage mechanism
}

void BusTicketSystem::submitSupportTicket(const std::string& userId, const std::string& message) {
    supportResponses.push_back(std::make_pair(userId, message));
}

void BusTicketSystem::respondToSupportTicket(const std::string& userId, const std::string& response) {
    supportResponses.push_back(std::make_pair(userId, response));
}

std::vector<std::pair<std::string, std::string>> BusTicketSystem::viewSupportTickets() const {
    return supportResponses;
}

int BusTicketSystem::getTotalBookings() const {
    int total = 0;
    for (const auto& route : routePrices) {
        total += (50 - route.second); // 50 is default total seats
    }
    return total;
}

double BusTicketSystem::getTotalRevenue() const {
    double total = 0.0;
    for (const auto& route : routes) {
        total += route.second * (50 - routePrices.at(route.first));
    }
    return total;
}

int BusTicketSystem::getActiveUsers() const {
    return users.size();
}