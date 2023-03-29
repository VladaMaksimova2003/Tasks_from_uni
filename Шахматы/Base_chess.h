#pragma once
#include <iostream>
#include <list>
using namespace std;
typedef struct Position
{
	int Coord_x;
	int Coord_y;
};

class Chess
{
protected:
	string type;
	string color;
	Position position;
	list <Position> possiblePosition;
	int board[8][8];
	bool CheckBoundry(Position position);
	bool doubleJump;

public:
	Chess();
	Chess(string type, string color, Position position);
	virtual ~Chess();
	void Draw();
	//void SetPosition(Position position);
	list <Position> GetPossiblePosition();
	//методы, позволяющие читать координаты возможного перемещения фигуры по доске;

	Position Getposition();
	//методы, позволяющие читать координаты расположения фигуры на доске; 

	string GetColor();
	virtual bool ValidateMove(Position moveToPosition) = 0;
	virtual void InitializeFigure() = 0;
	//методы, позволяющие устанавливать фигуры в исходное положение;

	virtual bool SetAccordingRules(Position toPos) = 0;
	//методы, позволяющие перемещать фигуру по доске в соответствии с правилами;

	void Draw_board();
	virtual bool SetArbitraryPosition(Position toPos);
	//методы, позволяющие устанавливать фигуры в произвольное положение;
};

