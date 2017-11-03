using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Distance_Calculator.FileOperations
{
    public class Logger
    {

        #region Program Log 

        public void LogToProgram(string text)
        {
            using (StreamWriter file = new StreamWriter("ProgramLog.txt", true))
            {
                file.WriteLine(text);
            }
        }

        public void ProgramLogDelete()
        {
            if (File.Exists("ProgramLog.txt"))
            {
                 File.Delete("ProgramLog.txt");
            }
        }

        #endregion

        #region Implementations Log   

        public void LogToImplementation(string text, string calculationEngineName, string calculationImplementationName)
        {
            using (StreamWriter file = new StreamWriter($"{calculationEngineName}Engine{calculationImplementationName}Log.txt", true))
            {
                file.WriteLine(text);
            }
        }

        public void ImplementationLogDelete(string calculationEngineName, string calculationImplementationName)
        {
            if (File.Exists($"{calculationEngineName}Engine{calculationImplementationName}Log.txt"))
            {
                File.Delete($"{calculationEngineName}Engine{calculationImplementationName}Log.txt");
            }
        }

        #endregion

    }
}
