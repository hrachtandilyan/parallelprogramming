using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ParallelProgrammingDemo.Entities;
using System.Diagnostics;

namespace ParallelProgrammingDemo.Calculators
{
    public class ParallelDistanceCalculator : IDistanceCalculator
    {
        /// <summary>
        /// Evaluates the distance between the according vectors and the overall running time
        /// </summary>
        /// <param name="QueryVectors">first set of vectors</param>
        /// <param name="DatasetVectors">second set of vectors </param>
        /// <returns></returns>
        public ComputationResult<float> GetComputationResult(ComputationRequest<float> request)
        {
            var stopwatch = new Stopwatch();
            stopwatch.Start();

            var distanceMatrix = this.GetDistanceMatrix(request);

            stopwatch.Stop();


            return new ComputationResult<float>(distanceMatrix, stopwatch.Elapsed.ToString());
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

            Matrix<float> datasetMatrix = (Matrix<float>)request.DatasetVectors.Clone();
            Matrix<float> querySetMatrix = (Matrix<float>)request.QueryVectors.Clone();
            
            for(int i=0; i<querySetMatrix.Height; i++)
            {
                var list = datasetMatrix.AsParallel().Select(row => request.CalculateDistance(querySetMatrix[i], row)).ToList();
                distanceMatrix[i] = list;
            }

            return distanceMatrix;
        }
    }
}
