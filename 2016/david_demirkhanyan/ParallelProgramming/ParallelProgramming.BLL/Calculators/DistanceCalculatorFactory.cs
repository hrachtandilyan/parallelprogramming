using ParallelProgramming.BLL.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgramming.BLL.Calculators
{
    public class DistanceCalculatorFactory
    {
        /// <summary>
        /// Initializes and returns a calculator object
        /// </summary>
        /// <param name="type">Calculator type, sync, parallel, MPI or CUDA computation types</param>
        /// <returns></returns>
        public static IDistanceCalculator GetCalculator(CalculatorType type)
        {
            switch(type)
            {
                case CalculatorType.SYNC:
                    return new SyncDistanceCalculator();
                case CalculatorType.PARALLEL:
                    return new ParallelDistanceCalculator();
                case CalculatorType.MPI:
                    return new MPIDistanceCalculator();
                case CalculatorType.CUDA:
                    return new NvidaCudaDistanceCalculator();
            }

            return null;
        }
    }
}
