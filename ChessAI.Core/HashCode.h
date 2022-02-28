#include "Constants.h"

#pragma once
struct HashCode {

	/// <summary>
	/// ID HASH CODE: Static hash code method for Piece* or PieceData. Identifies pieces by ID + color
	/// </summary>
	static unsigned long CreateIdHash(bool white, PieceId id)
	{
		// FORMAT:
		//
		// - PieceId:  4 Bits
		// - White:    1 Bit

		unsigned long data = 0;

		data |= ((BYTE)id & 0xF0000000);
		data |= ((BYTE)white >> 4) & 0x01000000;

		return data;
	}

	/// <summary>
	/// POSITION HASH CODE: Static hash code method for Piece* or PieceData. Identifies pieces by RANK + FILE
	/// </summary>
	static unsigned long CreatePositionHash(BYTE rank, BYTE file)
	{
		// FORMAT:
		//
		// - Rank:  1 Byte
		// - File:  1 Byte

		unsigned long data = 0;

		data |= (rank & 0xFF000000);
		data |= (file >> 8) & 0x00FF0000;

		return data;
	}

};