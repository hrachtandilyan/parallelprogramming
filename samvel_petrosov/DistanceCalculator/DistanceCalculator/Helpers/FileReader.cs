using System.IO;

namespace DistanceCalculator.Helpers
{
    class FileReader
    {
        /// <summary>
        /// Reading byte array from specified file
        /// </summary>
        /// <param name="filePath">File path</param>
        /// <returns></returns>
        public static byte[] ReadFromFile(string filePath)
        {
            byte[] retArray=null;
            try
            {
                using (FileStream fs = new FileStream(filePath, FileMode.Open))
                {
                    retArray = new byte[fs.Length];
                    fs.Read(retArray, 0, retArray.Length);
                }
            }
            catch(FileNotFoundException exc)
            {
                Logger.WriteLog(exc.Message, Logger.WarningLever.ERROR);
            }
            return retArray;
        }
    }
}
