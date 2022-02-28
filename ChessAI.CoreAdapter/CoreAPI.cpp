#include "CoreAPI.h"

namespace CoreAdapter
{
	CoreAPI::CoreAPI()
	{
		//_board = new Board();
	}
	CoreAPI::!CoreAPI()
	{
		//delete _board;
	}
	CoreAPI::~CoreAPI()
	{

	}

	void CoreAPI::Reset(bool force)
	{
		try
		{
			//_board->Restart(force);
		}
		catch (std::exception ex)
		{
			throw gcnew Exception(gcnew String(ex.what()));
		}
	}

	ChessMoveResult^ CoreAPI::Move(bool whiteMove, unsigned short searchDepth, unsigned short rank1, unsigned short file1, unsigned short rank2, unsigned short file2)
	{
		// Turn result = _board->MovePiece(whiteMove, rank1, file1, rank2, file2);

		//return gcnew ChessMoveResult(result.code,
		//							 result.searchDepth,
		//							 result.rank1,
		//							 result.file1,
		//							 result.rank2,
		//							 result.file2,
		//							 (ChessPieceId)result.sourcePieceId,
		//							 (ChessPieceId)result.capturedPieceId,
		//							 result.whiteTurn,
		//							 result.pieceCaptured);
		return nullptr;
	}

	array<ChessPiece^>^ CoreAPI::GetPiecesInPlay()
	{
		//std::vector<Piece> whitePieces = _board->GetWhitePieces();
		//std::vector<Piece> blackPieces = _board->GetBlackPieces();

		//array<ChessPiece^>^ result = gcnew array<ChessPiece^>(whitePieces.size() + blackPieces.size());

		//// Copy white piece data
		//for (int index = 0; index < whitePieces.size(); index++)
		//{
		//	Piece piece = whitePieces.at(index);

		//	result[index] = gcnew ChessPiece(piece.rank,
		//									 piece.file,
		//								    (CoreAdapter::ChessPieceCode)piece.code,
		//									(CoreAdapter::ChessPieceId)piece.id,
		//									 piece.white);
		//}

		//// Copy black piece data
		//for (int index = 0; index < blackPieces.size(); index++)
		//{
		//	Piece piece = blackPieces.at(index);

		//	result[index + whitePieces.size()] = gcnew ChessPiece(piece.rank,
		//														  piece.file,
		//													   	 (CoreAdapter::ChessPieceCode)piece.code,
		//														 (CoreAdapter::ChessPieceId)piece.id,
		//													      piece.white);
		//}

		//return result;
		return nullptr;
	}
}