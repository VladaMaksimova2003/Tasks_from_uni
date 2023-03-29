#pragma once
#include "Base_chess.h"
#include "Horse.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"

typedef unsigned int UINT;
class ArrShapes
{
private:
	Chess** Arr;
	UINT Len;
public:
	ArrShapes();
	ArrShapes(UINT len);
	ArrShapes(const ArrShapes& A);
	~ArrShapes() { Clear(); }
	void SetSize(UINT l);
	UINT GetSize();
	void SetType(UINT i, UINT type);
	UINT GetType(UINT i);
	Chess* operator[](UINT i);
	ArrShapes& operator=(const ArrShapes& A);
	void Clear();
};