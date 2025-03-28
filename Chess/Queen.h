#pragma once
#include "BasePiece.h"

class Queen : public BasePiece {
public:
    // Constructor for Queen
    Queen(char Color);

    // Get piece symbol
    char GetPiece() const override;

    // Check if the move is legal
    bool LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const override;
};
