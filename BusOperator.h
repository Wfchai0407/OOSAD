#ifndef BUS_OPERATOR_H
#define BUS_OPERATOR_H

#include "User.h"
#include <vector>
#include <string>

class Bus;  // Forward declaration

class BusOperator : public User {
private:
    std::vector<Bus*> managedBuses;
    std::string operatorId;

public:
    BusOperator(const std::string& username, const std::string& password, const std::string& operatorId);
    ~BusOperator();

    // F09: Display Seat Availability
    void displaySeatAvailability(const std::string& busId) const;
    
    // F10: Real-time Notification
    void sendNotification(const std::string& busId, const std::string& message);
    
    // Additional functionality
    void addBus(Bus* bus);
    void removeBus(const std::string& busId);
    void updateBusStatus(const std::string& busId, const std::string& status);
    std::vector<Bus*> getManagedBuses() const;
    std::string getOperatorId() const;
};

#endif // BUS_OPERATOR_H 