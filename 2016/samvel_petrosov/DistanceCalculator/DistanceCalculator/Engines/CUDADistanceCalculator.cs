using System;
using DistanceCalculator.Models;

namespace DistanceCalculator.Engines
{
    class CUDADistanceCalculator: AbstractCalculatorEngine
    {
        /// <summary>
        /// Calculating Distance using NVidia Cuda technology
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
