using System;
using System.Reflection;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace ChessAI.Service
{
    public static class ResourceService
    {
        public enum ResourceIdentifier
        {
            ClassicQueenWhite,
            ClassicKingWhite,
            ClassicBishopWhite,
            ClassicRookWhite,
            ClassicKnightWhite,
            ClassicPawnWhite,
            ClassicQueenBlack,
            ClassicKingBlack,
            ClassicBishopBlack,
            ClassicRookBlack,
            ClassicKnightBlack,
            ClassicPawnBlack
        }

        public static ImageSource Get(ResourceIdentifier identifier)
        {
            string resourceName = null;

            switch (identifier)
            {
                case ResourceIdentifier.ClassicQueenWhite:
                case ResourceIdentifier.ClassicKingWhite:
                case ResourceIdentifier.ClassicBishopWhite:
                case ResourceIdentifier.ClassicRookWhite:
                case ResourceIdentifier.ClassicKnightWhite:
                case ResourceIdentifier.ClassicPawnWhite:
                case ResourceIdentifier.ClassicQueenBlack:
                case ResourceIdentifier.ClassicKingBlack:
                case ResourceIdentifier.ClassicBishopBlack:
                case ResourceIdentifier.ClassicRookBlack:
                case ResourceIdentifier.ClassicKnightBlack:
                case ResourceIdentifier.ClassicPawnBlack:
                    resourceName = CompileChessPieceResourceName("Classic", identifier.ToString().Replace("Classic", ""));
                    break;
                default:
                    throw new Exception("Unhandled resource identifier");
            }

            if (resourceName != null)
            {
                return ReadPngResource(resourceName);
            }
            else
                throw new Exception("Unidentified resource:  " + identifier);
        }

        /// <summary>
        /// Method for chess piece resource folders
        /// </summary>
        private static string CompileChessPieceResourceName(string styleFolder, string fileNameWithoutExtension)
        {
            var assemblyName = "ChessAI";
            var resourceBaseName = "Resources.Bitmaps.ChessPieces";

            return string.Join(".", assemblyName, resourceBaseName, styleFolder, fileNameWithoutExtension, "png");
        }

        private static ImageSource ReadPngResource(string resourceName)
        {
            using (var stream = Assembly.GetExecutingAssembly().GetManifestResourceStream(resourceName))
            {
                var buffer = new byte[stream.Length];
                var decoder = new PngBitmapDecoder(stream, BitmapCreateOptions.None, BitmapCacheOption.None);

                return decoder.Frames[0];
            }
        }
    }
}
