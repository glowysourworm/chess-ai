#include "Constants.h"
#include "Board.h"
#include "BoardLookup.h"
#include "PossibleMoveData.h"
#include "List.h"

#pragma once
static class BoardCalculator
{
public:

	/// <summary>
	/// Returns heap allocated data structrue for serializing to memory or file
	/// </summary>
	static BoardLookup* CalculateLookup(const Board& board);

protected:

	/// <summary>
	/// Calculates possible moves for the specified piece
	/// </summary>
	static List<PossibleMoveData> CalculatePossibleMoves(const Board& board, BYTE rank, BYTE file);
};

