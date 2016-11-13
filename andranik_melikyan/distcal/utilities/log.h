#pragma once

#include <fstream>
#include <string>
#include <memory>

namespace distcal
{
	class Log
	{
	public:
      enum Level
      {
         FATAL   = 0,
         ERROR   = 0,
         WARNING = 1,
         INFO    = 2,
         DEBUG   = 3
		};

	private:
		Log()
			:m_ignore(false)
		{ }

	public:
		static Log& instance() 
      {
         if (!m_instance)
            m_instance = new Log();
         return *m_instance;
      }

		void init(Level level, const std::string& filename);
		
		static const Log& log();
		static const Log& fatal();
		static const Log& error();
		static const Log& warning();
		static const Log& info();
		static const Log& debug();

		template <typename Item>
		const Log& operator << (const Item& item) const { return push(item); }
		const Log& operator << (std::ostream& (*manip)(std::ostream&)) const { return push(manip); }
		
	private:
      template <typename Item>
      const Log& push(const Item& item) const
      {
         if (!m_ignore)
            *m_stream << item;
         return *this;
      }

		void setIgnore( bool flag ) { m_ignore = flag; }

		bool m_ignore;
		Level m_level;
		std::auto_ptr<std::ofstream> m_stream;

		static Log* m_instance;
	};
}; //namespace dist