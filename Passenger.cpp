#include "Passenger.h"
#include "Ticket.h"
#include <iostream>

Passenger::Passenger(const std::string& username, const std::string& password)
    : User(username, password) {
    userType = "passenger";
}

Passenger::~Passenger() {
    for (auto ticket : bookingHistory) {
        if (ticket) {
            delete ticket;
        }
    }
    bookingHistory.clear();
}

void Passenger::searchBus(const std::string& departure, const std::string& arrival, const std::string& date) {
    std::cout << "Searching for buses from " << departure << " to " << arrival 
              << " on " << date << std::endl;
}

bool Passenger::bookTicket(const std::string& busId, const std::string& seatNumber) {
    std::cout << "Booking ticket for bus " << busId << ", seat " << seatNumber << std::endl;
    return true;
}

bool Passenger::makePayment(const std::string& ticketId, const std::string& paymentMethod) {
    std::cout << "Processing payment for ticket " << ticketId 
              << " using " << paymentMethod << std::endl;
    return true;
}

void Passenger::viewBookingHistory() const {
    std::cout << "Booking History:" << std::endl;
    for (const auto& ticket : bookingHistory) {
        if (ticket) {
            std::cout << "Ticket ID: " << ticket->getTicketId() << std::endl;
        }
    }
}

void Passenger::cancelBooking(const std::string& ticketId) {
    std::cout << "Cancelling booking " << ticketId << std::endl;
}

void Passenger::addToBookingHistory(Ticket* ticket) {
    if (ticket) {
        bookingHistory.push_back(ticket);
    }
} 