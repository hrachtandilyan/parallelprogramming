using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Distance_Calculator.Models
{
    public class VectorsListModel
    {
        #region Private Members

        private List<VectorModel> vectors;
        private int vectorsCount;
        private int vectorsLength;

        #endregion

        #region Properties

        public List<VectorModel> Vectors
        {
            get { return vectors; }
            set { vectors = value; }
        }

        public int VectorsCount
        {
            get { return vectorsCount; }
            set { vectorsCount = value; }
        }

        public int VectorsLength
        {
            get { return vectorsLength; }
            set { vectorsLength = value; }
        }

        #endregion

        public void Add(VectorModel vector)
        {
            Vectors.Add(vector);
        }
    }
}
