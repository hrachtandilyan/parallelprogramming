#pragma once

#include <ostream>
#include <sstream>
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
      class Buffer
      {
      public:
         Buffer() 
         { }
         
         Buffer( std::shared_ptr<std::ostream> stream, std::string prefix)
            :m_stream(stream), m_prefix(prefix)
         { }

         Buffer( const Buffer& rhs )
            :m_stream(rhs.m_stream), m_prefix(rhs.m_prefix)
         { }

         ~Buffer()
         {
            std::string log = m_buf.str();
            if(m_stream && !log.empty())
               *m_stream << m_prefix << log << std::endl;
         }

         template <typename Item>
         Buffer& operator << (const Item& item) { return push(item); }
         Buffer& operator << (std::ostream& (*manip)(std::ostream&)) { return push(manip); }

      private:
         template <typename Item>
         Buffer& push(const Item& item)
         {
            if (m_stream)
               m_buf << item;
            return *this;
         }

         std::shared_ptr<std::ostream> m_stream;

         std::string m_prefix;
         std::ostringstream m_buf;
      };

	private:
		Log()
		{ }

   public:
		static Log& instance() 
      {
         if (!m_instance)
            m_instance = new Log();
         return *m_instance;
      }

      void init(Level level, const std::ostream& out);
		void init(Level level, const std::string& filename);


      static Log::Buffer log();

      static Log::Buffer fatal();
      static Log::Buffer error();
      static Log::Buffer warning();
      static Log::Buffer info();
      static Log::Buffer debug();
		
	private:
		Level m_level;
		std::shared_ptr<std::ostream> m_stream;

		static Log* m_instance;
	};
}; //namespace dist