#pragma once

#include <string>

#include "utilities/log.h"

namespace distcal
{
   namespace config
   {
      struct Config
      {
      public:
         Config(int argc, char* argv[]);

         Log::Level verbosity;
         std::string log_filename;
         std::string query_filename;
         std::string dataset_filename;
         size_t query_size;
         size_t dataset_size;
         size_t vector_dimension;
      };

   }; //namespace config
}; //namespace distcal