#include "config.h"

#include <iostream>
#include <fstream>

#include "utilities/timestamp.h"


namespace distcal
{
   namespace config
   {
      namespace
      {
         bool fileExists(const std::string& file)
         {
            std::ifstream test(file);
            return test.good();
         }

         std::string generateLogFilename()
         {
            std::string name;
            std::string sign = Timestamp(std::chrono::system_clock::now()).getSignature();
            char suffix = '0';
            do
            {
               name = "Log\\log_" + sign + ".txt";
               sign = sign + "_" + (++suffix);     // correct, unless the program is launched more than 10 times in one second, which is quite hard to do
            }
            while( fileExists(name) );
            return name;
         }
         
         template <class T>
         T getParam( const std::string& name, T defaultValue )
         {
            //get_opts, validation and processing
            return defaultValue;
         }

         const Log::Level  default_verbosity        = Log::Level::INFO;
         const std::string default_log_filename     = "";
         const std::string default_query_filename   = "";
         const std::string default_data_filename    = "";
         const size_t      default_query_count      = 1024;
         const size_t      default_data_count       = 1024;
         const size_t      default_vector_dimension = 512;
      }

      Config::Config(int argc, char* argv[]):
         verbosity        ( getParam<Log::Level>  ("v", default_verbosity) ),
         log_filename     ( getParam<std::string> ("l", default_log_filename) ),
         query_filename   ( getParam<std::string> ("q", default_query_filename) ),
         data_filename    ( getParam<std::string> ("d", default_data_filename) ),
         query_count      ( getParam<size_t>      ("Q", default_query_count) ),
         data_count       ( getParam<size_t>      ("D", default_data_count) ),
         vector_dimension ( getParam<size_t>      ("s", default_vector_dimension) )
      {
         if( log_filename.empty() )
            log_filename = generateLogFilename();
         Log::instance().init(verbosity, std::cout);
      }

      std::ostream& operator <<( std::ostream& out, const Config& rhs )
      {
         out << "configuration\n";
         out << "\tVerbosity        = <" << rhs.verbosity        << ">\n";
         out << "\tLog Filename     = <" << rhs.log_filename     << ">\n"; 
         out << "\tQuery Filename   = <" << rhs.query_filename   << ">\n"; 
         out << "\tData Filename    = <" << rhs.data_filename    << ">\n";
         out << "\tQuery Count      = <" << rhs.query_count      << ">\n"; 
         out << "\tData Count       = <" << rhs.data_count       << ">\n"; 
         out << "\tVector Dimension = <" << rhs.vector_dimension << ">";
         return out;
      }

   }; //namespace config
}; //namespace distcal