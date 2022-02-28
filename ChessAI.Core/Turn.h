#include "Constants.h"
#include "Piece.h"

#pragma once
class Turn {

private:
	TurnResultCode _code;

	unsigned short _rank1;
	unsigned short _file1;

	unsigned short _rank2;
	unsigned short _file2;

	PieceId _sourcePieceId;
	PieceId _capturedPieceId;

	bool _whiteTurn;
	bool _pieceCaptured;
	bool _piecePromotion;
	bool _castleQueenSide;
	bool _castleKingSide;
};