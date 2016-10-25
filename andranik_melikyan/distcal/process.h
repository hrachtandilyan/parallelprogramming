#pragma once

#include <iomanip>

#include "config.h"
#include "calculation/engine.h"
#include "utilities/types.h"

namespace distcal
{
   class Process
   {
   public:
      Process( int argc, char* argv[] );
      void run();

   private:
      config::Config m_config;

      types::DataSet m_dataset;
      types::DataSet m_queries;
      types::DataSet m_result;

      calculation::Engine m_engine;
   };

}; //namespace distcalc

