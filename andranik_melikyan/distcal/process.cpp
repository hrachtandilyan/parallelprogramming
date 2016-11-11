#include "process.h"

#include <iostream>

namespace distcal
{
   Process::Process( int argc, char* argv[] )
      :m_config( argc, argv ), 
       m_dataset( m_config.datasetCount, m_config.vectorSize ),
       m_queries( m_config.queryCount, m_config.vectorSize ), 
       m_result( m_config.datasetCount, m_config.queryCount ),
       m_engine( m_dataset, m_queries, m_result )
   {
      /*
      m_config.queryFilename = "queries.txt";         // temporary for testing
      m_config.datasetFilename = "dataset.txt";       //
      m_config.datasetCount = 3;                      //
      m_config.queryCount = 2;                        //
      m_config.vectorSize = 3;                        //
      */
   };

   void Process::run()
   {
      m_dataset.fetch( m_config.datasetFilename );
      m_queries.fetch( m_config.queryFilename );

      m_engine.start();

      std::cout << m_result << std::endl;
   }

}; //namespace distcal