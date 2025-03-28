#include "King.h"
// Constructor for King
King::King(char Color) :BasePiece(Color){}

// Get piece symbol
char King::GetPiece() const {
	return 'K';
}

// Check if the move is legal
bool King::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
	int roffset = FinalRow-IntCol;
	int coffset = FinalCol - IntCol;
	if (abs(roffset) == 1 && abs(coffset)) {
		return false;
	}
	if (Board[FinalRow][FinalCol] != nullptr && Board[FinalRow][FinalCol]->GetColor() == this->GetColor()) {
		return false;
	}
	return true;
}