using ChessAI.Model;

using CoreAdapter;

using System.ComponentModel;
using System.Windows.Input;

namespace ChessAI.ViewModel
{
    public class GameViewModel : INotifyPropertyChanged
    {
        int _turnCounter;
        int _lastTurnDepth;
        string _lastTurn;
        string _whiteTurn;

        public int TurnCounter
        {
            get { return _turnCounter; }
            set { _turnCounter = value; OnPropertyChanged("TurnCounter"); }
        }
        public int LastTurnDepth
        {
            get { return _lastTurnDepth; }
            set { _lastTurnDepth = value; OnPropertyChanged("LastTurnDepth"); }
        }
        public string LastTurn
        {
            get { return _lastTurn; }
            set { _lastTurn = value; OnPropertyChanged("LastTurn"); }
        }
        public string WhiteTurn
        {
            get { return _whiteTurn; }
            set { _whiteTurn = value; OnPropertyChanged("WhiteTurn"); }
        }

        public ICommand ResetCommand { get; private set; }
        public ICommand NextTurnCommand { get; private set; }

        public BoardViewModel BoardViewModel { get; private set; }

        // Core API
        Game _game;

        public GameViewModel(BoardViewModel.PieceStyle style)
        {
            _game = new Game();

            this.BoardViewModel = new BoardViewModel(_game.GetChessPieces(), style);

            this.ResetCommand = new BasicCommand(() =>
            {
                _game.Initialize();
            });

            this.NextTurnCommand = new BasicCommand(() =>
            {
                // TODO
                if (_game.NextTurn(1, ChessConstants.Rank2, ChessConstants.FileE, ChessConstants.Rank4, ChessConstants.FileE))
                {
                    this.TurnCounter = _game.TurnCounter;
                    this.LastTurnDepth = _game.LastTurnDepth;
                    this.LastTurn = _game.LastTurn;
                    this.WhiteTurn = _game.WhiteTurn ? "White" : "Black";
                }
            });

            // UPDATE FROM API BACKEND
            _game.PiecesChangedEvent += OnGameUpdate;
        }

        private void OnGameUpdate(object sender, ChessPiece[] chessPieces)
        {
            // Backend API -> UI
            this.BoardViewModel.Update(chessPieces);
        }

        #region INotifyPropertyChanged
        public event PropertyChangedEventHandler PropertyChanged;

        protected void OnPropertyChanged(string name)
        {
            if (this.PropertyChanged != null)
                this.PropertyChanged(this, new PropertyChangedEventArgs(name));
        }
        #endregion
    }
}
