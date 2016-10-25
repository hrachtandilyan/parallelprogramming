#pragma once

#include "config.h"

namespace distcal
{
   namespace config
   {
      const std::string defaultQueryFilename = "";
      const std::string defaultDatasetFilename = "";
      const int         defaultVectorSize = 512;
      const int         defaultQueryCount = 1024;
      const int         defaultDatasetCount = 1024;

      template <class T> 
      T getParam(const std::string& name, T defaultValue)
      {
         //get_opts, validation and processing
         return defaultValue;
      }

      Config::Config(int argc, char* argv[])
      {
         queryFilename =   getParam<std::string> ("-q", defaultQueryFilename);
         datasetFilename = getParam<std::string> ("-d", defaultDatasetFilename);
         vectorSize =      getParam<int> ("-s", defaultVectorSize);
         queryCount =      getParam<int> ("-Q", defaultQueryCount);
         datasetCount =    getParam<int> ("-D", defaultDatasetCount);
      }

   }; //namespace config
}; //namespace distcal