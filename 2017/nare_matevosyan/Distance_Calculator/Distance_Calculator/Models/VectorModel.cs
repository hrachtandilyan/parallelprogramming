using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Distance_Calculator.Models
{
    public class VectorModel
    {
        private List<float> coordinates;

        public List<float> Coordinates
        {
            get { return coordinates; }
            set { coordinates = value; }
        }
    }
}
