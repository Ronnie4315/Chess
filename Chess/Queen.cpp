#include "Queen.h"
#include <cmath>
// Constructor for Queen
Queen::Queen(char Color) : BasePiece(Color) {}

// Get piece symbol
char Queen::GetPiece() const {
    return 'Q';
}


bool Queen::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
    int roffset = FinalRow - IntRow;
    int coffset = FinalCol - IntCol;

    //check if the move is along a straight line or diagonal
    if (FinalRow == IntRow || FinalCol == IntCol || abs(roffset) == abs(coffset)) {
        // Determine rowStep and colStep based on the direction of movement
        int rowStep = 0;
        int colStep = 0;

        //calculate rowStep if moving vertically
        if (FinalRow > IntRow) {
            rowStep = 1; //go down
        }
        else if (FinalRow < IntRow) {
            rowStep = -1; //go up
        }

        //calculate colStep if moving horizontally
        if (FinalCol > IntCol) {
            colStep = 1; //go right
        }
        else if (FinalCol < IntCol) {
            colStep = -1; //go left
        }

        // Loop through the path and check for any piece blocking the Queen
        int row = IntRow + rowStep, col = IntCol + colStep;
        while (row != FinalRow || col != FinalCol) {
            if (Board[row][col] != nullptr) { // if blocked by a piece
                return false;
            }
            row += rowStep;
            col += colStep;
        }

        // Check if the final square is occupied by a piece of the same color
        if (Board[FinalRow][FinalCol] != nullptr && Board[FinalRow][FinalCol]->GetColor() == this->GetColor()) {
            return false; //illegal move
        }

        return true; // Valid move
    }

    return false; // Invalid move
}
