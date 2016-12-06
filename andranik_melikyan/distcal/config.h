#pragma once

#include <ostream>
#include <string>

#include <vector>

#include "utilities/log.h"

namespace distcal
{
   namespace config
   {
      /// @brief Helper class for storing and parsing command line arguments
      class CommandLine
      {
      public:
         CommandLine(int argc, char* argv[]);

         std::string getParam(char flag, std::string defaultValue);
         size_t      getParam(char flag, size_t      defaultValue);
         bool        getParam(char flag, bool        defaultValue);
         Log::Level  getParam(char flag, Log::Level  defaultValue);

      private:
         std::vector<std::string> m_args;

         int toInt(const std::string& line);
         std::vector<std::string>::const_iterator get(char flag);
      };

      /// @brief Holds all the configurable values 
      struct Config
      {
      public:
         /// @brief Parses command line parameters and sets appropriate values
         /// 
         /// Also initalizes logging
         Config(int argc, char* argv[]);

      private:
         CommandLine commandline;

      public:
         Log::Level  verbosity;
         std::string log_filename;
         std::string data_filename;
         std::string query_filename;
         size_t      data_count;
         size_t      query_count;
         size_t      vector_dimension;
      };

      std::ostream& operator <<( std::ostream& out, const Config& rhs );

   }; //namespace config
}; //namespace distcal