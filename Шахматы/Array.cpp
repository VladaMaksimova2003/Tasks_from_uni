#include "Array.h"
#include "Horse.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"

enum { N, R, K, P};

ArrShapes::ArrShapes() 
{ Arr = 0; Len = 0; }

ArrShapes::ArrShapes(const ArrShapes& A)
{
	Arr = 0;
	Len = 0;
	operator=(A);
}

UINT ArrShapes::GetSize() 
{ return Len; }

void ArrShapes::SetSize(UINT l)
{
	Clear();
	Len = l;
	Arr = new Chess * [Len];
	for (UINT i = 0; i < Len; i++)
		Arr[i] = 0;
}

void ArrShapes::Clear()
{
	if (Arr)
	{
		for (UINT i = 0; i < Len; i++)
			if (Arr[i]) delete Arr[i];
		delete[] Arr;
		Arr = 0;
		Len = 0;
	}
}

void ArrShapes::SetType(UINT i, UINT type)
{
	if (type >= 4) throw 11;
	if (i < Len)
	{
		if (Arr[i])
			delete Arr[i];
		switch (type)
		{
		case N:
			Arr[i] = new Knight;
			break;
		case R:
			Arr[i] = new Rook;
			break;
		case K:
			Arr[i] = new King;
			break;
		case P:
			Arr[i] = new Pawn;
			break;
		}
	}
	else
		throw 10;
}

UINT ArrShapes::GetType(UINT i)
{
	Chess* s;
	if (s = dynamic_cast<Knight*>(Arr[i])) return N;
	if (s = dynamic_cast<Rook*>(Arr[i])) return R;
	if (s = dynamic_cast<King*>(Arr[i])) return K;
	if (s = dynamic_cast<Pawn*>(Arr[i])) return P;
	throw 13; // Неизвестный тип
}

ArrShapes::ArrShapes(UINT len)
{
	Arr = 0;
	Len = 0;
	SetSize(len);
}

ArrShapes& ArrShapes::operator=(const ArrShapes& A)
{
	if (this == &A) return *this;
	Clear();
	SetSize(A.Len);
	for (UINT i = 0; i < Len; i++)
	{ 
		SetType(i, A.GetType(i));
		*(Arr[i]) = *(A.Arr[i]);
	}
	return *this;
}

Chess* ArrShapes::operator[](UINT i)
{
	if (i < Len)
	{
		if (Arr[i])
			return Arr[i];
		throw 12;
	}
	throw 10;
}


