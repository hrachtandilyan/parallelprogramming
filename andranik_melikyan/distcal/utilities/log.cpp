#include "log.h"

#include <fstream>

namespace distcal
{
	Log* Log::m_instance;

   void Log::init(Level verbosity, const std::ostream& out)
   {
      m_verbosity = verbosity;
      m_stream = std::auto_ptr<std::ostream>(new std::ostream(out.rdbuf()));
   }

	void Log::init(Level verbosity, std::string filename)
	{
      m_verbosity = verbosity;
      m_stream = std::auto_ptr<std::ostream>(new std::ofstream(filename));
	}

   Log::Buffer Log::log()
   {
      return Buffer(Log::instance().m_stream);
   }

   Log::Buffer Log::fatal()
   {
      if( Log::disabled( Level::FATAL ) )
         return Buffer();
      return Buffer(Log::instance().m_stream, "FATAL:   ");
   }

   Log::Buffer Log::error()
   {
      if( Log::disabled( Level::ERROR ) )
         return Buffer();
      return Buffer(Log::instance().m_stream, "ERROR:   ");
   }

   Log::Buffer Log::warning()
   {
      if( Log::disabled( Level::WARNING ) )
         return Buffer();
      return Buffer(Log::instance().m_stream, "WARNING: ");
   }

	Log::Buffer Log::info()
	{
      if( Log::disabled( Level::INFO ) )
         return Buffer();
		return Buffer(Log::instance().m_stream, "INFO:    ");
	}

   Log::Buffer Log::debug()
   {
      if( Log::disabled( Level::DEBUG ) )
         return Buffer();
      return Buffer(Log::instance().m_stream, "DEBUG:   ");
   }

}; //namespace distcal