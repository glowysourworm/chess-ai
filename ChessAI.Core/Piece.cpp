#include "Piece.h"

Piece::Piece(BYTE rank,
			 BYTE file,
			 bool white,
			 PieceCode code,
			 PieceId id)
{
	_white = white;
	_code = code;
	_id = id;
	_rank = rank;
	_file = file;

	_hasMoved = false;
	_isCaptured = false;
	_isPromoted = false;
	_promotedCode = PieceCode::Pawn;
}

Piece::Piece(PieceData data)
{
	_white = data.white;
	_code = data.code;
	_id = data.id;
	_rank = data.rank;
	_file = data.file;

	_hasMoved = data.hasMoved;
	_isCaptured = data.isCaptured;
	_isPromoted = data.isPromoted;
	_promotedCode = data.promotedCode;
}

void Piece::Move(BYTE rank, BYTE file)
{
	if (rank < RANK_1 ||
		rank > RANK_8 ||
		file < FILE_A ||
		file > FILE_H)
		throw std::exception("Invalid rank and file:  Piece::Move");

	_rank = rank;
	_file = file;

	_hasMoved = true;
}

void Piece::Promote(PieceCode code)
{
	if (code == PieceCode::Pawn)
		throw std::exception("Invalid promotion code Piece::Promote");

	_promotedCode = code;
	_isPromoted = true;
}

void Piece::Capture()
{
	if (_isCaptured)
		throw std::exception("Trying to re-capture piece");

	_isCaptured = true;
}

std::string Piece::GetDescription() const
{
	std::string color = _white ? "White" : "Black";
	std::string captured = _isCaptured ? " (captured)" : "";

	switch (_id)
	{
	case PieceId::QueenRook:
		return std::string(color + " Rook Queen-side" + captured);
	case PieceId::QueenKnight:
		return std::string(color + " Knight Queen-side" + captured);
	case PieceId::QueenBishop:
		return std::string(color + " Bishop Queen-side" + captured);
	case PieceId::Queen:
		return std::string(color + " Queen" + captured);
	case PieceId::King:
		return std::string(color + " King" + captured);
	case PieceId::KingBishop:
		return std::string(color + " Bishop King-side" + captured);
	case PieceId::KingKnight:
		return std::string(color + " Knight King-side" + captured);
	case PieceId::KingRook:
		return std::string(color + " Rook King-side" + captured);
	case PieceId::QueenRookPawn:
		return std::string(color + " Rook's Pawn Queen-side" + captured);
	case PieceId::QueenKnightPawn:
		return std::string(color + " Knight's Pawn Queen-side" + captured);
	case PieceId::QueenBishopPawn:
		return std::string(color + " Bishop's Pawn Queen-side" + captured);
	case PieceId::QueenPawn:
		return std::string(color + " Queen's Pawn" + captured);
	case PieceId::KingPawn:
		return std::string(color + " King's Pawn" + captured);
	case PieceId::KingBishopPawn:
		return std::string(color + " Bishop's Pawn King-side" + captured);
	case PieceId::KingKnightPawn:
		return std::string(color + " Knight's Pawn King-side" + captured);
	case PieceId::KingRookPawn:
		return std::string(color + " Rook's Pawn King-side" + captured);
	default:
		throw std::exception("Unhandled piece id:  Piece::GetDescription");
	}
}

unsigned short Piece::GetValue()
{
	PieceCode actualCode = _isPromoted ? _promotedCode : _code;

	switch (actualCode)
	{
	case PieceCode::Pawn:
		return VALUE_PAWN;
	case PieceCode::Knight:
		return VALUE_KNIGHT;
	case PieceCode::Bishop:
		return VALUE_BISHOP;
	case PieceCode::Rook:
		return VALUE_ROOK;
	case PieceCode::Queen:
		return VALUE_QUEEN;
	case PieceCode::King:
		return VALUE_KING;
	default:
		throw std::exception("Unhandled PieceCode Piece::GetValue()");
	}
}
