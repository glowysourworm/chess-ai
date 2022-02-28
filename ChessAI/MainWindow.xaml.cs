using ChessAI.ViewModel;

using System;
using System.Windows;

namespace ChessAI
{
    public partial class MainWindow : Window
    {
        // Primary View Model
        GameViewModel _viewModel;

        public MainWindow()
        {
            InitializeComponent();

            _viewModel = new GameViewModel(BoardViewModel.PieceStyle.Classic);

            // Hook primary view model to board control
            this.DataContext = _viewModel;
        }

        protected override void OnRenderSizeChanged(SizeChangedInfo sizeInfo)
        {
            base.OnRenderSizeChanged(sizeInfo);

            ResizeImpl(sizeInfo.NewSize);
        }

        protected override void OnStateChanged(EventArgs e)
        {
            base.OnStateChanged(e);

            ResizeImpl(this.RenderSize);
        }

        private void ResizeImpl(Size size)
        {
            // SEE XAML FOR STATIC SIZES
            this.BoardContainer.Width = size.Width - 300;
            this.BoardContainer.Height = size.Height - 300;

            var maxBoardSize = Math.Min(this.BoardContainer.Width, this.BoardContainer.Height);
            var boardSize = maxBoardSize - 100;
            var squareSize = boardSize / CoreAdapter.ChessConstants.Rank8;

            this.BoardCtrl.Width = boardSize;
            this.BoardCtrl.Height = boardSize;

            _viewModel.BoardViewModel.ChessSquareSize = squareSize;
        }
    }
}
