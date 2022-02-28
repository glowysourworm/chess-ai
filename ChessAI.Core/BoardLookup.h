#include "PieceData.h"
#include "PossibleMoveData.h"
#include "PossibleMoveLookup.h"
#include "List.h"
#include "OrderedList.h"
#include "HashTable.h"
#include "HashCode.h"
#include <ostream>
#include <istream>

#pragma once

/// <summary>
/// Class to represent-and-store the piece data + the possible moves for a particular board configuration. Also,
/// calculates a hash code for the total data structure to be saved on a hash table.
/// </summary>
class BoardLookup
{
public:

	BoardLookup(List<PieceData>& piecesInPlay, List<PossibleMoveData>& possibleMoves);

	~BoardLookup();

	/// <summary>
	/// Creates a new instance of BoardData from the input stream
	/// </summary>
	/// <param name="stream"></param>
	BoardLookup(std::istream& stream);	

	/// <summary>
	/// Serializes board data to the supplied stream
	/// </summary>
	std::ostream& Serialize(std::ostream& stream);

protected:

	/// <summary>
	/// Initializes data structre from supplied (ctor) data
	/// </summary>
	void Initialize(List<PieceData>& piecesInPlay, List<PossibleMoveData>& possibleMoves);

public:

	/// <summary>
	/// Ordered list of pieces in play
	/// </summary>
	HashTable<PieceData>* Pieces;

	/// <summary>
	/// Lookup of all possible moves for pieces in play
	/// </summary>
	PossibleMoveLookup* PossibleMoves;
};

