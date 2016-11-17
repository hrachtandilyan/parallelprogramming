#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

#include "../dataset.h"

namespace distcal
{
   class CSV
   {
   public:
      CSV(const std::string& filename)
      {
         m_file.open(filename);
         if( !m_file.good() )
         {
            throw std::exception("Invalid filename");
         }
      }

      void fill( DataSet& data )       // Check for exact match will be here
      {
         const std::regex csvLine("\\d(\\s*,\\s*\\d)");
         std::istringstream lineStream;
        
         for( int i = 0; i < data.count(); ++i )
         {
            std::string line;
            std::getline(m_file, line);
            if (!std::regex_match(line, csvLine))
            {
               throw std::exception("Invalid format");
            }

            lineStream.str(line + ',');
            for( int j = 0; j < data.dimension(); ++j )
            {
               char dummy;
               lineStream >> data[i][j] >> dummy;
            }
         }
         if (!m_file.eof())
         {
            throw std::exception("Invalid format");
         }

      }
      
   private:
      std::ifstream m_file;
   };
}; //namespace distcal