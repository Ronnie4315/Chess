#pragma once
#include <iostream>
using namespace std;

class BasePiece {
protected:
    char PieceColor;  // 'W' for White, 'B' for Black

public:
    // Constructor
    explicit BasePiece(char Color);

    // Virtual destructor
    virtual ~BasePiece();

    // Getter for piece color
    char GetColor() const;

    // Pure virtual function to get the piece type (P for Pawn, etc.)
    virtual char GetPiece() const = 0;

    // Pure virtual function for piece-specific movement validation
    virtual bool LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const = 0;
};
