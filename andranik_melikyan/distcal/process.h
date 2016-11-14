#pragma once

#include "config.h"

#include "calculation/engine.h"
#include "dataset.h"

namespace distcal
{
   class Process
   {
   public:
      Process( int argc, char* argv[] );
      void run();

   private:
      config::Config m_config;

      DataSet m_dataset;
      DataSet m_queries;
      DataSet m_result;

      calculation::Engine m_engine;
   };

}; //namespace distcal