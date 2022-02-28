#include "Constants.h"
#include "HashTable.h"
#include "Piece.h"
#include "PieceData.h"
#include "PossibleMoveData.h"

#pragma once
class PossibleMoveLookup
{
public:

	PossibleMoveLookup();
	~PossibleMoveLookup();

	/// <summary>
	/// THROWS EXCEPTION:  If move for piece already exists. Otherwise, adds move for  piece
	/// to the lookup
	/// </summary>
	void Add(PieceData data, PossibleMoveData move);

	/// <summary>
	/// Returns true if the piece has a possible move to the specified square
	/// </summary>
	bool HasMove(PieceData data, BYTE rank, BYTE file);

	/// <summary>
	/// THROWS EXCEPTION: When possible move is not found! Returns possible move data for the 
	/// specified piece to the specified square. 
	/// </summary>
	PossibleMoveData GetMove(PieceData data, BYTE rank, BYTE file);

	/// <summary>
	/// THROWS EXCEPTION: When no possible moves are found! Returns ALL possible move data for the 
	/// specified piece to other squares on the board.
	/// </summary>
	List<PossibleMoveData> GetMoves(PieceData data);

	/// <summary>
	/// Returns ALL moves for ALL pieces in the lookup
	/// </summary>
	List<PossibleMoveData> GetAllMoves();

protected:

	/// <summary>
	/// The maximum total number of moves for any potential piece (exceeds necessary limit!). This 
	/// could easily be optimized; but the memory savings may not matter until the data is kept 
	/// DESERIALIZED in memory. This data structure will only be de-compressed for a small amount
	/// of stack calls.
	/// </summary>
	const int MaximumPossibleMoveCount = 63;

private:

	// BOARD-LIKE LOOKUP:
	// 	 
	// Piece in play -> (rank, file) index for the array[8][8] of HashTable<PossibleMoveData> which
	//					contains all possible moves INDEXED BY POSITION
	//
	// Example:  Get move BOARD for piece at POSITION (rank, file). Returns a BOARD-LIKE hash table
	//			 with position indices.. Like:  _moveLookup[rank - 1, file - 1]->Get("hash code for other position") 
	//			 returns a PossibleMoveData instance.
	// 	   
	//			 Can also just call _moveLookup[rank - 1, file - 1]->GetItems() for ALL potential
	// 			 moves; but this would end up being more expensive.
	//
	HashTable<PossibleMoveData>** _moveLookup;

	// PIECE-LOOKUP: Hashed by Id (PIECES IN PLAY)
	//
	HashTable<PieceData>* _pieceTable;
};

