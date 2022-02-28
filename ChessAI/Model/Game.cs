using CoreAdapter;

using System;
using System.Collections.Generic;
using System.Windows;

namespace ChessAI.Model
{
    public class Game
    {
        CoreAPI _api;

        public int TurnCounter { get; private set; }
        public int LastTurnDepth { get; private set; }
        public string LastTurn { get; private set; }
        public bool WhiteTurn { get; private set; }

        public event EventHandler<ChessPiece[]> PiecesChangedEvent;

        public Game()
        {
            _api = new CoreAPI();

            Initialize();
        }

        public void Initialize()
        {
            this.TurnCounter = 0;
            this.LastTurnDepth = 1;
            this.LastTurn = "(none)";
            this.WhiteTurn = true;

            // Force reset (no exceptions)
            _api.Reset(true);

            // Force redraw
            if (this.PiecesChangedEvent != null)
                this.PiecesChangedEvent(this, _api.GetPiecesInPlay());
        }

        public bool NextTurn(ushort searchDepth, ushort rank1, ushort file1, ushort rank2, ushort file2)
        {
            var result = _api.Move(this.WhiteTurn, searchDepth, rank1, file1, rank2, file2);

            switch (result.Code)
            {
                case ChessMoveResultCode.GeneralError:
                case ChessMoveResultCode.WrongColorTurn:
                case ChessMoveResultCode.NoPiece:
                case ChessMoveResultCode.MoveBlockedSameColor:
                case ChessMoveResultCode.MoveBlockedOpposingColor:
                case ChessMoveResultCode.IllegalMove:
                case ChessMoveResultCode.IllegalCastle:
                case ChessMoveResultCode.IllegalMoveCheck:
                    ErrorResult(result);
                    return false;
                case ChessMoveResultCode.Success:
                    SuccessResult(result);
                    return true;
                default:
                    throw new Exception("Unhandled API result code:  " + result.Code);
            }
        }

        /// <summary>
        /// Returns current pieces in play
        /// </summary>
        public IEnumerable<ChessPiece> GetChessPieces()
        {
            return _api.GetPiecesInPlay();
        }

        #region (private) Chess Turn API Result
        private void SuccessResult(ChessMoveResult result)
        {
            this.TurnCounter++;
            this.WhiteTurn = !this.WhiteTurn;
            this.LastTurn = CreateTurnString(result.Rank1, result.File1, result.Rank2, result.File2);
            this.LastTurnDepth = result.SearchDepth;
        }
        private void ErrorResult(ChessMoveResult result)
        {
            MessageBox.Show("AI Error:  " + result.Code.ToString());
        }
        private string CreateTurnString(ushort rank1, ushort file1, ushort rank2, ushort file2)
        {
            return CreateFileString(file1) + 
                   CreateRankString(rank1) + 
                   " \u2192 " + 
                   CreateFileString(file2) + 
                   CreateRankString(rank2);
        }
        private string CreateRankString(ushort rank)
        {
            if (rank == ChessConstants.Rank1)
                return "1";

            else if (rank == ChessConstants.Rank2)
                return "2";

            else if (rank == ChessConstants.Rank3)
                return "3";

            else if (rank == ChessConstants.Rank4)
                return "4";

            else if (rank == ChessConstants.Rank5)
                return "5";

            else if (rank == ChessConstants.Rank6)
                return "6";

            else if (rank == ChessConstants.Rank7)
                return "7";

            else if (rank == ChessConstants.Rank8)
                return "8";

            else
                throw new Exception("Unhandled chess rank code");
        }
        private string CreateFileString(ushort file)
        {
            if (file == ChessConstants.FileA)
                return "A";

            else if (file == ChessConstants.FileB)
                return "B";

            else if (file == ChessConstants.FileC)
                return "C";

            else if (file == ChessConstants.FileD)
                return "D";

            else if (file == ChessConstants.FileE)
                return "E";

            else if (file == ChessConstants.FileF)
                return "F";

            else if (file == ChessConstants.FileG)
                return "G";

            else if (file == ChessConstants.FileH)
                return "H";

            else
                throw new Exception("Unhandled chess file code");
        }
        #endregion
    }
}
