#pragma once

#include <string>

namespace distcal
{
   /// @brief Custom exception strcut for errors related to CSV file processing
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