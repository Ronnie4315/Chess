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
	
	if (IntRow == FinalRow) {
		direction = FinalCol - IntCol;
		int count = 0;
		/*
		if (direction > 0) {
			for (int i = IntCol; i < direction; i++) {
				if (Board[IntRow][FinalCol + i]->GetColor() == this->GetColor()) {
					return false;
				}
				if (Board[IntRow][FinalCol + i]->GetColor() != this->GetColor()) {
					count++;
				}
			}
		}
		if (direction < 0) {
			for (int i = IntRow; i > direction; i--) {
				if (Board[IntRow][FinalCol+i]->GetColor() == this->GetColor()) {
					return false;
				}
				if (Board[IntRow + i][FinalCol+i]->GetColor() != this->GetColor()) {
					count++;
				}
			}
		}
		if (count > 1) {
			return false;
		}
		*/
	}
	if (IntCol == FinalCol) {
		direction = FinalRow - IntRow;
		/*
		int count = 0;
		if (direction > 0) {
			for (int i = IntRow; i < direction; i++) {
				if (Board[FinalCol][IntRow + i]->GetColor() == this->GetColor()) {
					return false;
				}
				if (Board[FinalCol][IntRow + i]->GetColor() != this->GetColor()) {
					count++;
				}
			}
		}
		if (direction < 0) {
			for (int i = IntRow; i > direction; i--) {
				if (Board[IntCol][IntRow + i]->GetColor() == this->GetColor()) {
					return false;
				}
				if (Board[FinalCol][IntRow + i]->GetColor() != this->GetColor()) {
					count++;
				}
			}
		}
		if (count > 1) {
			return false;
		}
		*/
	}

	if ((FinalRow == IntRow + direction && IntCol == FinalCol) && (Board[FinalCol][FinalRow] == nullptr || Board[FinalCol][FinalRow]->GetColor() != this->GetColor())) {
		return true;
	}
	if (FinalCol == IntCol + direction && IntRow == FinalRow && ( Board[FinalCol][FinalRow] == nullptr || Board[FinalCol][FinalRow]->GetColor() != this->GetColor())) {
		return true;
	}
	return false;
}