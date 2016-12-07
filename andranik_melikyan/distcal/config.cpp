#include "config.h"

#include <fstream>
#include <sstream>

#include "utilities/exception.h"
#include "utilities/timestamp.h"


namespace distcal
{
   namespace config
   {
      namespace
      {
         int toInt(const std::string& line)
         {
            int result;
            std::istringstream integer(line + " ");
            integer >> result;

            if (!integer.good())
            {
               throw CommandLineException("Invalid integer " + line);
            }

            return result;
         }

      }; //namespace

      CommandLine::CommandLine(int argc, char* argv[])
      {
         for (int i = 0; i < argc; ++i)
         {
            m_args.push_back(argv[i]);
         }
      }

      std::string CommandLine::getParam(const Flag& flag, std::string defaultValue)
      {
         auto it = get(flag);
         if( it == m_args.end() )
            return defaultValue;

         return *it;
      }

      size_t CommandLine::getParam(const Flag& flag, size_t defaultValue)
      {
         auto it = get(flag);
         if( it == m_args.end() )
            return defaultValue;

         int size = toInt(*it);
         if( size < 0 )
         {
            throw CommandLineException("Negative size not allowed");
         }

         return size;
      }

      Log::Level CommandLine::getParam(const Flag& flag, Log::Level defaultValue)
      {
         auto it = get(flag);
         if( it == m_args.end() )
            return defaultValue;

         int level = toInt(*it);
         if( level < Log::Level::FATAL || level > Log::Level::DEBUG )
         {
            throw CommandLineException("Invalid verbosity level");
         }

         return Log::Level(level);
      }

      bool CommandLine::getParam(const Flag& flag, bool defaultValue)
      {
         auto it = get(flag, false);
         if (it == m_args.end())
            return defaultValue;

         return true;
      }

      std::vector<std::string>::const_iterator CommandLine::get(const Flag& flag, bool expectValue)
      {
         auto it = find(m_args.begin(), m_args.end(), flag.getShort());
         if (it == m_args.end())
         {
            it = find(m_args.begin(), m_args.end(), flag.getLong());
            if (it == m_args.end())
            {
               return it;
            }
         }

         if (expectValue)
         {
            ++it;
            if (it == m_args.end())
            {
               throw CommandLineException("No value for parameter " + flag.getShort() + "/" + flag.getLong());
            }
         }

         return it;
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

         const Log::Level  default_verbosity      = Log::Level::INFO;
         const std::string default_log_filename   = "";
         const std::string default_data_filename  = "";
         const std::string default_query_filename = "";
         const size_t      default_data_count     = 1024;
         const size_t      default_query_count    = 1024;
         const size_t      default_dimension      = 512;
         const bool        default_console_log    = false;

      }; //namespace

      Config::Config(int argc, char* argv[])
         :commandline(argc, argv),
          verbosity      (commandline.getParam(Flag("v", "verbosity"),     default_verbosity) ),
          log_filename   (commandline.getParam(Flag("l", "log-file"),      default_log_filename) ),
          data_filename  (commandline.getParam(Flag("D", "data-file"),     default_data_filename) ),
          query_filename (commandline.getParam(Flag("Q", "queries-file"),  default_query_filename) ),
          data_count     (commandline.getParam(Flag("d", "data-count"),    default_data_count) ),
          query_count    (commandline.getParam(Flag("q", "queries-count"), default_query_count) ),
          dimension      (commandline.getParam(Flag("s", "dimension"),     default_dimension) ),
          console_log    (commandline.getParam(Flag("" , "console-log"),   default_console_log) )
      {  
         if (!console_log)
         {
            if (log_filename.empty())
               log_filename = generate_log_filename();
            Log::instance().init(verbosity, log_filename);
         }
         else 
         {
            Log::instance().init(verbosity, std::cout);
         }
      }

      std::ostream& operator <<( std::ostream& out, const Config& rhs )
      {
         out << "configuration\n";
         out << "\tVerbosity        = <" << rhs.verbosity       << ">\n";
         out << "\tLog Filename     = <" << rhs.log_filename    << ">\n"; 
         out << "\tData Filename    = <" << rhs.data_filename   << ">\n";
         out << "\tQuery Filename   = <" << rhs.query_filename  << ">\n"; 
         out << "\tData Count       = <" << rhs.data_count      << ">\n"; 
         out << "\tQuery Count      = <" << rhs.query_count     << ">\n"; 
         out << "\tVector Dimension = <" << rhs.dimension       << ">\n";
         out << "\tConsole Logging  = <" << rhs.console_log     << ">";
         return out;
      }

   }; //namespace config
}; //namespace distcal