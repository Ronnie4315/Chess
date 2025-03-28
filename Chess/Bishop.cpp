#include "Bishop.h"
// Constructor for Bishop
Bishop::Bishop(char Color) : BasePiece(Color) {}

// Get piece symbol
char Bishop::GetPiece() const {
	return 'B';
}

// Check if the move is legal
bool Bishop::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
	int roffset;
	int coffset;
	roffset = FinalRow - IntRow;
	coffset = FinalCol - IntCol;
	if (abs(roffset) != abs(coffset)) {
		return false;
	}
	if(roffset > 0 && coffset > 0) {
		//int count = 0;
		for (int i = IntRow; i !=FinalRow; i++) {
			if (Board[IntRow+i][IntCol+i] != nullptr) {
				return false;
			}
			/*if (Board[IntRow + i][IntCol + i]->GetColor() != this->GetColor()) {
				count++;
			}*/
		}
		/*if (count > 1) {
			return false;
		}*/
	}
	if (roffset < 0 && coffset < 0) {
		int count = 0;
		for (int i = IntRow; i != FinalRow; i--) {
			if (Board[IntRow + i][IntCol + i] != nullptr) {
				return false;
			}
		}
	}

		if (roffset > 0 && coffset < 0) {
			int count = 0;
			for (int i = IntRow; i < roffset; i++) {
				if (Board[IntRow + i][IntCol - i] != nullptr) {
					return false;
				}

			}
		}
	if (roffset < 0 && coffset > 0) {
		int count = 0;
		for (int i = IntCol; i < coffset; i++) {
			if (Board[IntRow - i][IntCol + i] != nullptr) {
				return false;
			}
		}
	}
	return true;
 }