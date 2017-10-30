using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DistanceCalculator.Entities
{
    public class Vector
    {
        public List<float> Elements { get; set; }

        public Vector(int numberOfElements)
        {
            Elements = new List<float>(numberOfElements);
        }

        public Vector(List<float> vector)
        {
            Elements = vector;
        }
    }
}
