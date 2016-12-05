using ParallelProgrammingDemo.Calculators;
using ParallelProgrammingDemo.Entities;
using ParallelProgrammingDemo.Enums;
using ParallelProgrammingDemo.Helpers;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo
{
    class Program
    {

        static void Main(string[] args)
        {
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

                options.ComputationType = CalculatorType.PARALLEL;
                options.MetricType = MetricType.HAMMING;

                var computationRequest = InputHelper.Instance.GetQueryAndDistanceMatrix(options.QueryStringFilePath, options.DataSetFilePath);
                computationRequest.CalculateDistance = MetricFactory.GetDistanceMetric(options.MetricType);

                var result = DistanceCalculatorFactory.GetCalculator(options.ComputationType).GetComputationResult(computationRequest);

                Console.WriteLine(result.TotalRuntime);
            }
        }
    }
}
