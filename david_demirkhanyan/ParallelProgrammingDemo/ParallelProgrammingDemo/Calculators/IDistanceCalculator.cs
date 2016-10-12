using ParallelProgrammingDemo.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo.Calculators
{
    public interface IDistanceCalculator
    {
        ComputationResult<float> GetComputationResult(ComputationRequest<float> request);

        Matrix<float> GetDistanceMatrix(ComputationRequest<float> request);
    }
}
