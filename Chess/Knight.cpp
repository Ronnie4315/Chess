#include "Knight.h"
// Constructor for Knight
Knight::Knight(char Color) : BasePiece(Color) {}

// Get piece symbol
char Knight::GetPiece() const {
	return 'N';
}

// Check if the move is legal
bool Knight::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
    int roffset = FinalRow - IntRow;
    int coffset = FinalCol - IntCol;

    // Check if the move is in an L-shape
    if ((abs(roffset) == 2 && abs(coffset) == 1) || (abs(roffset) == 1 && abs(coffset) == 2)) {
        // Check if the destination square is either empty or occupied by an opponent's piece
        if (Board[FinalRow][FinalCol] == nullptr || Board[FinalRow][FinalCol]->GetColor() != this->GetColor()) {
            return true;
        }
    }

    return false; // If none of the conditions are met, the move is illegal
}
