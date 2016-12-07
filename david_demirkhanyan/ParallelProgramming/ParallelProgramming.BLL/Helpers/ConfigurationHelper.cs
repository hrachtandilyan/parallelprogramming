using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParallelProgramming.BLL.Helpers
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

        #region File Settings
        public string QuerySetFilePath { get; }
        public string DataSetFilePath { get; }
        public bool DefaultFilesEnabled { get; }
        #endregion

        #region Program Settings
        //temporary solution for testing untill the unit tests are done
        public bool TestMode { get; }

        public float MaxFloatValue { get; }
        #endregion

        #region Constructor 
        private ConfigurationHelper()
        {
            QuerySetFilePath = ConfigurationManager.AppSettings["DefaultQueryVectorsFilePath"];
            DataSetFilePath = ConfigurationManager.AppSettings["DefaultDatasetVectorsFilePath"];

            DefaultFilesEnabled = Convert.ToBoolean(ConfigurationManager.AppSettings["AreDefaultFilesEnabled"]);

            TestMode = Convert.ToBoolean(ConfigurationManager.AppSettings["TestMode"]);

            MaxFloatValue = (float)Convert.ToDouble(ConfigurationManager.AppSettings["MaxFloatValue"]);
        }
        #endregion 
    }
}
