using System;
using DistanceCalculator.Models;

namespace DistanceCalculator.Engines
{
    class AsyncronousDistanceCalculator:AbstractCalculatorEngine
    {
        /// <summary>
        /// Calculating Distance asyncronously
        /// </summary>
        /// <param name="m1">DataSet Vectors</param>
        /// <param name="m2">Query Vectors</param>
        /// <returns></returns>
        public override Matrix CalculateDistance(Matrix m1, Matrix m2)
        {
            throw new NotImplementedException();
        }
    }
}
