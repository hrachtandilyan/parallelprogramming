#pragma once

#include <string>

namespace distcal
{
   /// @brief Exception for errors related to command line processing
   struct CommandLineException : public std::exception
   {
      CommandLineException(const std::string& msg = std::string())
         :m_msg(msg)
      { }

      virtual const char* what() { return "Command line exception"; }
      std::string msg() { return m_msg; }

      const std::string m_msg;
   };

   /// @brief Exception for errors related to CSV file processing
   struct CsvException : public std::exception
   {
      CsvException(const std::string& msg = std::string())
         :m_msg(msg)
      { }

      virtual const char* what() { return "CSV file exception"; }
      std::string msg() { return m_msg; }

      const std::string m_msg;
   };

}; //namespace distcal