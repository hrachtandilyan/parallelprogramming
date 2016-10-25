#include "process.h"

#include <iostream>
#include <fstream>

#include "utilities/setfetcher.h"

namespace distcal
{
   Process::Process( int argc, char* argv[] )
      :m_config( argc, argv )
   {
      /*
      m_config.queryFilename = "queries.txt";         //temporary for testing
      m_config.datasetFilename = "dataset.txt";
      m_config.datasetCount = 3;
      m_config.queryCount = 2;
      m_config.vectorSize = 3;                        //
      */
      m_queries = utility::SetFetcher(m_config.queryFilename, m_config.queryCount, m_config.vectorSize).fetch();
      m_dataset = utility::SetFetcher(m_config.datasetFilename, m_config.datasetCount, m_config.vectorSize).fetch();

      m_result = types::DataSet( m_dataset.size(), types::DataVector( m_queries.size() ) );
   };

   void Process::run()
   {
      m_engine.setEngineAndInit( calculation::EngineType::QUADRATIC_TYPE, Metric::MetricType::L2_TYPE, &m_dataset, &m_queries, &m_result );
      m_engine.start();

      utility::outputDataSet( std::cout, m_result );
   }

}; //namespace distcal