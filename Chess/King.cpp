#include "King.h"

//constructor for King
King::King(char Color) : BasePiece(Color) {}

//get piece symbol
char King::GetPiece() const {
    return 'K';
}

//check if the move is legal
bool King::LegalSquare(int IntRow, int IntCol, int FinalRow, int FinalCol, BasePiece* Board[8][8]) const {
    int roffset = FinalRow - IntRow;
    int coffset = FinalCol - IntCol;  

    //makes sure king can only move one square in any direction
    if (abs(roffset) > 1 || abs(coffset) > 1) {
        return false;  // King can only move one square
    }

    //check if the destination square is occupied by a piece of the same color
    if (Board[FinalRow][FinalCol] != nullptr && Board[FinalRow][FinalCol]->GetColor() == this->GetColor()) {
        return false;  //wont land on a square occupied by own piece
    }

    //check if the path is blocked by another piece (king can’t jump over pawns or other pieces)
    if (Board[FinalRow][FinalCol] != nullptr) {
        return false;  //if there’s a piece in the destination square, so the king can't move there
    }

    return true;  //the move is legal
}
