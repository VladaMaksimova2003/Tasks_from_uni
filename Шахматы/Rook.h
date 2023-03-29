#pragma once
#include "Base_chess.h"

class Rook : public Chess {

public:
	Rook(string type, string color, Position position) : Chess("R", color, position) {};
	Rook() {};
	virtual ~Rook();
	void InitializeFigure();
	bool ValidateMove(Position moveToPosition);
	bool SetAccordingRules(Position toPos);
	bool SetArbitraryPosition(Position toPos);
};