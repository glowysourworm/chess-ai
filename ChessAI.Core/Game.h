#include "Constants.h"
#include "Piece.h"
#include "Turn.h"
#include "List.h"
#include <vector>
#include <exception>
#include <ctime>

#pragma once
class Game
{
	Game();
	~Game();

	void Restart(bool force);

	GameStateCode GetState();
	bool GetWhitesTurn();

	Turn MovePiece(bool whiteMove, unsigned short rank1, unsigned short file1, unsigned short rank2, unsigned short file2);

	std::vector<Piece> GetWhitePieces();
	std::vector<Piece> GetWhitePiecesCaptured();

	std::vector<Piece> GetBlackPieces();
	std::vector<Piece> GetBlackPiecesCaptured();

public:

	void Initialize();
	void ClearAndDelete();

private:

	// Current Game Parameters
	std::time_t _startTime;		// __int64 
	std::time_t _endTime;		// __int64

	unsigned long _turnCounter;
	unsigned long _whiteSecondsLeft;
	unsigned long _blackSecondsLeft;

	bool _timedGame;
	bool _isWhiteAI;
	bool _isBlackAI;

	// SIGNALS INVALID TURN IN THE GAME
	bool _isValid;

private:

	// Game Data: { Game Parameters, AI Settings, Piece Lookup, Turn List }
	List<Turn>* _turnList;

private:

	// AI Settings
	unsigned short _depth;
};

