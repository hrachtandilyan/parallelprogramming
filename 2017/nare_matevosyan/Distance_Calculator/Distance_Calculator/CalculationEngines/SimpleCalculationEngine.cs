using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Distance_Calculator.FileOperations;
using Distance_Calculator.Models;
using Distance_Calculator.Timing;
using System.Threading;
using Timer = Distance_Calculator.Timing.Timer;

namespace Distance_Calculator.CalculationEngines
{
    public class SimpleCalculationEngine
    {
        private Logger logger;
        private const string EngineName = "Simple";
        private const string ImplementationL1 = "L1";
        private const string ImplementationL2 = "L2";
        private const string ImplementationHamming = "Hamming";

        public void Calculate(VectorsListModel queryVectorsList, VectorsListModel datasetVectorsList)
        {
            logger = new Logger();
            logger.LogToProgram($"Started {EngineName} engine.");

            //Log to Program.txt
            //Thread for L1
            logger.LogToProgram($"Starting {ImplementationL1} of {EngineName} engine.");
            new Thread(() => 
                CalculateL1(queryVectorsList, datasetVectorsList)
            ).Start();

            //Log to Program.txt
            //Thread for L2
            logger.LogToProgram($"Starting {ImplementationL2} of {EngineName} engine.");
            new Thread(() =>
                CalculateL2(queryVectorsList, datasetVectorsList)
            ).Start();

            //Log to Program.txt
            //Thread for Hamming
            logger.LogToProgram($"Starting {ImplementationHamming} of {EngineName} engine.");
            new Thread(() =>
                CalculateHamming(queryVectorsList, datasetVectorsList)
            ).Start();

        }

        #region L1 Implementation

         private void CalculateL1(VectorsListModel queryVectorsList, VectorsListModel datasetVectorsList)
        {
            //Log to SimpleEngineL1Log.txt
            const string implementationName = ImplementationL1;
            logger.ImplementationLogDelete(EngineName, implementationName);
            logger.LogToImplementation($"Started {implementationName} of {EngineName}.", EngineName, implementationName);

            var sumDoubles = new double[queryVectorsList.VectorsCount, datasetVectorsList.VectorsCount];

            var timer = new Timer();
            timer.Start();

            foreach (var queryVector in queryVectorsList.Vectors)
            {
                foreach (var datasetVector in datasetVectorsList.Vectors)
                {
                    var queryVectorIndex = queryVectorsList.Vectors.IndexOf(queryVector);
                    var datasetVectorIndex = datasetVectorsList.Vectors.IndexOf(datasetVector);

                    var pairTimer = new Timer();
                    pairTimer.Start();

                    var value = sumDoubles[queryVectorIndex, datasetVectorIndex] = CalculateL1(queryVector, datasetVector);

                    var elapsedPair = pairTimer.Stop();
                    logger.LogToImplementation($"Calculated [{implementationName}] distance of rows: " +
                                               $"( {queryVectorIndex}, {datasetVectorIndex} )" +
                                               $" in {elapsedPair}ms: {value}.", EngineName, implementationName);

                }
            }
            var elapsed = timer.Stop();

            logger.LogToImplementation($"Finished calculating {implementationName} of {EngineName} in {elapsed}ms.", EngineName, implementationName);
            var output = new Output();
            output.WriteMatrixToCsv(sumDoubles, $"{implementationName}{EngineName}");
        }

        private double CalculateL1(VectorModel queryVector, VectorModel datasetVector)
        {
            //distance = Sum|qi-di|
            double sum = 0;
            foreach (var queryVectorCoordinate in queryVector.Coordinates)
            {
                foreach (var datasetVectorCoordinate in datasetVector.Coordinates)
                {
                    sum = sum + Math.Abs(queryVectorCoordinate - datasetVectorCoordinate);
                }
            }
            return sum;
        }

        #endregion

        #region L2 Implementation

