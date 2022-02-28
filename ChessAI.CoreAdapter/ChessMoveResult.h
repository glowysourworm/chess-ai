#include "ChessConstants.h"

#pragma once
namespace CoreAdapter
{
	public ref struct  ChessMoveResult {

	public:

		property ChessMoveResultCode Code;

		property unsigned short SearchDepth;

		property unsigned short Rank1;
		property unsigned short File1;

		property unsigned short Rank2;
		property unsigned short File2;

		property ChessPieceId SourcePieceId;
		property ChessPieceId CapturedPieceId;

		property bool WhiteTurn;
		property bool PieceCaptured;

		ChessMoveResult(TurnResultCode code, 
						unsigned short searchDepth,
						unsigned short rank1,
						unsigned short file1,
						unsigned short rank2,
						unsigned short file2,
						ChessPieceId sourcePieceId,
						ChessPieceId capturedPieceId,
						bool whiteTurn,
						bool pieceCaptured)
		{
			this->Code = (ChessMoveResultCode)code;
			this->SearchDepth = searchDepth;
			this->Rank1 = rank1;
			this->File1 = file1;
			this->Rank2 = rank2;
			this->File2 = file2;
			this->SourcePieceId = sourcePieceId;
			this->CapturedPieceId = capturedPieceId;
			this->WhiteTurn = whiteTurn;
			this->PieceCaptured = pieceCaptured;
		}
	};
}