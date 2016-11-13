#pragma once

#include "log.h"

namespace distcal
{
	Log* Log::m_instance;

	void Log::init(Level level, const std::string& stream)
	{ 
		m_level = level;
		m_stream = std::auto_ptr<std::ofstream>(new std::ofstream(stream));
	}

	const Log& Log::log()
	{ 
		m_instance->setIgnore(true);
		return *m_instance << "\n";
	}

	const Log& Log::fatal()
	{
		m_instance->setIgnore(Log::FATAL > m_instance->m_level);
		return *m_instance << "\nFATAL:   ";
	}
	const Log& Log::error()
	{
		m_instance->setIgnore(Log::ERROR > m_instance->m_level);
		return *m_instance << "\nERROR:   ";
	}
	const Log& Log::warning()
	{
		m_instance->setIgnore(Log::WARNING > m_instance->m_level);
		return *m_instance << "\nWARNING: ";
	}
	const Log& Log::info()
	{
		m_instance->setIgnore(Log::INFO > m_instance->m_level);
		return *m_instance << "\nINFO:    ";
	}
	const Log& Log::debug()
	{
		m_instance->setIgnore(Log::DEBUG > m_instance->m_level);
		return *m_instance << "\nDEBUG:   ";
	}
}; //namespace dist