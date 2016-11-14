#pragma once

#include <vector>

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
      std::chrono::milliseconds duration();

   private:
      std::chrono::duration<double> m_duration;
      std::chrono::high_resolution_clock::time_point m_start;
   };

   class Performance
   {
   public:
      struct Result
      {
         std::chrono::milliseconds m_total;
         std::chrono::milliseconds m_average;
      };

   public:
      Performance();

      void start();
      void stop();

      int startSubAction();
      void stopSubAction(int index);

      Result getResult() { return m_result; }

   private:
      Timer m_global;
      std::vector<Timer> m_actions;

      int m_counter;
      Result m_result;
   };

}; //namespace distcal