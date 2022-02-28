#include "Board.h"

Board::Board()
{
	_idLookup = new HashTable<Piece*>(32, Board::CreateIdHash);
	_positionLookup = new HashTable<Piece*>(32, Board::CreatePositionHash);
	_pieceList = new List<Piece*>(32);

	// Stack array for all the piece pointers
	Piece* array[32]{};
	int counter = 0;

	// White
	array[counter++] = new Piece(RANK_1, FILE_A, true, PieceCode::Rook, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_1, FILE_B, true, PieceCode::Knight, PieceId::QueenKnight);
	array[counter++] = new Piece(RANK_1, FILE_C, true, PieceCode::Bishop, PieceId::QueenBishop);
	array[counter++] = new Piece(RANK_1, FILE_D, true, PieceCode::Queen, PieceId::Queen);
	array[counter++] = new Piece(RANK_1, FILE_E, true, PieceCode::King, PieceId::King);
	array[counter++] = new Piece(RANK_1, FILE_F, true, PieceCode::Bishop, PieceId::KingBishop);
	array[counter++] = new Piece(RANK_1, FILE_G, true, PieceCode::Knight, PieceId::KingKnight);
	array[counter++] = new Piece(RANK_1, FILE_H, true, PieceCode::Rook, PieceId::KingRook);

	array[counter++] = new Piece(RANK_2, FILE_A, true, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_2, FILE_B, true, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_2, FILE_C, true, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_2, FILE_D, true, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_2, FILE_E, true, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_2, FILE_F, true, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_2, FILE_G, true, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_2, FILE_H, true, PieceCode::Pawn, PieceId::QueenRook);

	// Black
	array[counter++] = new Piece(RANK_7, FILE_A, false, PieceCode::Rook, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_7, FILE_B, false, PieceCode::Knight, PieceId::QueenKnight);
	array[counter++] = new Piece(RANK_7, FILE_C, false, PieceCode::Bishop, PieceId::QueenBishop);
	array[counter++] = new Piece(RANK_7, FILE_D, false, PieceCode::Queen, PieceId::Queen);
	array[counter++] = new Piece(RANK_7, FILE_E, false, PieceCode::King, PieceId::King);
	array[counter++] = new Piece(RANK_7, FILE_F, false, PieceCode::Bishop, PieceId::KingBishop);
	array[counter++] = new Piece(RANK_7, FILE_G, false, PieceCode::Knight, PieceId::KingKnight);
	array[counter++] = new Piece(RANK_7, FILE_H, false, PieceCode::Rook, PieceId::KingRook);

	array[counter++] = new Piece(RANK_8, FILE_A, false, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_8, FILE_B, false, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_8, FILE_C, false, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_8, FILE_D, false, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_8, FILE_E, false, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_8, FILE_F, false, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_8, FILE_G, false, PieceCode::Pawn, PieceId::QueenRook);
	array[counter++] = new Piece(RANK_8, FILE_H, false, PieceCode::Pawn, PieceId::QueenRook);

	for (int index = 0; index < counter; index++)
	{
		Piece* piece = array[index];

		// Load hash tables
		_idLookup->Add(piece);
		_positionLookup->Add(piece);
		_pieceList->Add(piece);
	}
}
Board::Board(BoardLookup& lookup)
{
	_idLookup = new HashTable<Piece*>(32, Board::CreateIdHash);
	_positionLookup = new HashTable<Piece*>(32, Board::CreatePositionHash);
	_pieceList = new List<Piece*>(32);

	// Read data for the board
	for (int index = 0; index < lookup.Pieces->Count(); index++)
	{
		PieceData pieceData = lookup.Pieces->Get(index);

		// Heap-allocate piece
		Piece* piece = new Piece(pieceData);

		// Load hash tables
		_idLookup->Add(piece);
		_positionLookup->Add(piece);
		_pieceList->Add(piece);
	}
}
Board::~Board()
{
	delete _idLookup;
	delete _positionLookup;
	delete _pieceList;
}
bool Board::HasPiece(bool white, PieceId id) const
{
	// Create hash key
	unsigned long idHash = HashCode::CreateIdHash(white, id);

	return _idLookup->ContainsKey(idHash);
}
bool Board::HasPiece(BYTE rank, BYTE file) const
{
	// Create hash key
	unsigned long positionHash = HashCode::CreatePositionHash(rank, file);

	return _positionLookup->ContainsKey(positionHash);
}
PieceData Board::GetPiece(bool white, PieceId id) const
{
	// Create hash key
	unsigned long idHash = HashCode::CreateIdHash(white, id);

	// Load hash tables
	Piece* piecePtr = _idLookup->Get(idHash);

	return PieceData(piecePtr);
}
PieceData Board::GetPiece(BYTE rank, BYTE file) const
{
	// Create hash keys
	unsigned long positionHash = HashCode::CreatePositionHash(rank, file);

	// Load hash tables
	Piece* piecePtr = _positionLookup->Get(positionHash);

	return PieceData(piecePtr);
}

void Board::MovePiece(bool white, PieceId id, BYTE rank, BYTE file)
{
	// Create hash key
	unsigned long idHash = HashCode::CreateIdHash(white, id);

	// Lookup piece
	Piece* piecePtr = _idLookup->Get(idHash);

	if (piecePtr->IsCaptured())
	{
		std::string message = "Trying to move piece that is captured:  " + piecePtr->GetDescription();

		throw std::exception(message.c_str());
	}

	piecePtr->Move(rank, file);
}
void Board::CapturePiece(bool white, PieceId id)
{
	// Create hash key
	unsigned long idHash = HashCode::CreateIdHash(white, id);

	// Lookup piece
	Piece* piecePtr = _idLookup->Get(idHash);

	if (piecePtr->IsCaptured())
	{
		std::string message = "Trying to re-capture piece:  " + piecePtr->GetDescription();

		throw std::exception(message.c_str());
	}

	piecePtr->Capture();
}
void Board::PromotePiece(bool white, PieceId id, PieceCode promotedCode)
{
	// Create hash key
	unsigned long idHash = HashCode::CreateIdHash(white, id);

	// Lookup piece
	Piece* piecePtr = _idLookup->Get(idHash);

	if (piecePtr->IsCaptured())
	{
		std::string message = "Trying to promote captured piece:  " + piecePtr->GetDescription();

		throw std::exception(message.c_str());
	}

	if (piecePtr->GetCode() != PieceCode::Pawn)
	{
		std::string message = "Trying to promote non-pawn:  " + piecePtr->GetDescription();

		throw std::exception(message.c_str());
	}

	piecePtr->Promote(promotedCode);
}
List<PieceData> Board::GetPiecesInPlay()
{
	PieceData array[32];
	int counter = 0;

	for (int index = 0; index < _pieceList->Count(); index++)
	{
		if (!_pieceList->Get(index)->IsCaptured())
			array[counter++] = PieceData(_pieceList->Get(index));
	}

	return List<PieceData>(array, counter);
}