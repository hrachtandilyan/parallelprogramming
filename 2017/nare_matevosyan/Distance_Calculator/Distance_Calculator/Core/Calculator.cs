using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Distance_Calculator.CalculationEngines;
using Distance_Calculator.Models;

namespace Distance_Calculator.Core
{
    public class Calculator
    {
        public void StartCalculation(VectorsListModel queryVectorsList, VectorsListModel datasetVectorsList)
        {
            //TODO start calculations with each engine

            var simpleCalcilationEngine = new SimpleCalculationEngine();
            simpleCalcilationEngine.Calculate(queryVectorsList, datasetVectorsList);

        }
    }
}