        private void CalculateL2(VectorsListModel queryVectorsList, VectorsListModel datasetVectorsList)
        {
            const string implementationName = ImplementationL2;
            logger.ImplementationLogDelete(EngineName, implementationName);
            logger.LogToImplementation($"Started {implementationName} of {EngineName}.", EngineName, implementationName);

            var sumDoubles = new double[queryVectorsList.VectorsCount, datasetVectorsList.VectorsCount];

            var timer = new Timer();
            timer.Start();

            foreach (var queryVector in queryVectorsList.Vectors)
            {
                foreach (var datasetVector in datasetVectorsList.Vectors)
                {
                    var queryVectorIndex = queryVectorsList.Vectors.IndexOf(queryVector);
                    var datasetVectorIndex = datasetVectorsList.Vectors.IndexOf(datasetVector);

                    var pairTimer = new Timer();
                    pairTimer.Start();

                    var value = sumDoubles[queryVectorIndex, datasetVectorIndex] = CalculateL2(queryVector, datasetVector);

                    var elapsedPair = pairTimer.Stop();
                    logger.LogToImplementation($"Calculated [{implementationName}] distance of rows: " +
                                               $"( {queryVectorIndex}, {datasetVectorIndex} )" +
                                               $" in {elapsedPair}ms: {value}.", EngineName, implementationName);
                }
            }

            var elapsed = timer.Stop();
            logger.LogToImplementation($"Finished calculating {implementationName} of {EngineName} in {elapsed}ms.", EngineName, implementationName);

            var output = new Output();
            output.WriteMatrixToCsv(sumDoubles, $"{implementationName}{EngineName}");
        }

        private double CalculateL2(VectorModel queryVector, VectorModel datasetVector)
        {

            //distance = root(Sum(qi-di)*(qi-di))
            double sum = 0;
            foreach (var queryVectorCoordinate in queryVector.Coordinates)
            {
                foreach (var datasetVectorCoordinate in datasetVector.Coordinates)
                {
                    sum = sum + (queryVectorCoordinate - datasetVectorCoordinate) * (queryVectorCoordinate - datasetVectorCoordinate);
                }
            }
            return Math.Sqrt(sum);
        }

        #endregion

        #region Hamming Implementation

        private void CalculateHamming(VectorsListModel queryVectorsList, VectorsListModel datasetVectorsList)
        {
            const string implementationName = ImplementationHamming;
            logger.ImplementationLogDelete(EngineName, implementationName);
            logger.LogToImplementation($"Started {implementationName} of {EngineName}.", EngineName, implementationName);
            var sumDoubles = new double[queryVectorsList.VectorsCount, datasetVectorsList.VectorsCount];
            var timer = new Timer();
            timer.Start();

            foreach (var queryVector in queryVectorsList.Vectors)
            {
                foreach (var datasetVector in datasetVectorsList.Vectors)
                {
                    var queryVectorIndex = queryVectorsList.Vectors.IndexOf(queryVector);
                    var datasetVectorIndex = datasetVectorsList.Vectors.IndexOf(datasetVector);

                    var pairTimer = new Timer();
                    pairTimer.Start();

                    var value = sumDoubles[queryVectorIndex, datasetVectorIndex] = CalculateHamming(queryVector, datasetVector);

                    var elapsedPair = pairTimer.Stop();
                    logger.LogToImplementation($"Calculated [{implementationName}] distance of rows: " +
                                                $"( {queryVectorIndex}, {datasetVectorIndex} )" +
                                                $" in {elapsedPair}ms: {value}.", EngineName, implementationName);
                }
            }
            var elapsed = timer.Stop();
            logger.LogToImplementation($"Finished calculating {implementationName} of {EngineName} in {elapsed}ms.", EngineName, implementationName);
           
            var output = new Output();
            output.WriteMatrixToCsv(sumDoubles, $"{implementationName}{EngineName}");
        }

        private double CalculateHamming(VectorModel queryVector, VectorModel datasetVector)
        {
            return double.MinValue;
            //todo calculate
        }

        #endregion
    }
}
