using ChessAI.Control;
using ChessAI.Control.PieceControl;

using CoreAdapter;

using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;

namespace ChessAI.ViewModel
{
    /// <summary>
    /// View model will contain actual controls for the pieces since the data is native (chose a weird pattern).. So,
    /// lets define static pieces and where they are on / off the board
    /// </summary>
    public class BoardViewModel
    {
        public enum PieceStyle
        {
            Classic,
            Bauhaus
        }

        double _chessSquareSize;
        PieceStyle _chessPieceStyle;

        /// <summary>
        /// Collection of primary chess piece UI controls
        /// </summary>
        public ObservableCollection<PieceControlBase> ChessPieces { get; set; }

        public double ChessSquareSize
        {
            get { return _chessSquareSize; }
            set { _chessSquareSize = value; ResizePieces(); }
        }

        public BoardViewModel(IEnumerable<ChessPiece> currentPieces, PieceStyle style)
        {
            _chessPieceStyle = style;

            this.ChessPieces = new ObservableCollection<PieceControlBase>();

            Update(currentPieces);
        }

        /// <summary>
        /// Primary update method for piece data from the CoreAPI
        /// </summary>
        public void Update(IEnumerable<ChessPiece> currentPieces)
        {
            // TODO: Need to has the pieces for performance
            foreach (var pieceData in currentPieces)
            {
                var found = false;

                foreach (var piece in this.ChessPieces)
                {
                    if (pieceData.Id == piece.GetId() &&
                        pieceData.White == piece.GetWhite())
                    {
                        // Updates the piece control with the current data
                        piece.Update(pieceData);

                        found = true;
                        break;
                    }
                }

                // NEW PIECE
                if (!found)
                {
                    switch (_chessPieceStyle)
                    {
                        case PieceStyle.Classic:
                            this.ChessPieces.Add(new ClassicPieceControl(pieceData, (int)this.ChessSquareSize));
                            break;
                        case PieceStyle.Bauhaus:
                            this.ChessPieces.Add(new BauhausPieceControl(pieceData, (int)this.ChessSquareSize));
                            break;
                        default:
                            throw new System.Exception("Unhandled chess piece style");
                    }
                    
                }
            }

            // CHECK FOR REMOVED PIECES
            for (int index = this.ChessPieces.Count - 1; index >= 0; index--)
            {
                // None Found -> Remove piece control
                if (!currentPieces.Any(pieceData =>
                {
                    return pieceData.Id == this.ChessPieces[index].GetId() && 
                           pieceData.White == this.ChessPieces[index].GetWhite();
                }))
                {
                    this.ChessPieces.RemoveAt(index);
                }
            }
        }

        private void ResizePieces()
        {
            // Forces pieces to resize to the new square size
            foreach (var piece in this.ChessPieces)
                piece.UpdateSize((int)this.ChessSquareSize);
        }
    }
}
