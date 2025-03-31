#pragma once
#include "BasePiece.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include <iostream> 

class Promotion
{

public:

	static BasePiece* PromotePawn(char color); 

};

