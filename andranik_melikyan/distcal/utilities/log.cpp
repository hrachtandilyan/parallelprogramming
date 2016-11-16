#include "log.h"

#include <fstream>

namespace distcal
{
	Log* Log::m_instance;

   void Log::init(Level level, const std::ostream& out)
   {
      m_level = level;
      m_stream = std::auto_ptr<std::ostream>(new std::ostream(out.rdbuf()));
   }

	void Log::init(Level level, std::string filename)
	{
		m_level = level;
      m_stream = std::auto_ptr<std::ostream>(new std::ofstream(filename));
	}

   Log::Buffer Log::log()
   {
      return Buffer(Log::instance().m_stream, "");
   }

   Log::Buffer Log::fatal()
   {
      if( Log::disabled( Log::FATAL ) )
         return Buffer();
      return Buffer(Log::instance().m_stream, "FATAL:   ");
   }

   Log::Buffer Log::error()
   {
      if( Log::disabled( Log::ERROR ) )
         return Buffer();
      return Buffer(Log::instance().m_stream, "ERROR:   ");
   }

   Log::Buffer Log::warning()
   {
      if( Log::disabled( Log::WARNING ) )
         return Buffer();
      return Buffer(Log::instance().m_stream, "WARNING: ");
   }

	Log::Buffer Log::info()
	{
      if( Log::disabled( Log::INFO ) )
         return Buffer();
		return Buffer(Log::instance().m_stream, "INFO:    ");
	}

   Log::Buffer Log::debug()
   {
      if( Log::disabled( Log::DEBUG ) )
         return Buffer();
      return Buffer(Log::instance().m_stream, "DEBUG:   ");
   }

}; //namespace distcal