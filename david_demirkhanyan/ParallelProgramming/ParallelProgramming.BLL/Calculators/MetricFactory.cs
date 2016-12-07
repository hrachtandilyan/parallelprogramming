using NLog;
using ParallelProgramming.BLL.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgramming.BLL.Calculators
{
    public class MetricFactory
    {
        /// <summary>
        /// Initializes and returns a delegate to the requested method
        /// </summary>
        /// <param name="metricType">Hamming, L1, or L2</param>
        /// <returns></returns>
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

        /// <summary>
        /// Hamming metric
        /// </summary>
        /// <param name="queryVector"></param>
        /// <param name="dataVector"></param>
        /// <returns></returns>
        public float CalculateHammingDistance(List<float> queryVector, List<float> dataVector)
        {
            double calcResult = 0;

            for(int i=0; i<queryVector.Count(); i++)
            {
                calcResult += (queryVector[i] + dataVector[i] + double.Epsilon) % 2; 
            }

            return (float)calcResult;
        }

        /// <summary>
        /// L1 metric
        /// </summary>
        /// <param name="queryVector"></param>
        /// <param name="dataVector"></param>
        /// <returns></returns>
        public float CalculateLOneDistance(List<float> queryVector, List<float> dataVector)
        {
            double calcResult = 0; 

            for(int i=0; i<queryVector.Count(); i++)
            {
                calcResult += Math.Abs(queryVector[i] - dataVector[i]);
            }

            return (float)calcResult;
        }

        /// <summary>
        /// L2 metric
        /// </summary>
        /// <param name="queryVector"></param>
        /// <param name="dataVector"></param>
        /// <returns></returns>
        public float CalculateLTwoDistance(List<float> queryVector, List<float> dataVector)
        {
            double calcResult = 0;

            for (int i = 0; i < queryVector.Count(); i++)
            {
                calcResult += (queryVector[i] - dataVector[i])*(queryVector[i] - dataVector[i]);
            }

            return (float)Math.Sqrt(calcResult);
        }
    }
}
