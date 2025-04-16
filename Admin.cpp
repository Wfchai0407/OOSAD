#include "Admin.h"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

Admin::Admin(const std::string& username, const std::string& password)
    : User(username, password) {
    // Generate a random admin ID
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1000, 9999);
    
    std::stringstream ss;
    ss << "ADM" << std::setfill('0') << std::setw(4) << dis(gen);
    adminId = ss.str();
    userType = "admin";
}

Admin::~Admin() {
    supportTickets.clear();
}

void Admin::editPrice(const std::string& routeId, double newPrice) {
    // TODO: Implement price editing functionality
    std::cout << "Updating price for route " << routeId << " to: $" << newPrice << std::endl;
}

void Admin::addRoute(const std::string& departure, const std::string& arrival, double price) {
    // TODO: Implement route addition
    std::cout << "Adding new route from " << departure << " to " << arrival 
              << " with price: $" << price << std::endl;
}

void Admin::removeRoute(const std::string& routeId) {
    // TODO: Implement route removal
    std::cout << "Removing route " << routeId << std::endl;
}

void Admin::modifyRoute(const std::string& routeId, const std::string& departure, const std::string& arrival) {
    // TODO: Implement route modification
    std::cout << "Modifying route " << routeId << " to: " << departure << " -> " << arrival << std::endl;
}

void Admin::respondToSupport(const std::string& ticketId, const std::string& response) {
    // TODO: Implement support response system
    std::cout << "Responding to support ticket " << ticketId << ": " << response << std::endl;
}

void Admin::viewSupportTickets() const {
    std::cout << "Current Support Tickets:" << std::endl;
    for (const auto& ticket : supportTickets) {
        std::cout << ticket << std::endl;
    }
}

std::string Admin::getAdminId() const {
    return adminId;
}

void Admin::addSupportTicket(const std::string& ticket) {
    supportTickets.push_back(ticket);
}

void Admin::generateReport() const {
    // TODO: Implement report generation
    std::cout << "Generating administrative report..." << std::endl;
} 