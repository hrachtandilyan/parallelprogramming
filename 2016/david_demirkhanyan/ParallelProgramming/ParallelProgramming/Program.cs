using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ParallelProgramming.BLL.Calculators;
using ParallelProgramming.Entities;
using ParallelProgramming.BLL.Enums;
using ParallelProgramming.BLL.Helpers;

namespace ParallelProgrammingDemo
{
    class Program
    {

        static void Main(string[] args)
        {
            //temporary solution for testing untill the unit tests are done
            if(!ConfigurationHelper.Instance.TestMode)
            {
                var options = new Options();

                if (CommandLine.Parser.Default.ParseArguments(args, options))
                {
                    var computationRequest = InputHelper.Instance.GetQueryAndDistanceMatrix(options.QueryStringFilePath, options.DataSetFilePath);
                    computationRequest.CalculateDistance = MetricFactory.GetDistanceMetric(options.MetricType);

                    var result = DistanceCalculatorFactory.GetCalculator(options.ComputationType).GetComputationResult(computationRequest);

                    Console.WriteLine(result.TotalRuntime);
                }
                else
                {
                    Console.WriteLine("One or more invalid arguments");
                    return;
                }
            }
            else
            {
                Console.WriteLine("Begin");

                var options = new Options();

                options.ComputationType = CalculatorType.SYNC;
                options.MetricType = MetricType.HAMMING;

                //options.QueryStringFilePath = @"D:\ParallelProgramming\parallelprogramming\david_demirkhanyan\ParallelProgramming\ParallelProgramming.Tests\SampleData\queries.csv";
                //options.DataSetFilePath = @"D:\ParallelProgramming\parallelprogramming\david_demirkhanyan\ParallelProgramming\ParallelProgramming.Tests\SampleData\data.csv";

                var computationRequest = InputHelper.Instance.GetQueryAndDistanceMatrix(options.QueryStringFilePath, options.DataSetFilePath);
                computationRequest.CalculateDistance = MetricFactory.GetDistanceMetric(options.MetricType);

                var result = DistanceCalculatorFactory.GetCalculator(options.ComputationType).GetComputationResult(computationRequest);

                Console.WriteLine(result.TotalRuntime);
            }
        }
    }
}
