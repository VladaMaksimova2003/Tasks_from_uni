#pragma once
#include "Base_chess.h"

class King : public Chess {

public:
	King(string type, string color, Position position) : Chess("K", color, position) {};
	King() {};
	void InitializeFigure();
	bool ValidateMove(Position moveToPosition);
	bool SetAccordingRules(Position toPos);
	bool SetArbitraryPosition(Position toPos);
};
