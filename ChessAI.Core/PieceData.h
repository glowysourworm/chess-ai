#include "Constants.h"
#include "Piece.h"

#pragma once

/// <summary>
/// Data structure used for a stack copy of the original piece memory allocated on the heap
/// </summary>
struct PieceData {
public:

	/// <summary>
	/// Used to signal a null reference or empty square
	/// </summary>
	bool EMPTY;

	unsigned short rank;
	unsigned short file;

	bool white;
	bool hasMoved;
	bool isPromoted;
	bool isCaptured;

	PieceId id;
	PieceCode code;
	PieceCode promotedCode;

public:

	/// <summary>
	/// Hash code function for hashing piece data structures by id + color
	/// </summary>
	static unsigned long GetIdHashCode(PieceData data)
	{
		return HashCode::CreateIdHash(data.white, data.id);
	}

	/// <summary>
	/// Comparer for two pieces that compares their hash codes for ordering purposes
	/// </summary>
	static int IdComparer(PieceData data1, PieceData data2)
	{
		unsigned long hash1 = GetIdHashCode(data1);
		unsigned long hash2 = GetIdHashCode(data2);

		// SECOND ITEM TAKES PRECEDENCE
		if (hash2 > hash1)
			return 1;

		else if (hash2 < hash1)
			return -1;

		else
			return 0;
	}

public:

	/// <summary>
	/// INITIALIZES EMPTY TO TRUE
	/// </summary>
	PieceData() { this->EMPTY = true; }

	PieceData(const Piece* piece)
	{
		this->EMPTY = false;
		this->rank = piece->GetRank();
		this->file = piece->GetFile();
		this->white = piece->IsWhite();
		this->hasMoved = piece->HasMoved();
		this->isPromoted = piece->IsPromoted();
		this->isCaptured = piece->IsCaptured();
		this->id = piece->GetId();
		this->code = piece->GetCode();
		this->promotedCode = piece->GetPromotedCode();
	}

	/// <summary>
	/// Restores data for a piece data instance from an unsigned int
	/// </summary>
	PieceData(unsigned int serializedData)
	{
		EMPTY = false;

		// SEE DATA FORMAT BELOW
		this->id = (PieceId)(PieceData::IdMask & serializedData);
		this->code = (PieceCode)((PieceData::CodeMask & serializedData) << 4);
		this->promotedCode = (PieceCode)((PieceData::PromotedCodeMask & serializedData) << 8);
		this->rank = (unsigned short)((PieceData::RankMask & serializedData) << 12);
		this->file = (unsigned short)((PieceData::FileMask & serializedData) << 16);
		this->white = (bool)((PieceData::WhiteMask & serializedData) << 20);
		this->hasMoved = (bool)((PieceData::HasMovedMask & serializedData) << 21);
		this->isPromoted = (bool)((PieceData::IsPromotedMask & serializedData) << 22);
		this->isCaptured = (bool)((PieceData::IsCapturedMask & serializedData) << 23);
	}

	/// <summary>
	/// Stores data for this structure as an unsigned int
	/// </summary>
	unsigned int Serialize()
	{
		unsigned int data = 0x00000000;

		data |= (((unsigned int)this->id) & this->IdMask);
		data |= (((unsigned int)this->code >> 4) & this->CodeMask);
		data |= (((unsigned int)this->promotedCode >> 8) & this->PromotedCodeMask);
		data |= (((unsigned int)this->rank >> 12) & this->RankMask);
		data |= (((unsigned int)this->file >> 16) & this->FileMask);
		data |= (((unsigned int)this->white >> 20) & this->WhiteMask);
		data |= (((unsigned int)this->hasMoved >> 21) & this->HasMovedMask);
		data |= (((unsigned int)this->isPromoted >> 22) & this->IsPromotedMask);
		data |= (((unsigned int)this->isCaptured >> 23) & this->IsCapturedMask);

		return data;
	}

protected:

	// DATA FORMAT:  Requires 24-bits. So, using unsigned int
	//
	// - ID:			4-bits
	// - Code:			3-bits (using 4)
	// - Promoted Code: 3-bits (using 4)
	// - Rank:			4-bits
	// - File:			4-bits
	// - Bitmasks:		{ white, has moved, is promoted, is captured }

	static const unsigned int IdMask = 0xF0000000;
	static const unsigned int CodeMask = 0x07000000;
	static const unsigned int PromotedCodeMask = 0x00700000;
	static const unsigned int RankMask = 0x000F0000;
	static const unsigned int FileMask = 0x0000F000;
	static const unsigned int WhiteMask = 0x00000100;
	static const unsigned int HasMovedMask = 0x00000200;
	static const unsigned int IsPromotedMask = 0x00000400;
	static const unsigned int IsCapturedMask = 0x00000800;
};