#include "BusTicketSystem.h"
#include <iostream>

void displayMainMenu() {
    std::cout << "\nWelcome to Bus Ticket System" << std::endl
              << "Please select your role:" << std::endl
              << "1. Passenger" << std::endl
              << "2. Bus Operator" << std::endl
              << "3. Admin" << std::endl
              << "0. Exit" << std::endl
              << "Enter your choice: ";
}

void displayLoginMenu() {
    std::cout << "\nLogin/Register Menu:" << std::endl
              << "1. Login" << std::endl
              << "2. Register" << std::endl
              << "0. Back to main menu" << std::endl
              << "Enter your choice: ";
}

void displayPassengerMenu() {
    std::cout << "\nPassenger Menu:" << std::endl
              << "1. Search Bus" << std::endl
              << "2. Book Ticket" << std::endl
              << "3. Make Payment" << std::endl
              << "4. Customer Support" << std::endl
              << "5. View My Bookings" << std::endl
              << "0. Logout" << std::endl
              << "Enter your choice: ";
}

void displayBusOperatorMenu() {
    std::cout << "\nBus Operator Menu:" << std::endl
              << "1. Display Seat Availability" << std::endl
              << "2. Update Seat Status" << std::endl
              << "3. View All Buses" << std::endl
              << "0. Logout" << std::endl
              << "Enter your choice: ";
}

void displayAdminMenu() {
    std::cout << "\nAdmin Menu:" << std::endl
              << "1. Edit Price" << std::endl
              << "2. Add Bus Route" << std::endl
              << "3. Remove Bus Route" << std::endl
              << "4. Modify Bus Route" << std::endl
              << "5. View Support Tickets" << std::endl
              << "6. Respond to Support Ticket" << std::endl
              << "0. Logout" << std::endl
              << "Enter your choice: ";
}

void handlePassengerOperations(BusTicketSystem& system, const std::string& username) {
    int choice;
    do {
        displayPassengerMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {  // Search Bus
                std::string departure, arrival, date;
                std::cout << "Enter departure city: ";
                std::getline(std::cin, departure);
                std::cout << "Enter arrival city: ";
                std::getline(std::cin, arrival);
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                
                std::string routeId = system.getRouteId(departure, arrival);
                if (system.isRouteAvailable(routeId)) {
                    system.displaySeatAvailability(routeId);
                } else {
                    std::cout << "No available buses for this route." << std::endl;
                }
                break;
            }
            case 2: {  // Book Ticket
                std::string routeId;
                std::cout << "Enter route ID: ";
                std::getline(std::cin, routeId);
                
                if (system.bookTicket(routeId, username)) {
                    std::cout << "Ticket booked successfully!" << std::endl;
                } else {
                    std::cout << "Failed to book ticket." << std::endl;
                }
                break;
            }
            case 3: {  // Make Payment
                std::cout << "Payment processing is currently unavailable." << std::endl;
                break;
            }
            case 4: {  // Customer Support
                std::string message;
                std::cout << "Enter your message: ";
                std::getline(std::cin, message);
                system.submitSupportTicket(username, message);
                std::cout << "Support ticket submitted successfully!" << std::endl;
                break;
            }
            case 5: {  // View My Bookings
                auto bookings = system.getUserBookings(username);
                std::cout << "Your bookings:" << std::endl;
                for (const auto& ticket : bookings) {
                    // Display ticket information
                    std::cout << "Ticket ID: " << ticket->getTicketId() << std::endl;
                }
                break;
            }
            case 0:
                system.logout();
                std::cout << "Logged out successfully." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);
}

