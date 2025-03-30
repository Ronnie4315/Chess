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
	int direction;
	roffset = FinalRow - IntRow;
	coffset = FinalCol - IntCol;
	int rdirection = (roffset > 0) ? 1 : -1;
	int cdirection = (coffset > 0) ? 1 : -1;
	if (abs(roffset) == abs(coffset)) {
		for (int i = IntRow + rdirection; i != FinalRow; i = i + rdirection) {
			if (Board[i][IntCol + cdirection] != nullptr) {
				return false;
			}
			cdirection = cdirection + cdirection;
		}
		if (Board[FinalRow][FinalCol] == nullptr || Board[FinalRow][FinalCol]->GetColor() != this->GetColor()) {
			return true;
		}
	}
	if (IntRow == FinalRow) {
		direction = (FinalCol - IntCol > 0) ? 1 : -1;
		for (int i = IntCol + direction; i != FinalCol; i = i + direction) {
			if (Board[IntRow][i] != nullptr) {
				return false;
			}
		}

	}
	if (IntCol == FinalCol) {
		direction = (FinalRow - IntRow > 0) ? 1 : -1;
		for (int i = IntRow + direction; i != FinalRow; i = i + direction) {
			if (Board[i][IntCol] != nullptr) {
				return false;
			}
		}
	}
	if ((FinalRow == IntRow + roffset && IntCol == FinalCol) && (Board[FinalRow][FinalCol] == nullptr || Board[FinalRow][FinalCol]->GetColor() != this->GetColor())) {
		return true;
	}
	if (FinalCol == IntCol + coffset && IntRow == FinalRow && (Board[FinalRow][FinalCol] == nullptr || Board[FinalRow][FinalCol]->GetColor() != this->GetColor())) {
		return true;
	}

	return false;
}