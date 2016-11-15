#include "performance.h"

#include "log.h"

namespace distcal
{
   void Timer::start()
   {
      m_start = std::chrono::high_resolution_clock::now();
   }

   void Timer::stop()
   {
      m_duration = std::chrono::high_resolution_clock::now() - m_start;
   }

   std::chrono::microseconds Timer::duration()
   {
      return std::chrono::duration_cast<std::chrono::microseconds>(m_duration);
   }

   void Performance::start()
   {
      m_global.start();
   }

   void Performance::stop()
   {
      m_global.stop();
      m_result.m_total = (double)m_global.duration().count();
   }

   int Performance::registerIteration()
   {
      int id;
      if( m_free.empty() )
      {
         m_iterations.push_back( Timer() );
         id = m_iterations.size() - 1;
      }
      else
      {
         id = m_free.front();
         m_free.pop();
      }

      m_iterations[id].start();
      return id;
   }

   void Performance::endIteration( int id )
   {
      m_iterations[id].stop();
      m_free.push( id );

      //Avg(n + 1) = Avg(n) / (n + 1) * n + a[n + 1] / (n + 1)  
      m_result.m_average = m_result.m_average / (m_result.m_count + 1) * m_result.m_count + (double)m_iterations[id].duration().count() / ( m_result.m_count + 1 );           
      ++m_result.m_count;
   }

}; //namespace distcal