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
			FATAL = 0,
			ERROR,
			WARNING,
			INFO,
			DEBUG
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
		static const Log& Fatal();
		static const Log& Error();
		static const Log& Warning();
		static const Log& Info();
		static const Log& Debug();

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