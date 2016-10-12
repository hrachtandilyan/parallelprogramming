using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo.Entities
{
    public class ComputationResult<T>
    {
        public Matrix<T> DistanceMatrix { get; }
        public string TotalRuntime { get; }

        public ComputationResult (Matrix<T> distanceMatrix, string totalRuntime)
        {
            DistanceMatrix = distanceMatrix;
            TotalRuntime = totalRuntime;
        }
    }
}
