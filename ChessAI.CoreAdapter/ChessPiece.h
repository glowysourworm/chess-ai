#include "ChessConstants.h"

using namespace System;

#pragma once
namespace CoreAdapter
{
	public ref class ChessPiece
	{
	public:

		ChessPiece(int rank, int file, CoreAdapter::ChessPieceCode code, CoreAdapter::ChessPieceId id, bool white);

		property int Rank;
		property int File;
		property CoreAdapter::ChessPieceCode Code;
		property CoreAdapter::ChessPieceId Id;
		property bool White;

		virtual String^ ToString() override;
	};
}