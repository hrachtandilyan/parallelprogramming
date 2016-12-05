using NLog;
using ParallelProgrammingDemo.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo.Calculators
{
    public class MetricFactory
    {
        public static Func<List<float>, List<float>, float> GetDistanceMetric(MetricType metricType)
        {
            switch (metricType)
            {
                case MetricType.HAMMING:
                    return (new MetricFactory()).CalculateHammingDistance;
                case MetricType.L2:
                    return (new MetricFactory()).CalculateLTwoDistance;
                case MetricType.L1:
                    return (new MetricFactory()).CalculateLOneDistance;
            }

            return null; 
        }

        public float CalculateHammingDistance(List<float> queryVector, List<float> dataVector)
        {
            double calcResult = 0;

            for(int i=0; i<queryVector.Count(); i++)
            {
                calcResult += (queryVector[i] + dataVector[i] + double.Epsilon) % 2; 
            }

            return (float)calcResult;
        }

        public float CalculateLOneDistance(List<float> queryVector, List<float> dataVector)
        {
            double calcResult = 0; 

            for(int i=0; i<queryVector.Count(); i++)
            {
                calcResult += Math.Abs(queryVector[i] - dataVector[i]);
            }

            return (float)calcResult;
        }

        public float CalculateLTwoDistance(List<float> queryVector, List<float> dataVector)
        {
            double calcResult = 0;

            for (int i = 0; i < queryVector.Count(); i++)
            {
                calcResult += Math.Pow((queryVector[i] - dataVector[i]), 2);
            }

            return (float)calcResult;
        }
    }
}
