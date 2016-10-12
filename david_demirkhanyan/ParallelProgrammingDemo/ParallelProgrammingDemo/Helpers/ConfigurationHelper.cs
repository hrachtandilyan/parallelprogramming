using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgrammingDemo.Helpers
{
    public class ConfigurationHelper
    {
        #region Singleton
        private static readonly Lazy<ConfigurationHelper> lazy = new Lazy<ConfigurationHelper>(() => new ConfigurationHelper());

        public static ConfigurationHelper Instance
        {
            get
            {
                return lazy.Value;
            }
        }
        #endregion

        public string QuerySetFilePath { get; }
        public string DataSetFilePath { get; }
       
        public bool DefaultFilesEnabled { get; }

        private ConfigurationHelper()
        {
            QuerySetFilePath = ConfigurationManager.AppSettings["DefaultQueryVectorsFilePath"];
            DataSetFilePath = ConfigurationManager.AppSettings["DefaultDatasetVectorsFilePath"];

            DefaultFilesEnabled = Convert.ToBoolean(ConfigurationManager.AppSettings["AreDefaultFilesEnabled"]);
        }
    }
}
