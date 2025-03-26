#pragma once
#include "BasePiece.h"
#include "Pawn.h"

class Board {
private:
    BasePiece* BoardArray[8][8];  // Array of pointers to BasePiece

public:
    Board();
    ~Board();  // Destructor to clean up dynamically allocated pieces

    void display();  // Display the board
    void Move();     // Move a piece
};

