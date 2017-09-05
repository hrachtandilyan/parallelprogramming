using ParallelProgramming.BLL.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgramming.BLL.Calculators
{
    public interface IDistanceCalculator
    {
        ComputationResult<float> GetComputationResult(ComputationRequest<float> request);

        Matrix<float> GetDistanceMatrix(ComputationRequest<float> request);
    }
}
