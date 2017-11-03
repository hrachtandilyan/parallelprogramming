using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Distance_Calculator.Models;

namespace Distance_Calculator.Core
{
    public class Randomizer
    {
        public VectorsListModel GenerateVectorsModel(int vectorLength = 512, int count = 1024)
        {
            var vectorsList = new VectorsListModel();
            vectorsList.Vectors = GenerateVectorsList(vectorLength, count);
            vectorsList.VectorsCount = count;
            vectorsList.VectorsLength = vectorLength;
            return vectorsList;
        }

        #region Private Functions

        private List<VectorModel> GenerateVectorsList(int vectorLength, int count)
        {
            var vectorsList = new List<VectorModel>();
            for (int i = 0; i < count; i++)
            {
                VectorModel vector = GenerateVector(vectorLength);
                vectorsList.Add(vector);
            }
            return vectorsList;
        }

        private VectorModel GenerateVector(int vectorLength)
        {
            Random random = new Random();
            var vector = new VectorModel();
            vector.Coordinates = GenerateCoordinates(random, vectorLength);
            return vector;
        }

        private List<float> GenerateCoordinates(Random random, int vectorLength)
        {
            var coordainates = new List<float>();
            for (int i = 0; i < vectorLength; i++)
            {
                coordainates.Add(GetRandomNumber(random, -100000, +100000));    //default range is too big
            }
            return coordainates;
        }

        private float GetRandomNumber(Random random ,double minimum = float.MinValue, double maximum = float.MaxValue)
        {
            return (float)(random.NextDouble() * (maximum - minimum) + minimum);
        }

        #endregion
        
    }
}
