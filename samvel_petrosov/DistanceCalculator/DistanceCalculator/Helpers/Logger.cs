using System;

namespace DistanceCalculator.Helpers
{
    class Logger
    {
        public enum WarningLever
        {
            ERROR,
            WARNING,
            DEBUG
        }
        /// <summary>
        /// Write Log with corresponding logging level and color
        /// </summary>
        /// <param name="msg">Error message</param>
        /// <param name="wl">Logging level</param>
        public static void WriteLog(string msg,WarningLever wl)
        {
            switch(wl)
            {
                case WarningLever.ERROR:
                    Console.ForegroundColor = ConsoleColor.Red;
                    break;
                case WarningLever.DEBUG:
                    Console.ForegroundColor = ConsoleColor.Blue;
                    break;
                case WarningLever.WARNING:
                    Console.ForegroundColor = ConsoleColor.DarkYellow;
                    break;
            }
            Console.WriteLine("{0}: {1}",wl,msg);
            Console.ResetColor();
        }
    }
}
