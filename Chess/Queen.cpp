#include "Queen.h"
#include <cmath>
// Constructor for Queen
Queen::Queen(char Color) :BasePiece(Color) {}

// Get piece symbol
char Queen::GetPiece() const{
	return 'Q';
}

// Check if the move is legal
bool Queen::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
	int roffset;
	int coffset;
	roffset = FinalRow - IntRow;
	coffset = FinalCol - IntCol;

	if (FinalRow=IntRow||FinalCol==IntCol|| abs(roffset) == abs(coffset)) {
		return true;
	}
	return false;
}