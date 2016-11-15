#pragma once

#include <vector>
#include <queue>

#include <chrono>

namespace distcal
{
   class Timer
   {
   public:
      Timer()
      { }

      void start();
      void stop();

      std::chrono::microseconds duration();

   private:
      std::chrono::duration<double> m_duration;
      std::chrono::high_resolution_clock::time_point m_start;
   };

   class Performance
   {
   public:
      struct Result
      {
         Result()
            :m_total(0), m_average(0.), m_count(0)
         { }

         double m_total;
         double m_average;
         long long m_count;
      };

   public:
      Performance()
      { }

      void start();
      void stop();

      int registerIteration();
      void endIteration( int id );

      Result getResult() { return m_result; }

   private:
      Timer m_global;
      std::vector<Timer> m_iterations;
      std::queue<int> m_free;

      Result m_result;
   };

}; //namespace distcal