void handleBusOperatorOperations(BusTicketSystem& system, const std::string& username) {
    int choice;
    do {
        displayBusOperatorMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {  // Display Seat Availability
                std::string busId;
                std::cout << "Enter bus ID: ";
                std::getline(std::cin, busId);
                system.displaySeatAvailability(busId);
                break;
            }
            case 2: {  // Update Seat Status
                std::string busId, seatNumber;
                std::cout << "Enter bus ID: ";
                std::getline(std::cin, busId);
                std::cout << "Enter seat number: ";
                std::getline(std::cin, seatNumber);
                // TODO: Implement seat status update
                break;
            }
            case 3: {  // View All Buses
                system.displayAvailableBuses();
                break;
            }
            case 0:
                std::cout << "Logging out..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);
}

void handleAdminOperations(BusTicketSystem& system, const std::string& username) {
    int choice;
    do {
        displayAdminMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {  // Edit Price
                std::string routeId;
                double newPrice;
                std::cout << "Enter route ID: ";
                std::getline(std::cin, routeId);
                std::cout << "Enter new price: ";
                std::cin >> newPrice;
                std::cin.ignore();
                system.addNewRoute(routeId, newPrice);  // Update price by adding new route
                break;
            }
            case 2: {  // Add Bus Route
                std::string routeId;
                double price;
                std::cout << "Enter route ID (e.g., 'CityA_to_CityB'): ";
                std::getline(std::cin, routeId);
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cin.ignore();
                system.addNewRoute(routeId, price);
                break;
            }
            case 3: {  // Remove Bus Route
                std::string routeId;
                std::cout << "Enter route ID to remove: ";
                std::getline(std::cin, routeId);
                system.removeRoute(routeId);
                break;
            }
            case 4: {  // Modify Bus Route
                std::cout << "Route modification is handled through remove and add operations." << std::endl;
                break;
            }
            case 5: {  // View Support Tickets
                auto tickets = system.viewSupportTickets();
                std::cout << "\nSupport Tickets:" << std::endl;
                for (const auto& ticket : tickets) {
                    std::cout << "User: " << ticket.first << "\nMessage: " << ticket.second << "\n---" << std::endl;
                }
                break;
            }
            case 6: {  // Respond to Support Ticket
                std::string userId, response;
                std::cout << "Enter user ID: ";
                std::getline(std::cin, userId);
                std::cout << "Enter response: ";
                std::getline(std::cin, response);
                system.respondToSupportTicket(userId, response);
                break;
            }
            case 0:
                system.logout();
                std::cout << "Logged out successfully." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);
}

void handleLoginRegister(BusTicketSystem& system, const std::string& userType) {
    std::string username, password;
    int choice;
    bool loggedIn = false;

    do {
        displayLoginMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {  // Login
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                
                if (system.login(username, password)) {
                    std::cout << "Login successful!" << std::endl;
                    loggedIn = true;
                    
                    if (userType == "Passenger") {
                        handlePassengerOperations(system, username);
                    } else if (userType == "BusOperator") {
                        handleBusOperatorOperations(system, username);
                    } else if (userType == "Admin") {
                        handleAdminOperations(system, username);
                    }
                    
                    system.logout();
                } else {
                    std::cout << "Login failed!" << std::endl;
                }
                break;
            }
            case 2: {  // Register
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                
                if (system.registerUser(username, password, userType)) {
                    std::cout << "Registration successful! Please login." << std::endl;
                } else {
                    std::cout << "Registration failed! Username might already exist." << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Returning to main menu..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0 && !loggedIn);
}

int main() {
    BusTicketSystem system;
    int choice;
    
    // Add some sample data
    system.registerUser("admin", "admin123", "admin");
    system.registerUser("operator", "op123", "passenger");
    
    // Add some sample routes
    system.addNewRoute("Beijing_to_Shanghai", 100.0);
    system.addNewRoute("Shanghai_to_Guangzhou", 150.0);

    do {
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                handleLoginRegister(system, "passenger");
                break;
            case 2:
                handleLoginRegister(system, "operator");
                break;
            case 3:
                handleLoginRegister(system, "admin");
                break;
            case 0:
                std::cout << "Thank you for using Bus Ticket System!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);

    return 0;
} 