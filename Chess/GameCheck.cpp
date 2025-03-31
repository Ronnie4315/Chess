#include "GameCheck.h"
#include "King.h"

bool GameCheck::isInCheck(char kingColor, BasePiece* Board[8][8]) {
    int kingRow = -1, kingCol = -1;

    // Find king's position
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            if (Board[r][c] && Board[r][c]->GetPiece() == 'K' && Board[r][c]->GetColor() == kingColor) {
                kingRow = r;
                kingCol = c;
            }

    // Check threats to king
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            if (Board[r][c] && Board[r][c]->GetColor() != kingColor)
                if (Board[r][c]->LegalSquare(r, c, kingRow, kingCol, Board))
                    return true;

    return false;
}

bool GameCheck::isCheckMate(char kingColor, BasePiece* Board[8][8]) {
    if (!isInCheck(kingColor, Board))
        return false;  // Not checkmate if king isn't in check

    // Check every possible move for every piece of current player
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (Board[r][c] && Board[r][c]->GetColor() == kingColor) {
                for (int newR = 0; newR < 8; newR++) {
                    for (int newC = 0; newC < 8; newC++) {
                        if (Board[r][c]->LegalSquare(r, c, newR, newC, Board)) {
                            // Simulate move
                            BasePiece* originalDest = Board[newR][newC];
                            Board[newR][newC] = Board[r][c];
                            Board[r][c] = nullptr;

                            // If king is not in check after move, it's not checkmate
                            bool safe = !isInCheck(kingColor, Board);

                            // Revert move
                            Board[r][c] = Board[newR][newC];
                            Board[newR][newC] = originalDest;

                            if (safe)
                                return false;  // Found valid move
                        }
                    }
                }
            }
        }
    }

    return true;  // No valid moves found; checkmate
}
