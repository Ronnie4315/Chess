#include "Bishop.h"
// Constructor for Bishop
Bishop::Bishop(char Color) : BasePiece(Color) {}

// Get piece symbol
char Bishop::GetPiece() const {
	return 'B';
}

// Check if the move is legal
bool Bishop::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
	int roffset;//row offset
	int coffset;//column offset
	roffset = FinalRow - IntRow;
	coffset = FinalCol - IntCol;
	if (abs(roffset) != abs(coffset)) {
		return false;
	}
	int rdirection = (roffset > 0) ? 1 : -1;
	int cdirection = (coffset > 0) ? 1 : -1;

	for (int i = IntRow+rdirection; i != FinalRow; i = i + rdirection) {
		if (Board[i][IntCol+cdirection] != nullptr) {	
			return false;
		}
		cdirection = cdirection + cdirection;
	}
	if (Board[FinalRow][FinalCol] == nullptr || Board[FinalRow][FinalCol]->GetColor() != this->GetColor()) {
		return true;
	}
	return false;
 }