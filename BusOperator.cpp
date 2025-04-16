#include "BusOperator.h"
#include <iostream>

BusOperator::BusOperator(const std::string& username, const std::string& password, const std::string& operatorId)
    : User(username, password), operatorId(operatorId) {
    userType = "BusOperator";
}

BusOperator::~BusOperator() {
    // Clean up managed buses
    for (auto bus : managedBuses) {
        delete bus;
    }
    managedBuses.clear();
}

void BusOperator::displaySeatAvailability(const std::string& busId) const {
    // TODO: Implement seat availability display
    std::cout << "Displaying seat availability for bus " << busId << std::endl;
}

void BusOperator::sendNotification(const std::string& busId, const std::string& message) {
    // TODO: Implement notification system
    std::cout << "Sending notification for bus " << busId << ": " << message << std::endl;
}

void BusOperator::addBus(Bus* bus) {
    if (bus != nullptr) {
        managedBuses.push_back(bus);
    }
}

void BusOperator::removeBus(const std::string& busId) {
    // TODO: Implement bus removal
    std::cout << "Removing bus " << busId << " from managed buses" << std::endl;
}

void BusOperator::updateBusStatus(const std::string& busId, const std::string& status) {
    // TODO: Implement bus status update
    std::cout << "Updating status for bus " << busId << " to: " << status << std::endl;
}

std::vector<Bus*> BusOperator::getManagedBuses() const {
    return managedBuses;
}

std::string BusOperator::getOperatorId() const {
    return operatorId;
} 