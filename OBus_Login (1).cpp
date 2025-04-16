#include <iostream>
using namespace std;

void passengerMenu();
void adminMenu();
void busOperatorMenu(); 

int main()
{
    int choice;
    
    do
    {
        cout << "\n====== Welcome to OBus! ======\n";
        cout << "1. Passenger\n";
        cout << "2. Admin\n";
        cout << "3. Bus Operator\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            passengerMenu();
            break;
            
            case 2:
            adminMenu();
            break;
            
            case 3:
            busOperatorMenu();
            break;
            
            case 4:
            cout << "Thanks for using the system. See you again!\n";
            break;
            
            default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    while(choice != 4);
    
    return 0;
}

void passengerMenu()
{
    cout << "\n------ Passenger Menu ------\n";
    
}

void adminMenu()
{
    cout << "\n------ Admin Menu ------\n";
    
}

void busOperatorMenuMenu()
{
    cout << "\n------ Bus Operator Menu ------\n";
    
}