using Distance_Calculator.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CsvHelper;

namespace Distance_Calculator.FileOperations
{
    public class Output
    {
        public void WriteMatrixToCsv(double[,] matrix, string name)
        {
            var listColumns = new List<MatrixRow>();
            var columnIndexes = new List<ColumnIndex>();
            var columnIndex = new ColumnIndex();
            columnIndex.ColumnIndexInt = new List<int>();
            columnIndex.ColumnIndexInt.Add(0);
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                var listRows = new MatrixRow();

                listRows.List = new List<double>();
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    listRows.RowIndex = i + 1;
                    listRows.List.Add(matrix[i, j]);
                }
                columnIndex.ColumnIndexInt.Add(i + 1);
                listColumns.Add(listRows);
            }
            columnIndexes.Add(columnIndex);
            using (TextWriter fileWriter = File.CreateText($"{name}.csv"))
            {
                var csv = new CsvWriter(fileWriter);
                csv.Configuration.HasHeaderRecord = false;
                csv.WriteRecords(columnIndexes);
                csv.WriteRecords(listColumns);
                fileWriter.Close();
            }
        }
    }
    class ColumnIndex
    {
        public List<int> ColumnIndexInt { get; set; }
    }
}
