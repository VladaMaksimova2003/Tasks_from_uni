#pragma once
#include "Base_chess.h"

class Pawn : public Chess {

public:
	Pawn(string type, string color, Position position) : Chess("P", color, position) { };
	Pawn() {};
	virtual ~Pawn();
	void InitializeFigure();
	bool ValidateMove(Position moveToPosition);
	bool SetAccordingRules(Position toPos);
	bool SetArbitraryPosition(Position toPos);
};