#pragma once
#include "BasePiece.h"

class Board {
private:
    BasePiece* BoardArray[8][8];

public:
    Board();  // Constructor
    ~Board(); // Destructor
    void display();  // Display the board
    bool Move(char currentPlayer);  // Updated to return a bool
};
