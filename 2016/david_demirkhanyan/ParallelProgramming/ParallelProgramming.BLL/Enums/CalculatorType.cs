using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgramming.BLL.Enums
{
    /// <summary>
    /// types of possible distance calculations
    /// </summary>
    public enum CalculatorType
    {
       SYNC, 
       PARALLEL,
       MPI, 
       CUDA
    }
}
