#include "Bus.h"
#include <iostream>
#include <iomanip>

Bus::Bus(const std::string& busId, const std::string& routeId, int totalSeats)
    : busId(busId), routeId(routeId), totalSeats(totalSeats), currentStatus("On Time") {
    // Initialize seat availability
    for (int i = 1; i <= totalSeats; ++i) {
        seatAvailability[std::to_string(i)] = true;
    }
}

Bus::~Bus() {
    seatAvailability.clear();
}

// Getters
std::string Bus::getBusId() const {
    return busId;
}

std::string Bus::getRouteId() const {
    return routeId;
}

std::string Bus::getCurrentStatus() const {
    return currentStatus;
}

std::string Bus::getDeparture() const {
    return departure;
}

std::string Bus::getArrival() const {
    return arrival;
}

std::string Bus::getDepartureTime() const {
    return departureTime;
}

std::string Bus::getArrivalTime() const {
    return arrivalTime;
}

std::string Bus::getDate() const {
    return date;
}

// Setters
void Bus::setCurrentStatus(const std::string& status) {
    currentStatus = status;
}

void Bus::setRoute(const std::string& departure, const std::string& arrival) {
    this->departure = departure;
    this->arrival = arrival;
}

void Bus::setSchedule(const std::string& departureTime, const std::string& arrivalTime) {
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
}

void Bus::setDate(const std::string& date) {
    this->date = date;
}

// Seat management
bool Bus::isSeatAvailable(const std::string& seatNumber) const {
    auto it = seatAvailability.find(seatNumber);
    return it != seatAvailability.end() && it->second;
}

bool Bus::bookSeat(const std::string& seatNumber) {
    if (isSeatAvailable(seatNumber)) {
        seatAvailability[seatNumber] = false;
        return true;
    }
    return false;
}

void Bus::releaseSeat(const std::string& seatNumber) {
    seatAvailability[seatNumber] = true;
}

bool Bus::updateSeatStatus(const std::string& seatNumber, bool isAvailable) {
    if (seatAvailability.find(seatNumber) != seatAvailability.end()) {
        seatAvailability[seatNumber] = isAvailable;
        return true;
    }
    return false;
}

std::vector<std::string> Bus::getAvailableSeats() const {
    std::vector<std::string> availableSeats;
    for (const auto& seat : seatAvailability) {
        if (seat.second) {
            availableSeats.push_back(seat.first);
        }
    }
    return availableSeats;
}

int Bus::getAvailableSeatCount() const {
    int count = 0;
    for (const auto& seat : seatAvailability) {
        if (seat.second) {
            ++count;
        }
    }
    return count;
}

// Display
void Bus::displayBusInfo() const {
    std::cout << "\nBus Information:" << std::endl
              << "Bus ID: " << busId << std::endl
              << "Route: " << departure << " -> " << arrival << std::endl
              << "Schedule: " << departureTime << " - " << arrivalTime << std::endl
              << "Status: " << currentStatus << std::endl
              << "Available Seats: " << getAvailableSeatCount() << "/" << totalSeats << std::endl;
}

void Bus::displaySeatMap() const {
    std::cout << "\nSeat Map:" << std::endl;
    int seatsPerRow = 4;
    int currentSeat = 1;
    
    for (int i = 0; i < totalSeats; i += seatsPerRow) {
        for (int j = 0; j < seatsPerRow && currentSeat <= totalSeats; ++j) {
            std::string seatNumber = std::to_string(currentSeat);
            std::cout << std::setw(4) << (seatAvailability.at(seatNumber) ? "[" + seatNumber + "]" : "[X]");
            ++currentSeat;
        }
        std::cout << std::endl;
    }
} 