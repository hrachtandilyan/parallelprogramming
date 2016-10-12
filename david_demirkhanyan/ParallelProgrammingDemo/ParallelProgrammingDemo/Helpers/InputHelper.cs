using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ParallelProgrammingDemo.Entities;


namespace ParallelProgrammingDemo.Helpers
{
    public class InputHelper<T>
    {
        /// <summary>
        /// Instatiates the Query Vector Set and Data Vector sets
        /// </summary>
        /// <param name="querySetFilePath">optional parameter, if set to null will read default query set file or randomize input</param>
        /// <param name="dataSetFilePath">optional parameter, if set to null will read default data set file or randomize input</param>
        /// <returns></returns>
        public ComputationRequest<T> GetQueryAndDistanceMatrix(string querySetFilePath = null, string dataSetFilePath = null)
        {
            var computationRequest = new ComputationRequest<T>();

            var fillMatrix = new Action<Matrix<T>, string, bool, string>((target, providedPath, isDefaultEnabled, defaultPath) =>
            {
                if(!String.IsNullOrEmpty(providedPath))
                {
                    target = this.ParseCSVFile(providedPath);
                }
                else if(String.IsNullOrEmpty(providedPath) && isDefaultEnabled)
                {
                    target = this.ParseCSVFile(defaultPath);
                }
                else
                {
                    this.GenerateRandomMatrix();
                }
            });

            fillMatrix(computationRequest.QueryVectors, querySetFilePath, 
                       ConfigurationHelper.Instance.DefaultFilesEnabled, ConfigurationHelper.Instance.QuerySetFilePath);

            fillMatrix(computationRequest.DatasetVectors, dataSetFilePath,
                      ConfigurationHelper.Instance.DefaultFilesEnabled, ConfigurationHelper.Instance.DataSetFilePath);

            return computationRequest;
        }

        /// <summary>
        /// Generates a random matrix
        /// </summary>
        /// <param name="height">optional height parameter</param>
        /// <param name="width">optional width parameter</param>
        /// <returns></returns>
        private Matrix<float> GenerateRandomMatrix(int height = 1024, int width = 512)
        {
            var matrix = new Matrix<float>(height, width);
        
            //TO-DO: randomize Matrix

            return matrix;
        }

        /// <summary>
        /// parses a CSV file to a T type Matrix
        /// </summary>
        /// <param name="filePath">absolute path to the csv file</param>
        /// <returns></returns>
        private Matrix<T> ParseCSVFile(string filePath)
        {
            var matrix = new Matrix<T>();

            //TO-DO: Implement parsing logic

            return matrix;
        }
    }
}
