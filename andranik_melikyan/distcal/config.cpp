#include "config.h"

namespace distcal
{
   namespace config
   {
      const Log::Level  default_verbosity = Log::Level::INFO;
      const std::string default_log_filename = "Log\\logfile.txt";
      const std::string default_query_filename = "";
      const std::string default_dataset_filename = "";
      const size_t      default_query_size = 10;
      const size_t      default_dataset_size = 10;
      const size_t      default_vector_dimension = 10;

      template <class T> 
      T getParam(const std::string& name, T defaultValue)
      {
         //get_opts, validation and processing
         return defaultValue;
      }

      Config::Config(int argc, char* argv[])
      {
         verbosity =        getParam<Log::Level> ("v", default_verbosity);
         log_filename =     getParam<std::string> ("l", default_log_filename);
         query_filename =   getParam<std::string> ("q", default_query_filename);
         dataset_filename = getParam<std::string> ("d", default_dataset_filename);
         query_size =       getParam<size_t> ("Q", default_query_size);
         dataset_size =     getParam<size_t> ("D", default_dataset_size);
         vector_dimension = getParam<size_t>("s", default_vector_dimension);
      }

   }; //namespace config
}; //namespace distcal