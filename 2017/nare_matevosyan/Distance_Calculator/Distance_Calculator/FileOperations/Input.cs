using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Distance_Calculator.Models;
using CsvHelper;

namespace Distance_Calculator.FileOperations
{
    public class Input
    {
        public VectorsListModel ReadfromCsv(string filePath)
        {
            var vectorsList = new VectorsListModel()
            {
                Vectors = new List<VectorModel>()
            };

            using (TextReader fileReader = File.OpenText(filePath))
            {
                var csv = new CsvReader(fileReader);
                csv.Configuration.HasHeaderRecord = false;

                var records = csv.GetRecords<VectorModel>();   //try to write every row into variable of VactorModel type
                foreach (var record in records)
                {
                   vectorsList.Vectors.Add(record);
                }

                vectorsList.VectorsCount = vectorsList.Vectors.Count;
                vectorsList.VectorsLength = vectorsList.Vectors.First().Coordinates.Count;
            }

            return vectorsList;
        }
    }
}
