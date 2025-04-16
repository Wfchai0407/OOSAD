#ifndef BUS_H
#define BUS_H

#include <string>
#include <vector>
#include <map>

class Bus {
private:
    std::string busId;
    std::string routeId;
    int totalSeats;
    std::map<std::string, bool> seatAvailability;  // seat number -> is available
    std::string currentStatus;  // "On Time", "Delayed", "Cancelled", etc.
    std::string departure;
    std::string arrival;
    std::string departureTime;
    std::string arrivalTime;
    std::string date;

public:
    Bus(const std::string& busId, const std::string& routeId, int totalSeats);
    ~Bus();

    // Getters
    std::string getBusId() const;
    std::string getRouteId() const;
    std::string getCurrentStatus() const;
    std::string getDeparture() const;
    std::string getArrival() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    std::string getDate() const;
    
    // Setters
    void setCurrentStatus(const std::string& status);
    void setRoute(const std::string& departure, const std::string& arrival);
    void setSchedule(const std::string& departureTime, const std::string& arrivalTime);
    void setDate(const std::string& date);
    
    // Seat management
    bool isSeatAvailable(const std::string& seatNumber) const;
    bool bookSeat(const std::string& seatNumber);
    void releaseSeat(const std::string& seatNumber);
    bool updateSeatStatus(const std::string& seatNumber, bool isAvailable);
    std::vector<std::string> getAvailableSeats() const;
    int getAvailableSeatCount() const;
    
    // Display
    void displayBusInfo() const;
    void displaySeatMap() const;
};

#endif // BUS_H 