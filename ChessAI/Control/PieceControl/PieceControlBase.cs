using CoreAdapter;

using System.Windows.Shapes;

namespace ChessAI.Control.PieceControl
{
    public abstract class PieceControlBase : Shape
    {
        /// <summary>
        /// Original immutable data for the chess piece
        /// </summary>
        protected ChessPiece Data { get; private set; }

        public PieceControlBase(ChessPiece piece, int pixelSize)
        {
            this.Data = piece;
            this.Width = pixelSize;
            this.Height = pixelSize;
        }

        public virtual void Update(ChessPiece piece)
        {
            this.Data = piece;

            InvalidateVisual();
        }
        public virtual void UpdateSize(int pixelSize)
        {
            this.Width = pixelSize;
            this.Height = pixelSize;

            InvalidateVisual();
        }

        public ChessPieceId GetId()
        {
            return this.Data.Id;
        }

        public int GetRank()
        {
            return this.Data.Rank;
        }

        public int GetFile()
        {
            return this.Data.File;
        }

        public bool GetWhite()
        {
            return this.Data.White;
        }

        public override string ToString()
        {
            return this.GetId().ToString();
        }
    }
}
