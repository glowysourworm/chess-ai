#pragma once
typedef unsigned char BYTE;

const BYTE RANK_1 = 1;
const BYTE RANK_2 = 2;
const BYTE RANK_3 = 3;
const BYTE RANK_4 = 4;
const BYTE RANK_5 = 5;
const BYTE RANK_6 = 6;
const BYTE RANK_7 = 7;
const BYTE RANK_8 = 8;
const BYTE RANK_SIZE = RANK_8;

const BYTE FILE_A = 1;
const BYTE FILE_B = 2;
const BYTE FILE_C = 3;
const BYTE FILE_D = 4;
const BYTE FILE_E = 5;
const BYTE FILE_F = 6;
const BYTE FILE_G = 7;
const BYTE FILE_H = 8;
const BYTE FILE_SIZE = FILE_H;

const unsigned short VALUE_PAWN = 10;
const unsigned short VALUE_KNIGHT = 30;
const unsigned short VALUE_BISHOP = 30;
const unsigned short VALUE_ROOK = 50;
const unsigned short VALUE_QUEEN = 90;
const unsigned short VALUE_KING = 900;

enum class PieceCode {
	Pawn = 0,
	Knight = 1,
	Bishop = 2,
	Rook = 3,
	Queen = 4,
	King = 5
};

enum class PieceId {
	QueenRook = 0,
	QueenKnight = 1,
	QueenBishop = 2,
	Queen = 3,

	King = 4,
	KingBishop = 5,
	KingKnight = 6,
	KingRook = 7,

	QueenRookPawn = 8,
	QueenKnightPawn = 9,
	QueenBishopPawn = 10,
	QueenPawn = 11,

	KingPawn = 12,
	KingBishopPawn = 13,
	KingKnightPawn = 14,
	KingRookPawn = 15
};

/// <summary>
/// Result code for a human-made turn (or from a chess script)
/// </summary>
enum class TurnResultCode {

	/// <summary>
	/// Error when trying to move piece not related to the move
	/// </summary>
	GeneralError = 0,

	/// <summary>
	/// Returned with MoveResult when the wrong color was expected on a turn
	/// </summary>
	WrongColorTurn = 1,

	/// <summary>
	/// No piece was located at the source square
	/// </summary>
	NoPiece = 2,

	/// <summary>
	/// Move was blocked by a piece from the same color
	/// </summary>
	MoveBlockedSameColor = 3,

	/// <summary>
	/// Move was blocked by a piece from the opposing color
	/// </summary>
	MoveBlockedOpposingColor = 4,

	/// <summary>
	/// Move is not possible for the chosen piece
	/// </summary>
	IllegalMove = 5,

	/// <summary>
	/// Castle is not currently possible or blocked
	/// </summary>
	IllegalCastle = 6,

	/// <summary>
	/// Can't move because currently in check
	/// </summary>
	IllegalMoveCheck = 7,

	/// <summary>
	/// Move was successful
	/// </summary>
	Success = 8
};