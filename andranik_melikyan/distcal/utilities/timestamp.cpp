#include "timestamp.h"

#include <sstream>
#include <iomanip>

namespace distcal
{
   namespace
   {
      const int mlsec_in_sec = 1000;
   };

   Timestamp::Timestamp()
      :m_mlsec( 0 ), m_rest { 0 }
   { }

   Timestamp::Timestamp( std::chrono::time_point<std::chrono::system_clock> ms )
      :m_absoulte( std::chrono::duration_cast<std::chrono::milliseconds>(ms.time_since_epoch()).count() ),
      m_mlsec( m_absoulte % mlsec_in_sec )
   {
      time_t now = std::chrono::system_clock::to_time_t( ms );
      localtime_s( &m_rest, &now );
   }

   std::string Timestamp::getSignature() const
   {
      std::ostringstream line;
      line << std::setfill('0');
      line << std::setw( 4 ) << year() << std::setw( 2 ) << mon() << std::setw( 2 ) << mday() << '_' <<
              std::setw( 2 ) << hour() << std::setw( 2 ) << min() << std::setw( 2 ) << sec();
      return line.str();
   }

   std::ostream& operator <<( std::ostream& out, const Timestamp& rhs )
   {
      const char prevFill = out.fill();
      out << std::setfill('0');
      out << std::setw( 2 ) << rhs.hour() << ':' << std::setw( 2 ) << rhs.min() << ':' << std::setw( 2 ) << rhs.sec() << '.' << std::setw( 3 ) << rhs.mlsec();
      out << std::setfill(prevFill);
      return out;
   }

}; //namespace distcal