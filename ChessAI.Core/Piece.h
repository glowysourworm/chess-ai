#include "Constants.h"
#include <exception>
#include <string>

#pragma once
class Piece
{
public:

	Piece(BYTE rankData,
		  BYTE fileData,
		  bool whiteData,
		  PieceCode codeData,
		  PieceId idData);

	/// <summary>
	/// Creates piece from the piece data structure
	/// </summary>
	Piece(PieceData data);

public:
	PieceId GetId() const { return _id; }
	PieceCode GetCode() const { return _code; }
	PieceCode GetPromotedCode() const { return _promotedCode; }

	BYTE GetRank() const { return _rank; }
	BYTE GetFile() const { return _file; }
	bool IsWhite() const { return _white; }
	bool HasMoved() const { return _hasMoved; }
	bool IsPromoted() const { return _isPromoted; }
	bool IsCaptured() const { return _isCaptured; }

	std::string GetDescription() const;

public:

	/// <summary>
	/// Moves the piece to the new rank and file - throw std::exception if there is an out of bounds error
	/// </summary>
	void Move(BYTE rank, BYTE file);

	/// <summary>
	/// Promotes piece to a new type. Throws an exception if piece code is Pawn.
	/// </summary>
	void Promote(PieceCode code);

	/// <summary>
	/// Sets piece to captured
	/// </summary>
	void Capture();

public:

	unsigned short GetValue();

private:
	BYTE _rank;
	BYTE _file;

	bool _white;
	bool _hasMoved;
	bool _isPromoted;
	bool _isCaptured;

	PieceId _id;
	PieceCode _code;
	PieceCode _promotedCode;
};

