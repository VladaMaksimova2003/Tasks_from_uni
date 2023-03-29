#include "Rook.h"
#include "Base_chess.h"


Rook::~Rook() {

}

void Rook::InitializeFigure() {
	if (color == "white") {
		Position whiteRook = { 7,0 };
		position = { 7,0 };
		board[whiteRook.Coord_y][whiteRook.Coord_x] = 1;
	}
	else {
		Position blackRook = { 0,7 };
		position = { 0,7 };
		board[blackRook.Coord_y][blackRook.Coord_x] = 1;
	}
}
bool Rook::ValidateMove(Position moveToPos) {

	bool validMove = false;
	//int allowableMove1 = 1;
	//int allowableMove2 = 2;

	//if (color == black) {
	//	allowableMove1 = -1;
	//	allowableMove2 = -2;
	//}

	//for(y = )
	//if (moveToPos.Coord_y == position.Coord_y + allowableMove1 && moveToPos.Coord_x == position.Coord_x && board[moveToPos.Coord_y][moveToPos.Coord_x] == 0) {
	//	validMove = true;
	//	break;
	//}
	//else if (moveToPos.Coord_y == (position.Coord_y + allowableMove2) && moveToPos.Coord_x == position.Coord_x
	//	&& board[moveToPos.Coord_y][moveToPos.Coord_x] == 0) {
	//	validMove = true;
	//	break;
	//}

	return validMove;
}

bool Rook::SetAccordingRules(Position toPos) {

	bool moveFlag = false;
	if (ValidateMove(toPos)) {
		board[toPos.Coord_y][toPos.Coord_x] = 1;
		board[position.Coord_y][position.Coord_x] = 0;
		position = { toPos.Coord_x, toPos.Coord_y };
		moveFlag = true;
	}
	return moveFlag;
}

bool Rook::SetArbitraryPosition(Position toPos) {

	bool moveFlag = false;
	if (board[toPos.Coord_y][toPos.Coord_x] != 0 && CheckBoundry(toPos)) {
		board[toPos.Coord_y][toPos.Coord_x] = 1;
		board[position.Coord_y][position.Coord_x] = 0;
		position = { toPos.Coord_x, toPos.Coord_y };

		moveFlag = true;
	}
	return moveFlag;
}