#ifndef PASSENGER_H
#define PASSENGER_H

#include "User.h"
#include <vector>

class Ticket;  // Forward declaration

class Passenger : public User {
private:
    std::vector<Ticket*> bookingHistory;
    std::string paymentInfo;

public:
    Passenger(const std::string& username, const std::string& password);
    ~Passenger();

    // F03: Search Bus
    void searchBus(const std::string& departure, const std::string& arrival, const std::string& date);
    
    // F04: Book Ticket
    bool bookTicket(const std::string& busId, const std::string& seatNumber);
    
    // F05: Make Payment
    bool makePayment(const std::string& ticketId, const std::string& paymentMethod);
    
    // Additional functionality
    void viewBookingHistory() const;
    void cancelBooking(const std::string& ticketId);
    void addToBookingHistory(Ticket* ticket);
};

#endif // PASSENGER_H 