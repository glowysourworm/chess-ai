#include "BoardCalculator.h"

BoardLookup* BoardCalculator::CalculateLookup(const Board& board)
{
	// Look for pieces on the board -> Calculate possible moves
	for (BYTE rankIndex = 0; rankIndex < RANK_SIZE; rankIndex++)
	{
		for (BYTE fileIndex = 0; fileIndex < FILE_SIZE; fileIndex++)
		{
			if (board.HasPiece(rankIndex + 1, fileIndex + 1))
			{
				// CREATE PieceData structure
				PieceData data = board.GetPiece(rankIndex + 1, fileIndex + 1);

				// CALCULATE POSSIBLE MOVES FOR PIECE
				List<PossibleMoveData> moves = BoardCalculator::CalculatePossibleMoves(board, rankIndex + 1, fileIndex + 1);
			}
		}
	}
}

List<PossibleMoveData> BoardCalculator::CalculatePossibleMoves(const Board& board, BYTE rank, BYTE file)
{
	
}