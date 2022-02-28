#include "Game.h"

Game::Game()
{
	this->Initialize();
}

Game::~Game()
{
	this->ClearAndDelete();
}

void Game::Restart(bool force)
{
	//if (!force && _gameState != GameStateCode::None)
	//	throw std::exception("Must complete the game before restarting - or force a restart");

	this->ClearAndDelete();
	this->Initialize();
}

void Game::Initialize()
{
	////// Create the board 2D array
	////_board = new Piece*[RANK_SIZE];

	////for (int index = 0; index < RANK_SIZE; index++)
	////	_board[index] = new Piece[FILE_SIZE];

	//// Go by rank - white is rank 1, rank 2, etc...
	//_board[RANK_1 - 1][FILE_A - 1] = Piece(RANK_1, FILE_A, true, PieceCode::Rook, PieceId::QueenRook, VALUE_ROOK);
	//_board[RANK_1 - 1][FILE_B - 1] = Piece(RANK_1, FILE_B, true, PieceCode::Knight, PieceId::QueenKnight, VALUE_KNIGHT);
	//_board[RANK_1 - 1][FILE_C - 1] = Piece(RANK_1, FILE_C, true, PieceCode::Bishop, PieceId::QueenBishop, VALUE_BISHOP);
	//_board[RANK_1 - 1][FILE_D - 1] = Piece(RANK_1, FILE_D, true, PieceCode::Queen, PieceId::Queen, VALUE_QUEEN);
	//_board[RANK_1 - 1][FILE_E - 1] = Piece(RANK_1, FILE_E, true, PieceCode::King, PieceId::King, VALUE_KING);
	//_board[RANK_1 - 1][FILE_F - 1] = Piece(RANK_1, FILE_F, true, PieceCode::Bishop, PieceId::KingBishop, VALUE_BISHOP);
	//_board[RANK_1 - 1][FILE_G - 1] = Piece(RANK_1, FILE_G, true, PieceCode::Knight, PieceId::KingKnight, VALUE_KNIGHT);
	//_board[RANK_1 - 1][FILE_H - 1] = Piece(RANK_1, FILE_H, true, PieceCode::Rook, PieceId::KingRook, VALUE_ROOK);

	//_board[RANK_2 - 1][FILE_A - 1] = Piece(RANK_2, FILE_A, true, PieceCode::Pawn, PieceId::QueenRookPawn, VALUE_PAWN);
	//_board[RANK_2 - 1][FILE_B - 1] = Piece(RANK_2, FILE_B, true, PieceCode::Pawn, PieceId::QueenKnightPawn, VALUE_PAWN);
	//_board[RANK_2 - 1][FILE_C - 1] = Piece(RANK_2, FILE_C, true, PieceCode::Pawn, PieceId::QueenBishopPawn, VALUE_PAWN);
	//_board[RANK_2 - 1][FILE_D - 1] = Piece(RANK_2, FILE_D, true, PieceCode::Pawn, PieceId::QueenPawn, VALUE_PAWN);
	//_board[RANK_2 - 1][FILE_E - 1] = Piece(RANK_2, FILE_E, true, PieceCode::Pawn, PieceId::KingPawn, VALUE_PAWN);
	//_board[RANK_2 - 1][FILE_F - 1] = Piece(RANK_2, FILE_F, true, PieceCode::Pawn, PieceId::KingBishopPawn, VALUE_PAWN);
	//_board[RANK_2 - 1][FILE_G - 1] = Piece(RANK_2, FILE_G, true, PieceCode::Pawn, PieceId::KingKnightPawn, VALUE_PAWN);
	//_board[RANK_2 - 1][FILE_H - 1] = Piece(RANK_2, FILE_H, true, PieceCode::Pawn, PieceId::KingRookPawn, VALUE_PAWN);

	//_board[RANK_7 - 1][FILE_A - 1] = Piece(RANK_7, FILE_A, false, PieceCode::Pawn, PieceId::QueenRookPawn, VALUE_PAWN);
	//_board[RANK_7 - 1][FILE_B - 1] = Piece(RANK_7, FILE_B, false, PieceCode::Pawn, PieceId::QueenKnightPawn, VALUE_PAWN);
	//_board[RANK_7 - 1][FILE_C - 1] = Piece(RANK_7, FILE_C, false, PieceCode::Pawn, PieceId::QueenBishopPawn, VALUE_PAWN);
	//_board[RANK_7 - 1][FILE_D - 1] = Piece(RANK_7, FILE_D, false, PieceCode::Pawn, PieceId::QueenPawn, VALUE_PAWN);
	//_board[RANK_7 - 1][FILE_E - 1] = Piece(RANK_7, FILE_E, false, PieceCode::Pawn, PieceId::KingPawn, VALUE_PAWN);
	//_board[RANK_7 - 1][FILE_F - 1] = Piece(RANK_7, FILE_F, false, PieceCode::Pawn, PieceId::KingBishopPawn, VALUE_PAWN);
	//_board[RANK_7 - 1][FILE_G - 1] = Piece(RANK_7, FILE_G, false, PieceCode::Pawn, PieceId::KingKnightPawn, VALUE_PAWN);
	//_board[RANK_7 - 1][FILE_H - 1] = Piece(RANK_7, FILE_H, false, PieceCode::Pawn, PieceId::KingRookPawn, VALUE_PAWN);

	//_board[RANK_8 - 1][FILE_A - 1] = Piece(RANK_8, FILE_A, false, PieceCode::Rook, PieceId::QueenRook, VALUE_ROOK);
	//_board[RANK_8 - 1][FILE_B - 1] = Piece(RANK_8, FILE_B, false, PieceCode::Knight, PieceId::QueenKnight, VALUE_KNIGHT);
	//_board[RANK_8 - 1][FILE_C - 1] = Piece(RANK_8, FILE_C, false, PieceCode::Bishop, PieceId::QueenBishop, VALUE_BISHOP);
	//_board[RANK_8 - 1][FILE_D - 1] = Piece(RANK_8, FILE_D, false, PieceCode::Queen, PieceId::Queen, VALUE_QUEEN);
	//_board[RANK_8 - 1][FILE_E - 1] = Piece(RANK_8, FILE_E, false, PieceCode::King, PieceId::King, VALUE_KING);
	//_board[RANK_8 - 1][FILE_F - 1] = Piece(RANK_8, FILE_F, false, PieceCode::Bishop, PieceId::KingBishop, VALUE_BISHOP);
	//_board[RANK_8 - 1][FILE_G - 1] = Piece(RANK_8, FILE_G, false, PieceCode::Knight, PieceId::KingKnight, VALUE_KNIGHT);
	//_board[RANK_8 - 1][FILE_H - 1] = Piece(RANK_8, FILE_H, false, PieceCode::Rook, PieceId::KingRook, VALUE_ROOK);

	//_gameState = GameStateCode::None;
	//_moveCounter = 0;

	//// Setup piece lists
	//for (unsigned short index = FILE_A - 1; index < FILE_H; index++)
	//{
	//	_whitePieces.push_back(_board[RANK_1 - 1][index]);
	//	_whitePieces.push_back(_board[RANK_2 - 1][index]);
	//	_blackPieces.push_back(_board[RANK_7 - 1][index]);
	//	_blackPieces.push_back(_board[RANK_8 - 1][index]);
	//}
}

void Game::ClearAndDelete()
{
	//for (int index = 0; index < RANK_SIZE; index++)
	//	delete[] _board[index];

	//delete[] _board;
}