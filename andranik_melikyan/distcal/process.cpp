#include "process.h"
#include "utilities/log.h"
#include "utilities/time.h"

#include <iostream>
#include <fstream>

namespace distcal
{
   Process::Process( int argc, char* argv[] )
      :m_config( argc, argv ), 
       m_dataset( m_config.dataset_size, m_config.vector_dimension ),
       m_queries( m_config.query_size, m_config.vector_dimension ), 
       m_result( m_config.dataset_size, m_config.query_size ),
       m_engine( m_dataset, m_queries, m_result )
   {
      /*
      m_config.query_filename = "queries.txt";         // temporary for testing
      m_config.dataset_filename = "dataset.txt";       //
      */

	   Log::instance().init(m_config.verbosity, m_config.log_filename);
   };

   void Process::run()
   {
      Log::info() << "I work";

      m_dataset.fetch( m_config.dataset_filename );
      m_queries.fetch( m_config.query_filename );
      Log::info() << "Data fetched, calculating";

      Log::debug() << "Invisible";

      Timer t;
      t.start();
      m_engine.start();
      t.stop();

      Log::info() << "Done: calculated in " << t.duration().count() << "ms";
      std::cout << m_result << std::endl;
   }

}; //namespace distcal