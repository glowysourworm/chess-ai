#include "BoardLookup.h"

BoardLookup::BoardLookup(List<PieceData>& piecesInPlay, List<PossibleMoveData>& possibleMoves)
{
	this->Pieces = new HashTable<PieceData>(piecesInPlay.Count(), PieceData::GetIdHashCode);
	this->PossibleMoves = new PossibleMoveLookup();
}

BoardLookup::~BoardLookup()
{
	delete this->Pieces;
	delete this->PossibleMoves;
}

BoardLookup::BoardLookup(std::istream& stream)
{
	// DATA FORMAT:
	//
	// - Piece Count:		   int (4 Bytes)
	// - Possible Move Count:  int (4 Bytes)
	// - Piece[]:			   Variable (N x sizeof(PieceData))
	// - PossibleMoveData[]:   Variable (M x sizeof(PossibleMoveData))
	//

	int pieceCount;
	int possibleMoveCount;

	stream >> pieceCount;
	stream >> possibleMoveCount;

	// Stack allocated lists for reading data
	List<PieceData> pieces = List<PieceData>(pieceCount);
	List<PossibleMoveData> possibleMoves = List<PossibleMoveData>(possibleMoveCount);

	// Piece[]
	for (int index = 0; index < pieceCount; index++)
	{
		unsigned int data;

		stream >> data;

		// DECOMPRESS: Deserialize data from the stream
		pieces.Add(PieceData(data));
	}

	// PossibleMoveData[]
	for (int index = 0; index < possibleMoveCount; index++)
	{
		unsigned long data;

		stream >> data;

		// DECOMPRESS: Deserialize data from the stream
		possibleMoves.Add(PossibleMoveData(data));
	}

	// INSTANTIATE DATA STRUCTURES
	this->Pieces = new HashTable<PieceData>(pieces.Count(), PieceData::GetIdHashCode);
	this->PossibleMoves = new PossibleMoveLookup();

	this->Initialize(pieces, possibleMoves);
}

void BoardLookup::Initialize(List<PieceData>& piecesInPlay, List<PossibleMoveData>& possibleMoves)
{
	if (this->Pieces == nullptr ||
		this->PossibleMoves == nullptr)
		throw std::exception("Null reference exception BoardLookup::Initialize");

	for (int index = 0; index < possibleMoves.Count(); index++)
	{
		PossibleMoveData move = possibleMoves.Get(index);

		// Calculate hash code for the piece by ID
		unsigned long key = HashCode::CreateIdHash(move.White, move.Id);

		// THROWS EXCEPTION: When piece doesn't exist. Look up the piece data from those passed in
		PieceData data = this->Pieces->Get(key);

		// Add piece data + possible move data to the data structure
		this->PossibleMoves->Add(data, move);
	}
}

	/// <summary>
	/// Serializes board data to the supplied stream
	/// </summary>
std::ostream& BoardLookup::Serialize(std::ostream& stream)
{
	// DATA FORMAT:
	//
	// - Piece Count:		   int (4 Bytes)
	// - Possible Move Count:  int (4 Bytes)
	// - Piece[]:			   Variable (N x sizeof(PieceData))
	// - PossibleMoveData[]:   Variable (M x sizeof(PossibleMoveData))
	//

	// Get all possible moves as a list (SUPPOSED TO BE ON THE STACK)
	List<PossibleMoveData> possibleMoves = this->PossibleMoves->GetAllMoves();

	stream << this->Pieces->Count();
	stream << possibleMoves.Count();

	// Piece[]
	for (int index = 0; index < this->Pieces->Count(); index++)
	{
		// COMPRESS:  PieceData to int
		stream << this->Pieces->Get(index).Serialize();
	}

	// PossibleMoveData[]
	for (int index = 0; index < possibleMoves.Count(); index++)
	{
		// COMPRESS:  PossibleMoveData to unsigned long
		stream << possibleMoves.Get(index).Serialize();
	}

	return stream;
}