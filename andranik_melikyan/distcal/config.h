#pragma once

#include <ostream>
#include <string>

#include "utilities/log.h"

namespace distcal
{
   namespace config
   {
      /// @brief Holds all the configurable values 
      struct Config
      {
      public:
         /// @brief Parses command line parameters and sets appropriate values
         Config(int argc, char* argv[]);

         Log::Level verbosity;
         std::string log_filename;
         std::string query_filename;
         std::string data_filename;
         size_t query_count;
         size_t data_count;
         size_t vector_dimension;
      };

      std::ostream& operator <<( std::ostream& out, const Config& rhs );

   }; //namespace config
}; //namespace distcal