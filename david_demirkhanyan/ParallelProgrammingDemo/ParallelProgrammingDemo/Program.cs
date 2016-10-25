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
            var options = new Options();

            if(CommandLine.Parser.Default.ParseArguments(args,options))
            {
               
            }
            else
            {
                Console.WriteLine("One or more invalid arguments");
                return;
            }
        }
    }
}
