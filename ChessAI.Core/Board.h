#include "Piece.h"
#include "PieceData.h"
#include "PossibleMoveData.h"
#include "BoardLookup.h"
#include "List.h"
#include "HashTable.h"
#include <functional>

#pragma once
class Board
{

public:

	Board();
	Board(BoardLookup& data);
	~Board();

public: 

	bool HasPiece(bool white, PieceId id) const;
	bool HasPiece(BYTE rank, BYTE file) const;

	PieceData GetPiece(bool white, PieceId id) const;
	PieceData GetPiece(BYTE rank, BYTE file) const;

	void MovePiece(bool white, PieceId id, BYTE rank, BYTE file);
	void CapturePiece(bool white, PieceId id);
	void PromotePiece(bool white, PieceId id, PieceCode promotedCode);

public:

	/// <summary>
	/// Returns all pieces still on the board
	/// </summary>
	List<PieceData> GetPiecesInPlay();

protected:

	// HashTable key selectors
	static unsigned long CreateIdHash(Piece* piece)   { return HashCode::CreateIdHash(piece->IsWhite(), piece->GetId()); }
	static unsigned long CreatePositionHash(Piece* piece) { return HashCode::CreatePositionHash(piece->GetRank(), piece->GetFile()); }

private:

	HashTable<Piece*>* _idLookup;
	HashTable<Piece*>* _positionLookup;

	List<Piece*>* _pieceList;
};

