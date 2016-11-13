#pragma once

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

	void Log::init(Level level, const std::string& stream)
	{
		m_level = level;
      m_stream = std::auto_ptr<std::ostream>(new std::ofstream(stream));
	}

   Log::Buffer Log::log()
   {
      return Buffer(Log::instance().m_stream, "");
   }

   Log::Buffer Log::fatal()
   {
      if (Log::FATAL > m_instance->m_level)
         return Buffer();
      return Buffer(Log::instance().m_stream, "FATAL:   ");
   }

   Log::Buffer Log::error()
   {
      if (Log::ERROR > m_instance->m_level)
         return Buffer();
      return Buffer(Log::instance().m_stream, "ERROR:   ");
   }

   Log::Buffer Log::warning()
   {
      if (Log::WARNING > m_instance->m_level)
         return Buffer();
      return Buffer(Log::instance().m_stream, "WARNING: ");
   }

	Log::Buffer Log::info()
	{
      if (Log::INFO > m_instance->m_level)
         return Buffer();
		return Buffer(Log::instance().m_stream, "INFO:    ");
	}

   Log::Buffer Log::debug()
   {
      if (Log::DEBUG > m_instance->m_level)
         return Buffer();
      return Buffer(Log::instance().m_stream, "DEBUG:   ");
   }

}; //namespace distcal