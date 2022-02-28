using ChessAI.Service;

using CoreAdapter;

using System;
using System.Windows;
using System.Windows.Media;

namespace ChessAI.Control.PieceControl
{
    public class ClassicPieceControl : PieceControlBase
    {
        public ClassicPieceControl(ChessPiece piece, int pixelSize) : base(piece, pixelSize)
        {
            this.Width = pixelSize;
            this.Height = pixelSize;

            SetPieceImage(pixelSize);
        }

        public override void UpdateSize(int pixelSize)
        {
            SetPieceImage(pixelSize);

            base.UpdateSize(pixelSize);
        }

        protected void SetPieceImage(int pixelSize)
        {
            var imageBrush = new ImageBrush();

            switch (this.Data.Code)
            {
                case ChessPieceCode.Pawn:
                    imageBrush.ImageSource = ResourceService.Get(this.Data.White ? ResourceService.ResourceIdentifier.ClassicPawnWhite :
                                                                               ResourceService.ResourceIdentifier.ClassicPawnBlack);
                    break;
                case ChessPieceCode.Knight:
                    imageBrush.ImageSource = ResourceService.Get(this.Data.White ? ResourceService.ResourceIdentifier.ClassicKnightWhite :
                                                                               ResourceService.ResourceIdentifier.ClassicKnightBlack);
                    break;
                case ChessPieceCode.Bishop:
                    imageBrush.ImageSource = ResourceService.Get(this.Data.White ? ResourceService.ResourceIdentifier.ClassicBishopWhite :
                                                                               ResourceService.ResourceIdentifier.ClassicBishopBlack);
                    break;
                case ChessPieceCode.Rook:
                    imageBrush.ImageSource = ResourceService.Get(this.Data.White ? ResourceService.ResourceIdentifier.ClassicRookWhite :
                                                                               ResourceService.ResourceIdentifier.ClassicRookBlack);
                    break;
                case ChessPieceCode.Queen:
                    imageBrush.ImageSource = ResourceService.Get(this.Data.White ? ResourceService.ResourceIdentifier.ClassicQueenWhite :
                                                                               ResourceService.ResourceIdentifier.ClassicQueenBlack);
                    break;
                case ChessPieceCode.King:
                    imageBrush.ImageSource = ResourceService.Get(this.Data.White ? ResourceService.ResourceIdentifier.ClassicKingWhite :
                                                                               ResourceService.ResourceIdentifier.ClassicKingBlack);
                    break;
                default:
                    throw new Exception("Unhandled piece code");
            }

            imageBrush.Viewbox = new Rect(0, 0, 1, 1);
            imageBrush.ViewboxUnits = BrushMappingMode.RelativeToBoundingBox;
            imageBrush.Viewport = new Rect(0, 0, 1, 1);
            imageBrush.ViewportUnits = BrushMappingMode.RelativeToBoundingBox;
            imageBrush.AlignmentX = AlignmentX.Left;
            imageBrush.AlignmentY = AlignmentY.Top;
            imageBrush.TileMode = TileMode.None;

            this.Fill = imageBrush;
        }

        protected override Geometry DefiningGeometry
        {
            get { return new RectangleGeometry(new Rect(0, 0, this.Width, this.Height)); }
        }
    }
}
