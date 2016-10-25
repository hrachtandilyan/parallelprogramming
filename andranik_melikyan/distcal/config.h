#pragma once

#include <string>

namespace distcal
{
   namespace config
   {
      struct Config
      {
      public:
         Config(int argc, char* argv[]);

         std::string queryFilename;
         std::string datasetFilename;
         int vectorSize;
         int queryCount;
         int datasetCount;
      };

   }; //namespace config
}; //namespace distcal