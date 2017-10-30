using DistanceCalculator.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DistanceCalculator.Interfaces
{
    public interface IDistanceCalculator
    {
        float[,] CalculateHammingDistance(List<Vector> queryVectors, List<Vector> datasetVectors);
        float[,] CalculateL1Distance(List<Vector> queryVectors, List<Vector> datasetVectors);
        float[,] CalculateL2Distance(List<Vector> queryVectors, List<Vector> datasetVectors);
    }
}
