#include "config.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "utilities/exception.h"
#include "utilities/timestamp.h"


namespace distcal
{
   namespace config
   {
      CommandLine::CommandLine(int argc, char* argv[])
         :m_args(argc - 1)
      {
         for( int i = 1; i < argc; ++i )
         {
            m_args.push_back(argv[i]);
         }
      }

      std::string CommandLine::getParam(char flag, std::string defaultValue)
      {
         auto it = get(flag);
         if( it == m_args.end() )
            return defaultValue;

         return *++it;
      }

      size_t CommandLine::getParam(char flag, size_t defaultValue)
      {
         auto it = get(flag);
         if( it == m_args.end() )
            return defaultValue;

         int num = toInt(*++it);
         if( num < 0 )
         {
            throw CommandLineException("Negative size not allowed");
         }

         return num;
      }

      bool CommandLine::getParam(char flag, bool defaultValue)
      {
         auto it = get(flag);
         if( it == m_args.end() )
            return defaultValue;

         return true;
      }

      Log::Level CommandLine::getParam(char flag, Log::Level defaultValue)
      {
         auto it = get(flag);
         if( it == m_args.end() )
            return defaultValue;

         ++it;
         int level = toInt(*it);
         if( level < 0 || level > Log::Level::DEBUG )
         {
            throw CommandLineException("Invalid verbosity level");
         }

         return Log::Level(level);
      }

      int CommandLine::toInt(const std::string& line)
      {
         int num;
         std::istringstream iss(line);
         iss >> num;
         return num;
      }

      std::vector<std::string>::const_iterator CommandLine::get(char flag)
      {
         const std::string line = "-";
         return find(m_args.begin(), m_args.end(), std::string(line + flag));
      }

      namespace
      {
         bool file_exists(const std::string& file)
         {
            std::ifstream test(file);
            return test.good();
         }

         std::string generate_log_filename()
         {
            std::string name;
            std::string sign = Timestamp(std::chrono::system_clock::now()).getDatetime();
            char suffix = '0';
            do
            {
               name = "Log\\log_" + sign + ".txt";
               sign = sign + "_" + (++suffix);     // correct, unless the program is launched more than 10 times in one second, which is quite hard to do
            }
            while( file_exists(name) );
            return name;
         }

         const Log::Level  default_verbosity        = Log::Level::INFO;
         const std::string default_log_filename     = "";
         const std::string default_data_filename    = "";
         const std::string default_query_filename   = "";
         const size_t      default_data_count       = 1024;
         const size_t      default_query_count      = 1024
         const size_t      default_vector_dimension = 512;

      }; //namespace

      Config::Config(int argc, char* argv[]):
         commandline      ( argc, argv ),
         verbosity        ( commandline.getParam('v', default_verbosity) ),
         log_filename     ( commandline.getParam('l', default_log_filename) ),
         data_filename    ( commandline.getParam('D', default_data_filename) ),
         query_filename   ( commandline.getParam('Q', default_query_filename) ),
         data_count       ( commandline.getParam('d', default_data_count) ),
         query_count      ( commandline.getParam('q', default_query_count) ),
         vector_dimension ( commandline.getParam('s', default_vector_dimension) )
      {
         if( log_filename.empty() )
            log_filename = generate_log_filename();
         Log::instance().init(verbosity, log_filename);
      }

      std::ostream& operator <<( std::ostream& out, const Config& rhs )
      {
         out << "configuration\n";
         out << "\tVerbosity        = <" << rhs.verbosity        << ">\n";
         out << "\tLog Filename     = <" << rhs.log_filename     << ">\n"; 
         out << "\tData Filename    = <" << rhs.data_filename    << ">\n";
         out << "\tQuery Filename   = <" << rhs.query_filename   << ">\n"; 
         out << "\tData Count       = <" << rhs.data_count       << ">\n"; 
         out << "\tQuery Count      = <" << rhs.query_count      << ">\n"; 
         out << "\tVector Dimension = <" << rhs.vector_dimension << ">";
         return out;
      }

   }; //namespace config
}; //namespace distcal