
#pragma once 

#include "BasePiece.h" 

    class Pawn : public BasePiece {
    public:
        // Constructor 
        Pawn(char Color);

        // Get piece type (returns 'P' or 'p')
        char GetPiece() const;

        // Basic pawn move logic
        bool LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const;
};

