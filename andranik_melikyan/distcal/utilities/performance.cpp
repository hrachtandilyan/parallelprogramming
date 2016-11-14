#include "performance.h"

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

   std::chrono::milliseconds Timer::duration()
   {
      return std::chrono::duration_cast<std::chrono::milliseconds>(m_duration);
   }

}; //namespace distcal