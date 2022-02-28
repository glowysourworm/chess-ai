using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace ChessAI.ViewModel
{
    public class BasicCommand : ICommand
    {
        public event EventHandler CanExecuteChanged;

        Action _action;

        public BasicCommand(Action action)
        {
            _action = action;
        }

        public bool CanExecute(object parameter)
        {
            return _action != null;
        }

        public void Execute(object parameter)
        {
            _action();
        }
    }
}
