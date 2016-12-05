#include "process.h"
#include "utilities/log.h"
#include "utilities/performance.h"

#include <iostream>

namespace distcal
{
   Process::Process( int argc, char* argv[] )
      :m_config( argc, argv ), 
       m_data( m_config.data_count, m_config.vector_dimension ),
       m_queries( m_config.query_count, m_config.vector_dimension ),
       m_result( m_config.data_count, m_config.query_count ),
       m_engine( m_data, m_queries, m_result )
   {
      Log::debug() << m_config;
   };

   void Process::run()
   {
      Log::info() << "fetching data";
      m_data.fetch( m_config.data_filename );
      m_queries.fetch( m_config.query_filename );

      Log::info() << "data fetched, calculating";
      Performance::Result perf = m_engine.calculate();

      Log::info() << "done: [" << perf.m_count << "] iterations in [" << perf.m_total / 1000 << "ms], averaged at [" << perf.m_average << "mcs]";
      Log::debug() << m_result;
   }

}; //namespace distcal