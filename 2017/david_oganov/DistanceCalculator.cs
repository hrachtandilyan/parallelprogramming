using DistanceCalculator.Entities;
using DistanceCalculator.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace DistanceCalculator.Functionalities
{
    public class DistanceCalculator : IDistanceCalculator
    {
        public float[,] CalculateHammingDistance(List<Vector> queryVectors, List<Vector> datasetVectors)
        {
            return GetMatrixOfVectors(queryVectors, datasetVectors, CalculateHammingDistance);
        }

        public float[,] CalculateL1Distance(List<Vector> queryVectors, List<Vector> datasetVectors)
        {
            return GetMatrixOfVectors(queryVectors, datasetVectors, CalculateL1Distance);
        }

        public float[,] CalculateL2Distance(List<Vector> queryVectors, List<Vector> datasetVectors)
        {
            return GetMatrixOfVectors(queryVectors, datasetVectors, CalculateL2Distance);
        }

        public void CalculateDistances(List<Vector> queryVectors, List<Vector> datasetVectors)
        {
            var calculations = new Task[3];
            calculations[0] = Task.Factory.StartNew(() => 
            {
                this.CalculateHammingDistance(queryVectors, datasetVectors);
            });

            calculations[1] = Task.Factory.StartNew(() =>
            {
                this.CalculateL1Distance(queryVectors, datasetVectors);
            });

            calculations[2] = Task.Factory.StartNew(() =>
            {
                this.CalculateL2Distance(queryVectors, datasetVectors);
            });

            Task.WaitAll(calculations);

            Console.WriteLine("Calculation successfully completed");
            Console.ReadLine();
        }


        private float CalculateHammingDistance(Vector queryVector, Vector datasetVector)
        {
            var numberOfElements = queryVector.Elements.Count;
            if (numberOfElements == datasetVector.Elements.Count)
            {
                var distance = default(float);
                for (var i = 0; i < numberOfElements; ++i)
                {
                    if (queryVector.Elements[i] != datasetVector.Elements[i])
                    {
                        ++distance;
                    }
                }
                return distance;
            }
            else
            {
                throw new Exception();
            }
        }

        private float CalculateL1Distance(Vector queryVector, Vector datasetVector)
        {
            var numberOfElements = queryVector.Elements.Count;
            if (numberOfElements == datasetVector.Elements.Count)
            {
                var distance = default(float);
                for (var i = 0; i < numberOfElements; ++i)
                {
                    distance += GetAbsoluteValue(queryVector.Elements[i] - datasetVector.Elements[i]);
                }
                return distance;
            }
            else
            {
                throw new Exception();
            }
        }

        private float CalculateL2Distance(Vector queryVector, Vector datasetVector)
        {
            return 0.0f;
        }


        private float[,] GetMatrixOfVectors(List<Vector> queryVectors, List<Vector> datasetVectors, Func<Vector, Vector, float> distanceCalculatingMethod)
        {
            var rows = queryVectors.Count;
            var columns = datasetVectors.Count;
            float[,] distancesMatrix = new float[queryVectors.Count, datasetVectors.Count];
            for (int row = 0; row < rows; row++)
            {
                for (int column = 0; column < columns; column++)
                {
                    distancesMatrix[row, column]
                        = distanceCalculatingMethod(queryVectors[row], datasetVectors[column]);
                }
            }

            return distancesMatrix;
        }

        private float GetAbsoluteValue(float number)
        {
            return number < 0 ? -number : number;
        }
    }
}
