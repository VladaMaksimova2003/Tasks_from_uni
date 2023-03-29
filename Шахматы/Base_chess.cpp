#include "Base_chess.h"

Chess::Chess(){
	type = " ";
    color = "white";
    position = {0,0};
    possiblePosition.push_back({ 0, 0 });
    doubleJump = true;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++)
            board[col][row] = 0;
    }
}

Chess::Chess(string type, string color, Position position) {
    this->type = type;
    this->color = color;
    this->position = position;
}

Chess::~Chess() {}

void Chess::Draw()
{
	if (color == "black") cout << "b";
	else cout << "w";
	cout << type;
}

//void Chess::SetPosition(Position position)
//{
//	this->position = position;
//}

list <Position> Chess::GetPossiblePosition()
{
    return possiblePosition;
}

Position Chess::Getposition()
{
    return position;
}

string Chess::GetColor()
{
	return color;
}


bool Chess::CheckBoundry(Position position) {
    if ((0 <= position.Coord_x && position.Coord_x <= 7) && (0 <= position.Coord_y && position.Coord_y <= 7)) {
        return true;
    }

    return false;
}

void Chess::Draw_board() {
    for (int row = 7; row >= 0; row--) {

        // Draws Horizontal Row Dividers
        cout << "   ";
        for (int col = 0; col < 8; col++) {
            cout << "-----";
        }
        cout << "-" << endl;


        // Draws Vertical Row Divider and Chess Piece
        cout << row + 1 << "  ";
        for (int col = 0; col < 8; col++) {
            cout << "| ";
            if (board[row][col] != 0) {
                Draw();
            }
            else {
                cout << "  ";
            }
            cout << " ";
        }

        // Draws Divider for end of Row
        cout << "|" << endl;

    }

    // Draws Horitonal Divider for last Row
    cout << "   ";
    for (int col = 0; col < 8; col++) {
        cout << "-----";
    }
    cout << "-" << endl;

    // Draws Letters on botton of board
    cout << "   ";
    for (int col = 0; col < 8; col++) {
        cout << "  " << (char)(col + 97) << "  ";
    }
    cout << endl << endl;

}