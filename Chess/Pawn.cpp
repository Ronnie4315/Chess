#include "Pawn.h"

// Constructor for Pawn
Pawn::Pawn(char Color) : BasePiece(Color) {}

// Return piece symbol (always 'P' for pawn)
char Pawn::GetPiece() const {
    return 'P';  // Same symbol for both colors
}

// Check pawn move legality
bool Pawn::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
    int direction;
    if (PieceColor == 'W') {
        direction = -1;  // White moves up
    }
    else {
        direction = 1;   // Black moves down
    }

    int startRow;
    if (PieceColor == 'W') {
        startRow = 6;  // Initial row for white pawn
    }
    else {
        startRow = 1;  // Initial row for black pawn
    }

    // Move one square forward
    if (FinalRow == IntRow + direction && FinalCol == IntCol && Board[FinalRow][FinalCol] == nullptr) {
        return true;
    }

    // Initial double move
    if (IntRow == startRow && FinalRow == IntRow + 2 * direction && FinalCol == IntCol &&
        Board[FinalRow][FinalCol] == nullptr && Board[IntRow + direction][IntCol] == nullptr) {
        return true;
    }

    // Diagonal capture
    if (FinalRow == IntRow + direction && (FinalCol == IntCol + 1 || FinalCol == IntCol - 1)) {
        if (Board[FinalRow][FinalCol] != nullptr && Board[FinalRow][FinalCol]->GetColor() != this->GetColor()) {
            return true;
        }
    }

    return false;  // Invalid move otherwise
}
