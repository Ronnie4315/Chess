#pragma once
#include "BasePiece.h"

class Pawn : public BasePiece {
public:
    // Constructor for Pawn
    Pawn(char Color);

    // Get piece symbol (always 'P' for pawn)
    char GetPiece() const override;

    // Check if the pawn's move is legal
    bool LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const override;
};
