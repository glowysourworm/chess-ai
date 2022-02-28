#include "..\\ChessAI.Core\Constants.h"

#pragma once
namespace CoreAdapter
{
	/// <summary>
	/// Core constants translated into chess coordinates. Should pertain to playing
	/// the actual game and not to any arrays or indexes.
	/// </summary>
	public ref class ChessConstants
	{
	public:
		static const unsigned short Rank1 = RANK_1;
		static const unsigned short Rank2 = RANK_2;
		static const unsigned short Rank3 = RANK_3;
		static const unsigned short Rank4 = RANK_4;
		static const unsigned short Rank5 = RANK_5;
		static const unsigned short Rank6 = RANK_6;
		static const unsigned short Rank7 = RANK_7;
		static const unsigned short Rank8 = RANK_8;

		static const unsigned short FileA = FILE_A;
		static const unsigned short FileB = FILE_B;
		static const unsigned short FileC = FILE_C;
		static const unsigned short FileD = FILE_D;
		static const unsigned short FileE = FILE_E;
		static const unsigned short FileF = FILE_F;
		static const unsigned short FileG = FILE_G;
		static const unsigned short FileH = FILE_H;
	};

	// ****** COPIED FROM CORE LIB

	public enum class ChessPieceCode {
		Pawn = 0,
		Knight = 1,
		Bishop = 2,
		Rook = 3,
		Queen = 4,
		King = 5
	};

	public enum class ChessPieceId {
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

	public enum class ChessMoveResultCode {

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
}