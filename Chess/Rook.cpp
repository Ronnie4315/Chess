#include "Rook.h"

// Constructor for Pawn
Rook::Rook(char Color):BasePiece(Color) {
}

// Get piece symbol (always 'P' for pawn)
char Rook::GetPiece() const{
	return 'R';
}

// Check if the Rook's move is legal
bool Rook::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
	int direction =0;
	int roffset = FinalRow - IntRow;
	int coffset = FinalCol - IntCol;
	if (IntRow == FinalRow) {
		direction = (FinalCol - IntCol > 0) ? 1:-1;
		for (int i = IntCol + direction; i != FinalCol; i = i + direction) {
			if (Board[IntRow][i] != nullptr) {
				return false;
			}
		}

	}
	if (IntCol == FinalCol) {
		direction = (FinalRow - IntRow > 0) ? 1:-1;
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