
#pragma once
class Board
{
private:
	char chess[9][9];
public:
	Board();
	virtual void Move();
	void display();
};

