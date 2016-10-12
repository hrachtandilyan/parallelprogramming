using ParallelProgrammingDemo.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo.Calculators
{
    public class DistanceCalculatorFactory
    {
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
                    return new MPIDistanceCalculator();
            }

            return null;
        }
    }
}
