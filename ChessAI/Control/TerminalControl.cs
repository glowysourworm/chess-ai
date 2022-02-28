using System.Windows.Controls;
using System.Windows.Media;

namespace ChessAI.Control
{
    public class TerminalControl : RichTextBox
    {
        public TerminalControl()
        {
            this.IsReadOnly = true;
            this.IsReadOnlyCaretVisible = true;

            this.Background = Brushes.DarkBlue;
            this.Foreground = Brushes.Beige;
        }
    }
}
