using ParallelProgrammingDemo.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo.Calculators
{
    public class BaseCalculator
    {
        protected float CalculateHammingDistance(List<float> queryVector, List<float> dataVector)
        {
            return 0;
        }

        protected float CalculateLOneDistance(List<float> queryVector, List<float> dataVector)
        {
            return 0;
        }

        protected float CalculateLTwoDistance(List<float> queryVector, List<float> dataVector)
        {
            return 0; 
        }
    }
}
