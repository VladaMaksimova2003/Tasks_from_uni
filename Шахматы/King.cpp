#include "King.h"
#include "Base_chess.h"

King::~King() {

}

void King::InitializeFigure() {
	if (color == "white") {
		Position whiteKing = { 4,0 };
		position = { 4,0 };
		board[whiteKing.Coord_y][whiteKing.Coord_x] = 1;
	}
	else {
		Position blackKing = { 4,7 };
		position = { 4,7 };
		board[blackKing.Coord_y][blackKing.Coord_x] = 1;
	}
}
bool King::ValidateMove(Position moveToPosition) {
	possiblePosition.clear();
	bool validMove = false;
	int allowableMove1 = 1;

	if (color == "black") {
		allowableMove1 = -1;
	}

	if (moveToPosition.Coord_y == position.Coord_y + allowableMove1 && moveToPosition.Coord_x == position.Coord_x && board[moveToPosition.Coord_y][moveToPosition.Coord_x] == 0) {
		validMove = true;
		possiblePosition.push_back({ position.Coord_x,position.Coord_y + allowableMove1 });
	}
	if (moveToPosition.Coord_y == position.Coord_y - allowableMove1 && moveToPosition.Coord_x == position.Coord_x && board[moveToPosition.Coord_y][moveToPosition.Coord_x] == 0) {
		validMove = true;
		possiblePosition.push_back({ position.Coord_x,position.Coord_y - allowableMove1 });
	}
	if (moveToPosition.Coord_x == position.Coord_x + allowableMove1 && moveToPosition.Coord_y == position.Coord_y && board[moveToPosition.Coord_y][moveToPosition.Coord_x] == 0) {
		validMove = true;
		possiblePosition.push_back({ position.Coord_x + allowableMove1 ,position.Coord_y});
	}
	if (moveToPosition.Coord_x == position.Coord_x - allowableMove1 && moveToPosition.Coord_y == position.Coord_y && board[moveToPosition.Coord_y][moveToPosition.Coord_x] == 0) {
		validMove = true;
		possiblePosition.push_back({ position.Coord_x - allowableMove1 ,position.Coord_y });
	}

	return validMove;
}

bool King::SetAccordingRules(Position toPos) {

	bool moveFlag = false;
	if (ValidateMove(toPos)) {
		board[toPos.Coord_y][toPos.Coord_x] = 1;
		board[position.Coord_y][position.Coord_x] = 0;
		position = { toPos.Coord_x, toPos.Coord_y };
		moveFlag = true;
	}
	return moveFlag;
}

bool King::SetArbitraryPosition(Position toPos) {

	bool moveFlag = false;
	if (board[toPos.Coord_y][toPos.Coord_x] != 0 && CheckBoundry(toPos)) {
		board[toPos.Coord_y][toPos.Coord_x] = 1;
		board[position.Coord_y][position.Coord_x] = 0;
		position = { toPos.Coord_x, toPos.Coord_y };

		moveFlag = true;
	}
	return moveFlag;
}