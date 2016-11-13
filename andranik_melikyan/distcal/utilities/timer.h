#pragma once

#include <chrono>

namespace distcal
{
   class Timer
   {
   public:
      Timer() 
      { }

      void start()
      {
         m_start = std::chrono::high_resolution_clock::now();
      }

      void stop()
      {
         m_duration = std::chrono::high_resolution_clock::now() - m_start;
      }

      std::chrono::milliseconds duration()
      {
         return std::chrono::duration_cast<std::chrono::milliseconds>(m_duration);
      }

      std::chrono::duration<float> m_duration;
      std::chrono::high_resolution_clock::time_point m_start;
   };
}; //namespace distcal