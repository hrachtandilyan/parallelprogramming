using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo.Entities
{
    public class Matrix<T> : IEnumerable<List<T>> , ICloneable
    {
        protected List<List<T>> matrixValues;
        public int Height { get; protected set; }
        public int Width { get; protected set; }

        /// <summary>
        /// Initializes a matrix of type T
        /// </summary>
        /// <param name="height">default value is 1024</param>
        /// <param name="width">default value is 512</param>
        public Matrix(int height = 1024, int width = 512)
        {
            this.InitializeMatrix(height, width);
            Height = height;
            Width = width;
        }

        /// <summary>
        /// Initializes matrix with given values
        /// </summary>
        /// <param name="matrixValues"></param>
        public Matrix(List<List<T>> matrixValues)
        {
            this.matrixValues = matrixValues;
        }

        /// <summary>
        /// Initializes a matrix with given dimensions and elements equal to zero 
        /// </summary>
        /// <param name="height"></param>
        /// <param name="width"></param>
        private void InitializeMatrix(int height, int width)
        {
            this.matrixValues = new List<List<T>>(height);

            for (int i = 0; i < height; i++)
            {
                matrixValues.Add(new List<T>(new T[width]));
            }
        }

        /// <summary>
        /// Adds an element at this position 
        /// </summary>
        /// <param name="element">element</param>
        /// <param name="verticalIndex">vertical index of the element</param>
        /// <param name="horizontalIndex">horizontal index of the element</param>
        public void AddElement(T element, int verticalIndex,int horizontalIndex)
        {
            if (verticalIndex < Height && horizontalIndex < Width)
            {
                matrixValues[verticalIndex][horizontalIndex] = element;
            }
        }

       

        /// <summary>
        /// Returns the row with the given index
        /// </summary>
        /// <param name="rowIndex">index of the row</param>
        /// <returns></returns>
        public List<T> GetRow(int rowIndex)
        {
            try
            {
                return matrixValues[rowIndex];
            }
            catch (Exception ex)
            {
                throw ex; 
            }
        }

        public int GetIndex(List<T> row)
        {
            try
            {
                return matrixValues.FindIndex(i => i == row);
            }
            catch(Exception ex)
            {
                throw ex;
            }
        }

        //hack
        public List<List<T>> All()
        {
            return matrixValues;
        }
   

        #region IEnumerable implementation 

        public List<T> this[int index]
        {
            get
            {
                if(index < this.Height)
                {
                    return matrixValues[index];
                }
                else
                {
                    throw new IndexOutOfRangeException();
                }
            }
            set
            {
                if(index < this.Height)
                {
                    matrixValues[index] = value;
                }
                else
                {
                    throw new IndexOutOfRangeException();
                }
            }
        }

        public T this[int i, int j]
        {
            get
            {
                if(i < this.Height && j < this.Width)
                {
                    return matrixValues[i][j];
                }
                else
                {
                    throw new IndexOutOfRangeException();
                }
            }
        }

        public IEnumerator<List<T>> GetEnumerator()
        {
            foreach (List<T> row in this.matrixValues)
            {
                yield return row;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return this.GetEnumerator();
        }



        #endregion


        #region ICloneable implementation 

        public object Clone()
        {
            return this.MemberwiseClone();
        }

        #endregion 
    }
}
