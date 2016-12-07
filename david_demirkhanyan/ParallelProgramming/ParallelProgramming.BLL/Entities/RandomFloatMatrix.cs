using ParallelProgramming.BLL.Helpers;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgramming.BLL.Entities
{
    public class RandomFloatMatrix : Matrix<float>
    {
        public RandomFloatMatrix() : base()
        {
            this.RandomizeMatrix();
        }

        /// <summary>
        /// Randomizes matrix
        /// </summary>
        protected void RandomizeMatrix()
        {
            Random rand = new Random();

            //magic 
            var NextFloat = new Func<Random, float>((random) =>
            {
                return (float)(ConfigurationHelper.Instance.MaxFloatValue * 2.0 * (random.NextDouble() - 0.5));
            });

            for(int i=0; i<Height; i++)
            {
                for(int j=0; j<Width; j++)
                {
                    matrixValues[i][j] = NextFloat(rand);
                }
            }
        }
    }
}
