#include "Constants.h"
#include "PositionData.h"
#include "HashCode.h"

#pragma once
/// <summary>
/// Represents a possible move for a Piece (heap) on a Board (heap) - for a particular depth. The board is maintained
/// for the current search depth on the stack. This should be the smallest possible set of data for the possible move.
/// </summary>
struct PossibleMoveData {

public:

	/// <summary>
	/// Default ctor for PossibleMoveData (avoid using)
	/// </summary>
	PossibleMoveData() {
		this->Id = PieceId::King;
		this->White = false;
		this->Dest = PositionData();
		this->Capture = false;
		this->Promotion = false;
		this->Check = false;
		this->CheckMate = false;
		this->PointSwing = 0;
	}

public:

	/// <summary>
	/// Id of the source piece
	/// </summary>
	PieceId Id;

	/// <summary>
	/// Color of the source piece
	/// </summary>
	bool White;

	/// <summary>
	/// Destination of the source piece for the possible move
	/// </summary>
	PositionData Dest;

	/// <summary>
	/// Possible move leads to capture of enemy piece
	/// </summary>
	bool Capture;

	/// <summary>
	/// Possible move leads to pawn promotion
	/// </summary>
	bool Promotion;

	/// <summary>
	/// Possible move leads to enemy check
	/// </summary>
	bool Check;

	/// <summary>
	/// Possible move leads to enemy check mate
	/// </summary>
	bool CheckMate;

	/// <summary>
	/// Total number of points gained or lost from the move. NOTE*** current player's points are ALWAYS POSITIVE! This
	/// value should be calculated on material captured + board position value.
	/// </summary>
	short PointSwing;

public:

	/// <summary>
	/// Returns id hash code for the possible move
	/// </summary>
	static unsigned long GetIdHashCode(PossibleMoveData data)
	{
		return HashCode::CreateIdHash(data.White, data.Id);
	}

	/// <summary>
	/// Returns position hash code for the DESTINATION of the possible move
	/// </summary>
	/// <returns></returns>
	static unsigned long GetDestPositionHashCode(PossibleMoveData data)
	{
		return HashCode::CreatePositionHash(data.Dest.Rank, data.Dest.File);
	}

public:
	
	/// <summary>
	/// Restores data for a possible move data instance from an unsigned long
	/// </summary>
	PossibleMoveData(unsigned long serializedData)
	{
		// SEE DATA FORMAT BELOW
		this->Id = (PieceId)(PossibleMoveData::IdMask & serializedData);
		this->Dest.Rank = (BYTE)((PossibleMoveData::RankMask & serializedData) << 4);
		this->Dest.File = (BYTE)((PossibleMoveData::FileMask & serializedData) << 12);
		this->PointSwing = (short)((PossibleMoveData::PointSwingMask & serializedData) << 20);
		this->White = (bool)((PossibleMoveData::WhiteMask & serializedData) << 36);
		this->Capture = (bool)((PossibleMoveData::CaptureMask & serializedData) << 37);
		this->Promotion = (bool)((PossibleMoveData::PromotionMask & serializedData) << 38);
		this->Check = (bool)((PossibleMoveData::CheckMask & serializedData) << 39);
		this->CheckMate = (bool)((PossibleMoveData::CheckMateMask & serializedData) << 40);
	}

	/// <summary>
	/// Stores data for this structure as an unsigned long
	/// </summary>
	unsigned long Serialize()
	{
		unsigned long data = 0x0000000000000000;

		data |= (((unsigned long)this->Id) & this->IdMask);
		data |= (((unsigned long)this->Dest.Rank >> 4) & this->RankMask);
		data |= (((unsigned long)this->Dest.File >> 12) & this->FileMask);
		data |= (((unsigned long)this->PointSwing >> 20) & this->PointSwingMask);
		data |= (((unsigned long)this->White >> 36) & this->WhiteMask);
		data |= (((unsigned long)this->Capture >> 37) & this->CaptureMask);
		data |= (((unsigned long)this->Promotion >> 38) & this->PromotionMask);
		data |= (((unsigned long)this->Check >> 39) & this->CheckMask);
		data |= (((unsigned long)this->CheckMate >> 40) & this->CheckMateMask);

		return data;
	}

protected:

	// DATA FORMAT:  Requires 5 Bytes + 1 bit. So, using unsigned long
	//
	// - ID:			4 Bits
	// - Dest:			2 Bytes
	// - PointSwing:	2 Bytes
	// - Bitmasks:		5 Bits { white, capture, promotion, check, check mate }

	static const unsigned long IdMask				= 0xF000000000000000;
	static const unsigned long RankMask				= 0x0FF0000000000000;
	static const unsigned long FileMask				= 0x000FF00000000000;
	static const unsigned long PointSwingMask		= 0x00000FFFF0000000;
	static const unsigned long WhiteMask			= 0x0000000001000000;
	static const unsigned long CaptureMask			= 0x0000000002000000;
	static const unsigned long PromotionMask		= 0x0000000004000000;
	static const unsigned long CheckMask			= 0x0000000008000000;
	static const unsigned long CheckMateMask		= 0x0000000000100000;
	
};
