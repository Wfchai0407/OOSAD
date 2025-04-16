#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
private:
    std::string ticketId;
    std::string busId;
    std::string userId;
    std::string seatNumber;
    double price;
    std::string bookingDate;
    std::string status;  // "Booked", "Paid", "Cancelled", etc.
    std::string paymentMethod;
    bool paymentStatus;

public:
    Ticket(const std::string& ticketId, const std::string& busId, 
           const std::string& userId, const std::string& seatNumber);
    ~Ticket();

    // Getters
    std::string getTicketId() const;
    std::string getBusId() const;
    std::string getUserId() const;
    std::string getSeatNumber() const;
    double getPrice() const;
    std::string getBookingDate() const;
    std::string getStatus() const;
    std::string getPaymentMethod() const;
    bool getPaymentStatus() const;

    // Setters
    void setStatus(const std::string& status);
    void setPaymentMethod(const std::string& method);
    void setPrice(double newPrice);
    void setPaymentStatus(bool status);

    // Ticket operations
    bool processPayment(const std::string& paymentMethod);
    void cancelTicket();
    void displayTicketInfo() const;
    bool isValid() const;
};

#endif // TICKET_H 