#include <iostream>
#include "Board.h"
using namespace std;

int main() {
    // Create a Board object
    Board G1;

    // Display the initial state of the board
    cout << "Initial Board Setup:" << endl;
    G1.display();

    // Test move for pawn
    G1.Move();  // Move a piece (pawn test)

    // Display the board after a move
    cout << "\nBoard After Move:" << endl;
    G1.display();

    // Test move for pawn
    G1.Move();  // Move a piece (pawn test)

    // Display the board after a move
    cout << "\nBoard After Move:" << endl;
    G1.display();

    return 0;
}
