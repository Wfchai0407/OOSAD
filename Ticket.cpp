#include "Ticket.h"
#include <iostream>
#include <ctime>
#include <iomanip>

Ticket::Ticket(const std::string& ticketId, const std::string& busId,
               const std::string& userId, const std::string& seatNumber)
    : ticketId(ticketId), busId(busId), userId(userId), seatNumber(seatNumber),
      price(0.0), status("Booked"), paymentStatus(false) {
    // Set booking date to current time
    time_t now = time(0);
    char* dt = ctime(&now);
    bookingDate = std::string(dt);
    bookingDate = bookingDate.substr(0, bookingDate.length() - 1); // Remove newline
}

Ticket::~Ticket() {}

// Getters
std::string Ticket::getTicketId() const { return ticketId; }
std::string Ticket::getBusId() const { return busId; }
std::string Ticket::getUserId() const { return userId; }
std::string Ticket::getSeatNumber() const { return seatNumber; }
double Ticket::getPrice() const { return price; }
std::string Ticket::getBookingDate() const { return bookingDate; }
std::string Ticket::getStatus() const { return status; }
std::string Ticket::getPaymentMethod() const { return paymentMethod; }
bool Ticket::getPaymentStatus() const { return paymentStatus; }

// Setters
void Ticket::setStatus(const std::string& newStatus) {
    status = newStatus;
}

void Ticket::setPaymentMethod(const std::string& method) {
    paymentMethod = method;
}

void Ticket::setPrice(double newPrice) {
    price = newPrice;
}

void Ticket::setPaymentStatus(bool status) {
    paymentStatus = status;
}

// Ticket operations
bool Ticket::processPayment(const std::string& method) {
    if (price > 0) {
        paymentMethod = method;
        paymentStatus = true;
        status = "Paid";
        std::cout << "Processing payment of $" << price << " using " << method << std::endl;
        return true;
    }
    return false;
}

void Ticket::cancelTicket() {
    status = "Cancelled";
    paymentStatus = false;
    std::cout << "Ticket " << ticketId << " has been cancelled" << std::endl;
}

void Ticket::displayTicketInfo() const {
    std::cout << "\nTicket Information:" << std::endl
              << "Ticket ID: " << ticketId << std::endl
              << "Bus ID: " << busId << std::endl
              << "User ID: " << userId << std::endl
              << "Seat Number: " << seatNumber << std::endl
              << "Price: $" << std::fixed << std::setprecision(2) << price << std::endl
              << "Booking Date: " << bookingDate << std::endl
              << "Status: " << status << std::endl
              << "Payment Method: " << paymentMethod << std::endl
              << "Payment Status: " << (paymentStatus ? "Paid" : "Unpaid") << std::endl;
}

bool Ticket::isValid() const {
    return !ticketId.empty() && !busId.empty() && !userId.empty() && 
           !seatNumber.empty() && status != "Cancelled";
} 