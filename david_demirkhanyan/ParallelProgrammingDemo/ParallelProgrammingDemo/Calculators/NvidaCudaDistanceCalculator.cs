using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ParallelProgrammingDemo.Entities;

namespace ParallelProgrammingDemo.Calculators
{
    public class NvidaCudaDistanceCalculator : BaseCalculator, IDistanceCalculator
    {
        /// <summary>
        /// Evaluates the distance between the according vectors and the overall running time
        /// </summary>
        /// <param name="QueryVectors">first set of vectors</param>
        /// <param name="DatasetVectors">second set of vectors </param>
        /// <returns></returns>
        public ComputationResult<float> GetComputationResult(ComputationRequest<float> request)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Evaluates the distance between the according vectors
        /// </summary>
        /// <param name="QueryVectors">first set of vectors</param>
        /// <param name="DatasetVectors">second set of vectors</param>
        /// <returns></returns>
        public Matrix<float> GetDistanceMatrix(ComputationRequest<float> request)
        {
            throw new NotImplementedException();
        }
    }
}
