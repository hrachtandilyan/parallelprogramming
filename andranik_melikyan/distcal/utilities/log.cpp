#include "log.h"

#include <fstream>

namespace distcal
{
   namespace
   {
      const std::string logfileName = "Log\\logfile";
      const std::string logfileExt = ".txt";
   };

	Log* Log::m_instance;

   void Log::init(Level level, const std::ostream& out)
   {
      m_level = level;
      m_stream = std::auto_ptr<std::ostream>(new std::ostream(out.rdbuf()));
   }

	void Log::init(Level level, std::string filename)
	{
		m_level = level;
      
      if( filename.empty() )
      {
         Timestamp now( std::chrono::system_clock::now() );
         filename = logfileName + "_" + now.getSignature() + logfileExt;
      }
      m_stream = std::auto_ptr<std::ostream>(new std::ofstream(filename));
	}

   Log::Buffer Log::log()
   {
      return Buffer(Log::instance().m_stream, "");
   }

   Log::Buffer Log::fatal()
   {
      if (Log::FATAL > Log::instance().m_level)
         return Buffer();
      return Buffer(Log::instance().m_stream, "FATAL:   ");
   }

   Log::Buffer Log::error()
   {
      if (Log::ERROR > Log::instance().m_level)
         return Buffer();
      return Buffer(Log::instance().m_stream, "ERROR:   ");
   }

   Log::Buffer Log::warning()
   {
      if (Log::WARNING > Log::instance().m_level)
         return Buffer();
      return Buffer(Log::instance().m_stream, "WARNING: ");
   }

	Log::Buffer Log::info()
	{
      if (Log::INFO > Log::instance().m_level)
         return Buffer();
		return Buffer(Log::instance().m_stream, "INFO:    ");
	}

   Log::Buffer Log::debug()
   {
      if (Log::DEBUG > Log::instance().m_level)
         return Buffer();
      return Buffer(Log::instance().m_stream, "DEBUG:   ");
   }

}; //namespace distcal