#include <iostream>
#include "Board.h"
using namespace std;

int main() {
    Board G1;  // Create a Board object
    int choice;

    while (true) {
        // Display a simple menu
        cout << "Chess Game Menu:" << endl;
        cout << "1. Start a new game" << endl;
        cout << "2. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Start a new game
            cout << "Starting a new game." << endl;
            cout << "Initial Board Setup:" << endl;
            G1.display();

            // Game loop to allow repeated moves
            while (true) {
                
                G1.Move();  // Move a piece 

                // Display the board after the move
                cout << "\nBoard After Move:" << endl;
                G1.display();
            }
        }
        else if (choice == 2) {
            // Exit the program
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
