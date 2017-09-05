using DistanceCalculator.Models;

namespace DistanceCalculator.Engines
{
    abstract class AbstractCalculatorEngine
    {
        public abstract Matrix CalculateDistance(Matrix m1,Matrix m2);
    }
}
