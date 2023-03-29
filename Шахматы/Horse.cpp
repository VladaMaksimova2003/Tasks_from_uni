#include "Horse.h"
#include "Base_chess.h"

Knight::~Knight() {

}


void Knight::InitializeFigure() {
	if (color == "white") {
		Position whiteKnight = { 6,0 };
		position = { 6,0 };
		board[whiteKnight.Coord_y][whiteKnight.Coord_x] = 1;
	}
	else {
		Position blackKnight = { 1,7 };
		position = { 1,7 };
		board[blackKnight.Coord_y][blackKnight.Coord_x] = 1;
	}
}
bool Knight::ValidateMove(Position moveToPos) {

	return false;
}

bool Knight::SetAccordingRules(Position toPos) {

	bool moveFlag = false;
	if (ValidateMove(toPos)) {
		board[toPos.Coord_y][toPos.Coord_x] = 1;
		board[position.Coord_y][position.Coord_x] = 0;
		position = { toPos.Coord_x, toPos.Coord_y };
		moveFlag = true;
	}
	return moveFlag;
}

bool Knight::SetArbitraryPosition(Position toPos) {

	bool moveFlag = false;
	if (board[toPos.Coord_y][toPos.Coord_x] != 0 && CheckBoundry(toPos)) {
		board[toPos.Coord_y][toPos.Coord_x] = 1;
		board[position.Coord_y][position.Coord_x] = 0;
		position = { toPos.Coord_x, toPos.Coord_y };

		moveFlag = true;
	}
	return moveFlag;
}