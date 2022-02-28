using ChessAI.Control.PieceControl;

using CoreAdapter;

using System;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace ChessAI.Control
{
    public class BoardPanel : ItemsControl
    {
        public Brush BlackBrush { get; set; }
        public Brush WhiteBrush { get; set; }

        readonly Pen _linePen; 

        public BoardPanel()
        {
            this.BlackBrush = Brushes.Black;
            this.WhiteBrush = Brushes.White;

            _linePen = new Pen(Brushes.CornflowerBlue, 1.0);
        }

        protected override Size MeasureOverride(Size availableSize)
        {
            var minDimension = Math.Min(availableSize.Width, availableSize.Height);

            return base.MeasureOverride(new Size(minDimension, minDimension));
        }

        protected override Size ArrangeOverride(Size finalSize)
        {
            // NOTE*** Force casting to piece implementation
            foreach (var piece in this.Items.Cast<PieceControlBase>())
            {
                var boundary = GetBoundary(piece.GetRank(), piece.GetFile());

                piece.Arrange(boundary);
            }

            return base.ArrangeOverride(finalSize);
        }

        /// <summary>
        /// Returns the UI boundary for the square in pixel coordinates
        /// </summary>
        protected Rect GetBoundary(int rank, int file)
        {
            var size = this.RenderSize.Width / ChessConstants.Rank8;

            return new Rect(new Point((file - 1) * size,
                                      (ChessConstants.Rank8 - rank) * size),
                            new Point(file * size,
                                     (ChessConstants.Rank8 - rank + 1) * size));
        }

        protected override void OnRender(DrawingContext drawingContext)
        {
            for (int rank = ChessConstants.Rank1; rank <= ChessConstants.Rank8; rank++)
            {
                for (int file = ChessConstants.FileA; file <= ChessConstants.FileH; file++)
                {
                    // Bottom left square is black
                    var black = ((rank + file) % 2) == 0;

                    // Calculate the boundary for the square
                    var square = GetBoundary(rank, file);

                    // Draw square in the background before pieces are rendered
                    drawingContext.DrawRectangle(black ? this.BlackBrush : this.WhiteBrush, _linePen, square);
                }
            }

            base.OnRender(drawingContext);
        }

        protected override void OnRenderSizeChanged(SizeChangedInfo sizeInfo)
        {
            base.OnRenderSizeChanged(sizeInfo);

            InvalidateVisual();
        }
    }
}
