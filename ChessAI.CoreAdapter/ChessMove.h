#pragma once
namespace CoreAdapter
{
	public ref struct ChessMove {
		property bool WhiteTurn;
		property unsigned short RankBegin;
		property unsigned short RankEnd;
		property unsigned short FileBegin;
		property unsigned short FileEnd;
	};
}