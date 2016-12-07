using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ParallelProgramming.BLL.Entities;
using ParallelProgramming.BLL.Calculators;
using ParallelProgramming.BLL.Enums;
using ParallelProgramming.BLL.Helpers;

namespace ParallelProgramming.Tests
{
    [TestClass]
    public class MetricTests
    {
        [TestMethod]
        public void TestHammingSync()
        {
            try
            {
                var computationRequest = InputHelper.Instance.GetQueryAndDistanceMatrix();

                Assert.IsNotNull(computationRequest.CalculateDistance);
                Assert.IsNotNull(computationRequest.DatasetVectors);

                computationRequest.CalculateDistance = MetricFactory.GetDistanceMetric(MetricType.HAMMING);

                var computationResult = DistanceCalculatorFactory.GetCalculator(CalculatorType.SYNC).GetComputationResult(computationRequest);

                Assert.IsNotNull(computationResult.DistanceMatrix);
            }
            catch(Exception ex)
            {
                throw new AssertFailedException();
            }
        }

        [TestMethod]
        public void TestLTwoSync()
        {

        }

        [TestMethod]
        public void TestLOneSync()
        {

        }
    }
}
