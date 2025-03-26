
#pragma once
#include "BasePiece.h"
#include "Pawn.h"
class Board
{
private:
	BasePiece* BoardArray[8][8];
public:
	Board();
	~Board();
	void Move();
	void display();
};

