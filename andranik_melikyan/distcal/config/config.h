#pragma once

#include <iostream>
#include <string>

#include "../utilities/log.h"
#include "cmdline.h"

namespace distcal
{
   namespace config
   {
      namespace
      {
         const size_t      default_verbosity      = Log::Level::INFO;
         const std::string default_log_filename   = "";
         const std::string default_data_filename  = "";
         const std::string default_query_filename = "";
         const size_t      default_data_count     = 1024;
         const size_t      default_query_count    = 1024;
         const size_t      default_dimension      = 512;
         const bool        default_console_log    = false;

      }; //namespace

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
         size_t      verbosity;
         bool        console_log;
         std::string log_filename;
         std::string data_filename;
         size_t      data_count;
         std::string query_filename;
         size_t      query_count;
         size_t      dimension;
      };

      std::ostream& operator <<( std::ostream& out, const Config& rhs );

   }; //namespace config
}; //namespace distcal