#include "process.h"
#include "utilities/log.h"

#include <iostream>
#include <fstream>

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
      */

	   Log::instance().init(Log::Level::INFO, "logfile.txt");
   };

   void Process::run()
   {
      Log::Info() << "I work";
      m_dataset.fetch( m_config.datasetFilename );
      m_queries.fetch( m_config.queryFilename );
      Log::Info() << "Data fetched, calculating";
      m_engine.start();
      Log::Info() << "Done\n";

      std::cout << m_result << std::endl;
   }

}; //namespace distcal