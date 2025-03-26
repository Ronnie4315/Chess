#include "Board.h"

#pragma once
class BasePiece :public Board
{
    protected:
        char PieceColor;  // 'W' for White, 'B' for Black 

    public:
        // Constructor 
        explicit BasePiece(char Color);

        // Virtual destructor 
        virtual ~BasePiece();

        // Getter for piece color 
        char GetColor() const;

        // Pure virtual function to get the piece type (K for King, Q for Queen, etc.) 
        virtual char GetPiece() const = 0;

        // Virtual function to check if the move is legal 
        virtual bool LegalMove(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const;

        // Pure virtual function for piece-specific movement validation 
        virtual bool LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const = 0
 };

