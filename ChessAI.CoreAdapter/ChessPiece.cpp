#include "ChessPiece.h"


CoreAdapter::ChessPiece::ChessPiece(int rank, int file, CoreAdapter::ChessPieceCode code, CoreAdapter::ChessPieceId id, bool white)
{
	this->Rank = rank;
	this->File = file;
	this->Code = code;
	this->Id = id;
	this->White = white;
}

String^ CoreAdapter::ChessPiece::ToString()
{
	if (this->White)
		return this->Id.ToString() + " - White";
	else
		return this->Id.ToString() + " - Black";
}