#include <iostream>
using namespace std;

void userMenu();
void adminMenu(); // Functions

int main()
{
    int choice;
    
    do
    {
        cout << "\n====== Welcome to OBus! ======\n";
        cout << "1. User\n";
        cout << "2. Admin\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1: userMenu();
            break;
            
            case 2: adminMenu();
            break;
            
            case 3: cout << "Thanks for using the system. Goodbye!\n";
            break;
            
            default: cout << "Invalid choice! Please try again.\n";
        }
    }
    while(choice != 3);
    
    return 0;
}