using CoreAdapter;

using System;
using System.Windows;
using System.Windows.Media;

namespace ChessAI.Control.PieceControl
{
    public class BauhausPieceControl : PieceControlBase
    {
        const double ROYALTY_RATIO = 4.0 / 6.0;
        const double PAWN_SUBRATIO = 2.0 / 3.0;

        protected override Geometry DefiningGeometry
        {
            get
            {
                return CreateGeometry();
            }
        }

        public BauhausPieceControl(ChessPiece piece, int pixelSize) : base(piece, pixelSize)
        {
            this.Fill = this.Data.White ? Brushes.White : Brushes.Black;
            this.Stroke = Brushes.CornflowerBlue;
            this.StrokeThickness = 1.0;
        }

        private Geometry CreateGeometry()
        {
            switch (this.Data.Code)
            {
                case ChessPieceCode.Pawn:
                    return CreatePawn();
                case ChessPieceCode.Knight:
                    return CreateKnight();
                case ChessPieceCode.Bishop:
                    return CreateBishop();
                case ChessPieceCode.Rook:
                    return CreateRook();
                case ChessPieceCode.Queen:
                    return CreateQueen();
                case ChessPieceCode.King:
                    return CreateKing();
                default:
                    throw new Exception("Unhandled chess piece code");
            }
        }

        private Geometry CreatePawn()
        {
            var size = this.Width * ROYALTY_RATIO * PAWN_SUBRATIO;
            var offset = (this.Width - size) / 2.0;

            return new RectangleGeometry(new Rect(offset, offset, size, size));
        }
        private Geometry CreateKnight()
        {
            var size = this.Width * ROYALTY_RATIO;
            var sixthSize = (1.0 / 6.0) * size;

            var figure = new PathFigure();
            figure.StartPoint = new Point(sixthSize, sixthSize);

            // N
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 3, sixthSize * 1), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 3, sixthSize * 3), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 3), true));

            // E
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 5), true));

            // S
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 5), true));

            // W
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 1), true));

            figure.IsClosed = true;

            return new PathGeometry(new PathFigure[] { figure });
        }
        private Geometry CreateBishop()
        {
            var size = this.Width * ROYALTY_RATIO;
            var sixthSize = (1.0 / 6.0) * size;

            var figure = new PathFigure();
            figure.StartPoint = new Point(sixthSize, sixthSize);

            // N
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 2, sixthSize * 1), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 3, sixthSize * 2), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 4, sixthSize * 1), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 1), true));

            // E
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 2), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 4, sixthSize * 3), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 4), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 5), true));

            // S
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 4, sixthSize * 5), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 3, sixthSize * 4), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 2, sixthSize * 5), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 5), true));

            // W
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 4), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 2, sixthSize * 3), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 2), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 1), true));

            figure.IsClosed = true;

            return new PathGeometry(new PathFigure[] { figure });
        }
        private Geometry CreateRook()
        {
            var size = this.Width * ROYALTY_RATIO;
            var sixthSize = (1.0 / 6.0) * size;

            var figure = new PathFigure();
            figure.StartPoint = new Point(sixthSize, sixthSize);

            // N
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 1), true));

            // E
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 5), true));

            // S
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 5), true));

            // W
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 1), true));

            figure.IsClosed = true;

            return new PathGeometry(new PathFigure[] { figure });
        }
        private Geometry CreateQueen()
        {
            var size = this.Width * ROYALTY_RATIO;
            var sixthSize = (1.0 / 6.0) * size;

            var figure = new PathFigure();
            figure.StartPoint = new Point(sixthSize, sixthSize);

            // OUTER SEGMENTS

            // N
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 1), true));

            // E
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 5), true));

            // S
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 5), true));

            // W
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 1), true));

            // INNER ELLIPSE SEGMENT

            // N OFFSET
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 3, sixthSize * 1), true));
            figure.Segments.Add(new ArcSegment(new Point(sixthSize * 3, sixthSize * 1),
                                               new Size(size, size),
                                               360,
                                               true,
                                               SweepDirection.Clockwise,
                                               true));

            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 1), true));

            figure.IsClosed = true;

            return new PathGeometry(new PathFigure[] { figure });
        }
        private Geometry CreateKing()
        {
            var size = this.Width * ROYALTY_RATIO;
            var sixthSize = (1.0 / 6.0) * size;

            var figure = new PathFigure();
            figure.StartPoint = new Point(sixthSize, sixthSize);

            // OUTER SEGMENTS

            // N
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 1), true));

            // E
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 5), true));

            // S
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 5), true));

            // W
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 1), true));

            // INNER SEGMENTS

            // N OFFSET INNER
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 3, sixthSize * 1), true));

            // KING'S CROWN
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 5, sixthSize * 3), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 3, sixthSize * 5), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 3), true));
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 3, sixthSize * 1), true));

            // Figure Closing Segment
            figure.Segments.Add(new LineSegment(new Point(sixthSize * 1, sixthSize * 1), true));

            figure.IsClosed = true;

            return new PathGeometry(new PathFigure[] { figure });
        }
    }
}
