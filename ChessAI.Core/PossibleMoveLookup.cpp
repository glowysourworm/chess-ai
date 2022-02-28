#include "PossibleMoveLookup.h"

PossibleMoveLookup::PossibleMoveLookup()
{
	_moveLookup = new HashTable<PossibleMoveData>*[8];
	_pieceTable = new HashTable<PieceData>(32, PieceData::GetIdHashCode);

	// Create hash table hashed by DESTINATION for the possible move
	for (int index = 0; index < 8; index++)
		_moveLookup[index] = new HashTable<PossibleMoveData>(this->MaximumPossibleMoveCount, PossibleMoveData::GetDestPositionHashCode);
}
PossibleMoveLookup::~PossibleMoveLookup()
{
	for (int index = 0; index < 8; index++)
		delete _moveLookup[index];

	delete[] _moveLookup;
	delete _pieceTable;
}

void PossibleMoveLookup::Add(PieceData data, PossibleMoveData move)
{
	if (data.isCaptured)
		throw std::exception("Trying to add possible move for captured piece");

	bool hasMove = this->HasMove(data, move.Dest.Rank, move.Dest.File);

	if (hasMove)
		throw std::exception("Trying to add duplicate move to the PossibleMoveLookup");

	// Check for new piece
	if (!_pieceTable->Contains(data))
		_pieceTable->Add(data);

	// ADD MOVE TO:  HashTable at the PIECE'S POSITION for the possible move
	if (_moveLookup[data.rank - 1][data.file - 1].Contains(move))
		_moveLookup[data.rank - 1][data.file - 1].Add(move);

	else
		throw std::exception("Unknown error:  PossibleMoveLookup::Add found existing move");
}

bool PossibleMoveLookup::HasMove(PieceData data, BYTE rank, BYTE file)
{
	if (!_pieceTable->Contains(data))
		return false;

	else if (!_moveLookup[data.rank - 1][data.file - 1].ContainsKey(HashCode::CreatePositionHash(rank, file)))
		return false;

	return true;
}

PossibleMoveData PossibleMoveLookup::GetMove(PieceData data, BYTE rank, BYTE file)
{
	bool hasMove = this->HasMove(data, rank, file);

	if (hasMove)
		throw std::exception("Trying to get non-existing possible move");

	return _moveLookup[data.rank - 1][data.file - 1].Get(HashCode::CreatePositionHash(rank, file));
}

List<PossibleMoveData> PossibleMoveLookup::GetMoves(PieceData data)
{
	if (_pieceTable->Contains(data))
		throw std::exception("Trying to get possible moves for non-existing piece");

	return _moveLookup[data.rank - 1][data.file - 1].GetItems();
}

List<PossibleMoveData> PossibleMoveLookup::GetAllMoves()
{
	List<PieceData> pieces = _pieceTable->GetItems();
	
	// CONST REQUIRED FOR STACK ALLOCATION:  Max-capacity for ALL POSSIBLE MOVES for ALL POSSIBLE PIECES
	const int maxCapacity = 32 * 64;

	PossibleMoveData allMoves[maxCapacity];
	int counter = 0;

	for (int pieceIndex = 0; pieceIndex < pieces.Count(); pieceIndex++)
	{
		// Piece to fetch and store moves for the result
		PieceData data = pieces.Get(pieceIndex);

		// Get all moves for the piece
		List<PossibleMoveData> moves = _moveLookup[data.rank - 1][data.file - 1].GetItems();

		// Add moves to stack-allocated array
		for (int moveIndex = 0; moveIndex < moves.Count(); moveIndex++)
		{
			if (counter + 1 >= maxCapacity)
				throw std::exception("Max capacity of internal stack array exceeded:  PossibleMoveLookup::GetAllMoves");

			allMoves[counter++] = moves.Get(moveIndex);
		}
	}

	// Create result list trimmed off from the original
	return List<PossibleMoveData>(allMoves, counter);
}