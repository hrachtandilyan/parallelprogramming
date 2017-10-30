using DistanceCalculator.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DistanceCalculator.Interfaces
{
    public interface IInitializer
    {
        List<Vector> GetRandomVectors(int numberOfVectors = 1024);
        List<Vector> GetVectorsFromCSVs(string pathToFileTemplate, int numberOfFiles);
    }
}
