using DistanceCalculator.Entities;
using DistanceCalculator.Interfaces;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DistanceCalculator.Functionalities
{
    public class Initializer : IInitializer
    {
        
        public List<Vector> GetRandomVectors(int numberOfVectors = 1024)
        {
            var vectors = new List<Vector>(numberOfVectors); 
            for (var i = 0; i < numberOfVectors; ++i)
            {
                vectors[0].Elements = GetRandomVector();
            }
            return vectors;
        }
        public List<Vector> GetVectorsFromCSVs(string pathToFileTemplate, int numberOfFiles)
        {
            var vectors = new List<Vector>(numberOfFiles);
            for (var i = 0; i < numberOfFiles; ++i)
            {
                GetVectorFromCSV(pathToFileTemplate + (i + 1).ToString());
            }
            return vectors;
        }

        // Load a CSV file into an array of rows and columns.
        // Assume there may be blank lines but every line has
        // the same number of fields.
        public List<Vector> GetVectorsFromCSV(string pathToFile)
        {
            // Get the file's text.
            string file = System.IO.File.ReadAllText(pathToFile);

            // Split into lines.
            file = file.Replace('\n', '\r');
            string[] lines = file.Split(new char[] { '\r' },
                StringSplitOptions.RemoveEmptyEntries);

            // Get number of rows and columns.
            int numumberOfRows = lines.Length;
            int numberOfcolumns = lines[0].Split(',').Length;

            var vectors = new List<Vector>(numberOfcolumns);

            // Load the array.
            for (int row = 0; row < numumberOfRows; row++)
            {
                string[] lineRow = lines[row].Split(',');
                vectors[row].Elements = new List<float>(numberOfcolumns);
                for (int column = 0; column < numberOfcolumns; column++)
                {
                    float temp;
                    float.TryParse(lineRow[column], out temp);
                    vectors[row].Elements[column] = temp;
                }
            }

            return vectors;
        }

        private List<float> GetRandomVector(int vectorLength = 512)
        {
            var vector = new List<float>(vectorLength);
            for (var i = 0; i < vectorLength; ++i)
            {
                vector[i] = this.GetRandomNumber();
            }
            return vector;
        }

        private float GetRandomNumber()
        {
            Random random = new Random();
            double mantissa = (random.NextDouble() * 2.0) - 1.0;
            double exponent = Math.Pow(2.0, random.Next(-126, 128));
            return (float)(mantissa * exponent);
        }
        private List<float> GetVectorFromCSV(string pathToFile, int vectorLenth = 512)
        {
            var vector = new List<float>(vectorLenth);
            using (StreamReader sr = new StreamReader(@pathToFile))
            {
                string[] columns = { };
                while (!sr.EndOfStream)
                {
                    Console.WriteLine("Reading...");
                    string str = sr.ReadLine();
                    columns = str.Split('\t');
                    //vectors.Add(columns[0]);
                    float temp;
                    float.TryParse(columns[0], out temp);
                    vector.Add(temp);
                }
            }
            if (vector[0] == default(float))
            {
                vector = GetRandomVector();
            }
            return vector;
        }
    }
}
