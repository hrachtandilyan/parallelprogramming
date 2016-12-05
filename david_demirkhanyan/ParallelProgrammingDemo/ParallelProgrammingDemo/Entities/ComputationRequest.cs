using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo.Entities
{
    public class ComputationRequest<T> 
    {
        public Matrix<T> QueryVectors { get; set; }
        public Matrix<T> DatasetVectors { get; set; }

        public Func<List<T>, List<T>, float> CalculateDistance { get; set; } 

        public ComputationRequest()
        {
            QueryVectors = null;
            DatasetVectors = null;
        }

        public ComputationRequest(Matrix<T> queryVectors, Matrix<T> datasetVectors)
        {
            QueryVectors = queryVectors;
            DatasetVectors = datasetVectors;
        }
    }
}
