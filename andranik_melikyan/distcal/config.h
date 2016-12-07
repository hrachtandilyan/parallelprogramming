#pragma once

#include <iostream>
#include <string>

#include <vector>

#include "utilities/log.h"

namespace distcal
{
   namespace config
   {
      /// @brief Helper struct for storing configurable flags
      struct Flag
      {
         explicit Flag(const std::string& shortName, const std::string& longName)
            :m_short(shortName), m_long(longName)
         { }

         std::string getShort() const { return ( m_short.empty() ? "" : "-" + m_short ); }
         std::string getLong()  const { return ( m_long.empty()  ? "" : "--" + m_long ); }

      private:
         std::string m_short;
         std::string m_long;
      };

      /// @brief Helper class for storing and parsing command line arguments
      class CommandLine
      {
      public:
         CommandLine(int argc, char* argv[]);

         std::string getParam(const Flag& flag, std::string defaultValue);
         size_t      getParam(const Flag& flag, size_t      defaultValue);
         bool        getParam(const Flag& flag, bool        defaultValue);
         Log::Level  getParam(const Flag& flag, Log::Level  defaultValue);

      private:
         std::vector<std::string> m_args;

         std::vector<std::string>::const_iterator get(const Flag& flag, bool expectValue = true);
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
         size_t      dimension;
         bool        console_log;
      };

      std::ostream& operator <<( std::ostream& out, const Config& rhs );

   }; //namespace config
}; //namespace distcal