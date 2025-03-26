#include "BasePiece.h"
// Constructor 
BasePiece::BasePiece(char Color) : PieceColor(Color) {}

// Destructor 
BasePiece::~BasePiece() {}

// Get piece color 
char BasePiece::GetColor() const {
    return PieceColor;
}
