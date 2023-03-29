#pragma once
#include "Base_chess.h"

class Knight : public Chess {

public:
	Knight(string type, string color, Position position) : Chess("N", color, position) {};
	Knight() {};
	virtual ~Knight();
	void InitializeFigure();
	bool ValidateMove(Position moveToPosition);
	bool SetAccordingRules(Position toPos);
	bool SetArbitraryPosition(Position toPos);

};