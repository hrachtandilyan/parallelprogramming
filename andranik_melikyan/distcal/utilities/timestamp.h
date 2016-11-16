#pragma once

#include <ostream>
#include <string>

#include <chrono>


namespace distcal
{
   class Timestamp
   {
   public:
      Timestamp();
      Timestamp( std::chrono::time_point<std::chrono::system_clock> ms );

      int mlsec() const { return m_mlsec; }
      int   sec() const { return m_rest.tm_sec; }
      int   min() const { return m_rest.tm_min; }
      int  hour() const { return m_rest.tm_hour; }
      int  mday() const { return m_rest.tm_mday; }
      int   mon() const { return m_rest.tm_mon; }
      int  year() const { return m_rest.tm_year + 1900; }

      std::string getSignature() const;

   private:
      long long m_absoulte;
      int m_mlsec;
      tm m_rest;
   };

   std::ostream& operator <<( std::ostream& out, const Timestamp& rhs );

}; //namespace distcal