#include "Knight.h"
// Constructor for Knight
Knight::Knight(char Color) : BasePiece(Color) {}

// Get piece symbol
char Knight::GetPiece() const {
	return 'N';
}

// Check if the move is legal
bool Knight::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
	int roffset;
	int coffset;
	roffset = FinalRow - IntRow;
	coffset = FinalCol - IntCol;
	if (abs(roffset) == 2 && abs(coffset) == 1) {
		if (Board[FinalRow][FinalCol] != nullptr && Board[FinalRow][FinalCol]->GetColor() != this->GetColor()) {
			return true;
		}
	}
	if (abs(roffset) == 1 && abs(coffset) == 2) {
		if (Board[FinalRow][FinalCol] != nullptr && Board[FinalRow][FinalCol]->GetColor() != this->GetColor()) {
			return true;
		}
	}
	//if(Board[FinalRow][FinalCol])
	return false;
}