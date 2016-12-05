using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ParallelProgrammingDemo.Entities;
using System.Diagnostics;

namespace ParallelProgrammingDemo.Calculators
{
    public class SyncDistanceCalculator : IDistanceCalculator
    {
        /// <summary>
        /// Evaluates the distance between the according vectors and the overall running time
        /// </summary>
        /// <param name="QueryVectors">first set of vectors</param>
        /// <param name="DatasetVectors">second set of vectors </param>
        /// <returns></returns>
        public ComputationResult<float> GetComputationResult(ComputationRequest<float> request)
        {
            var stopWatch = new Stopwatch();
            stopWatch.Start();

            var distanceMatrix = this.GetDistanceMatrix(request);

            stopWatch.Stop();

            return new ComputationResult<float>(distanceMatrix, stopWatch.Elapsed.ToString());
        }

        /// <summary>
        /// Evaluates the distance between the according vectors
        /// </summary>
        /// <param name="QueryVectors">first set of vectors</param>
        /// <param name="DatasetVectors">second set of vectors</param>
        /// <returns></returns>
        public Matrix<float> GetDistanceMatrix(ComputationRequest<float> request)
        {
            var distanceMatrix = new Matrix<float>();
            
            for(int i=0; i<request.QueryVectors.Height; i++)
            {
                for(int j=0; j<request.DatasetVectors.Height; j++)
                {
                    distanceMatrix.AddElement(request.CalculateDistance(request.QueryVectors[i], 
                                                                        request.DatasetVectors[j]), i, j);
                }
            }

            return distanceMatrix;
        }
    }
}
