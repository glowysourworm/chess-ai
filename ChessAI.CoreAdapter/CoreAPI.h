#include "..\\ChessAI.Core\Game.h"
#include "..\\ChessAI.Core\Turn.h"
#include "ChessPiece.h"
#include "ChessMoveResult.h"
#include <vector>
#include <exception>

using namespace System;

#pragma once
namespace CoreAdapter
{
	public ref class CoreAPI
	{

	public:

		CoreAPI();
		~CoreAPI();
		!CoreAPI();

		void Reset(bool force);

	public:

		array<ChessPiece^>^ GetPiecesInPlay();

	public:

		ChessMoveResult^ Move(bool whiteMove, unsigned short searchDepth, unsigned short rank1, unsigned short file1, unsigned short rank2, unsigned short file2);

	private:
		//Board* _board;
	};
}