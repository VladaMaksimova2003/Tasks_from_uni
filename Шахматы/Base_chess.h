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
	//������, ����������� ������ ���������� ���������� ����������� ������ �� �����;

	Position Getposition();
	//������, ����������� ������ ���������� ������������ ������ �� �����; 

	string GetColor();
	virtual bool ValidateMove(Position moveToPosition) = 0;
	virtual void InitializeFigure() = 0;
	//������, ����������� ������������� ������ � �������� ���������;

	virtual bool SetAccordingRules(Position toPos) = 0;
	//������, ����������� ���������� ������ �� ����� � ������������ � ���������;

	void Draw_board();
	virtual bool SetArbitraryPosition(Position toPos);
	//������, ����������� ������������� ������ � ������������ ���������;
};

