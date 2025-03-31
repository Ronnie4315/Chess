#pragma once
#include "BasePiece.h"

class GameCheck {
public:
    static bool isInCheck(char kingColor, BasePiece* Board[8][8]);
    static bool isCheckMate(char kingColor, BasePiece* Board[8][8]);
};

