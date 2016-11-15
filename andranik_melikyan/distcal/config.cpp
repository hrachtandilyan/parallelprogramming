#include "config.h"

namespace distcal
{
   namespace config
   {
      const Log::Level  default_verbosity = Log::Level::DEBUG;
      const std::string default_log_filename = "";
      const std::string default_query_filename = "";
      const std::string default_data_filename = "";
      const size_t      default_query_count = 100;
      const size_t      default_data_count = 100;
      const size_t      default_vector_dimension = 512;

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
         data_filename =    getParam<std::string> ("d", default_data_filename);
         query_count =      getParam<size_t> ("Q", default_query_count );
         data_count =       getParam<size_t> ("D", default_data_count );
         vector_dimension = getParam<size_t>("s", default_vector_dimension);
      }

      std::ostream& operator <<( std::ostream& out, const Config& rhs )
      {
         out << "Configuration\n";
         out << "Verbosity        = [" << rhs.verbosity        << "]\n";
         out << "Log Filename     = [" << rhs.log_filename     << "]\n"; 
         out << "Query Filename   = [" << rhs.query_filename   << "]\n"; 
         out << "Data Filename    = [" << rhs.data_filename    << "]\n";
         out << "Query Count      = [" << rhs.query_count      << "]\n"; 
         out << "Data Count       = [" << rhs.data_count       << "]\n"; 
         out << "Vector Dimension = [" << rhs.vector_dimension << "]";
         return out;
      }

   }; //namespace config
}; //namespace distcal