#include "Base_chess.h"
#include "Pawn.h"


Pawn::~Pawn() {

}

void Pawn::InitializeFigure() {
    if (color == "white") {
        Position whitePawn = { 0,6 };
        position = { 0,6 };
        board[whitePawn.Coord_y][whitePawn.Coord_x] = 1;
    }
    else {
        Position blackPawn = { 0,1 };
        position = { 0,1 };
        board[blackPawn.Coord_y][blackPawn.Coord_x] = 1;
    }
}

bool Pawn::ValidateMove(Position moveToPositionition) {
    possiblePosition.clear();
    bool validMove = false;
    int allowableMove1 = 1;
    int allowableMove2 = 2;

    if (color == "black") {
        allowableMove1 = -1;
        allowableMove2 = -2;
    }

    if (moveToPositionition.Coord_y == position.Coord_y + allowableMove1 && moveToPositionition.Coord_x == position.Coord_x && board[moveToPositionition.Coord_y][moveToPositionition.Coord_x] == 0) {
        validMove = true;
        doubleJump = false;
        possiblePosition.push_back({ position.Coord_x,position.Coord_y + allowableMove1 });

    }
    if (doubleJump == true && moveToPositionition.Coord_y == (position.Coord_y + allowableMove2) && moveToPositionition.Coord_x == position.Coord_x
        && board[moveToPositionition.Coord_y][moveToPositionition.Coord_x] == 0) {
        validMove = true;
        doubleJump = false;
        possiblePosition.push_back({ position.Coord_x,position.Coord_y + allowableMove2 });
    }

    return validMove;
}

bool Pawn::SetAccordingRules(Position toPos) {

    bool moveFlag = false;
    if (ValidateMove(toPos)) {
        board[toPos.Coord_y][toPos.Coord_x] = 1;
        board[position.Coord_y][position.Coord_x] = 0;
        position = { toPos.Coord_x, toPos.Coord_y };
        moveFlag = true;
    }
    return moveFlag;
}

bool Pawn::SetArbitraryPosition(Position toPos) {

    bool moveFlag = false;
    if (board[toPos.Coord_y][toPos.Coord_x] != 0 && CheckBoundry(toPos)) {
        board[toPos.Coord_y][toPos.Coord_x] = 1;
        board[position.Coord_y][position.Coord_x] = 0;
        position = { toPos.Coord_x, toPos.Coord_y };

        moveFlag = true;
    }
    return moveFlag;
}