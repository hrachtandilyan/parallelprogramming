#include "csv.h"

#include <sstream>
#include <regex>

#include "exception.h"

#include "../dataset.h"

namespace distcal
{
   namespace
   {
      std::string generate_regex(size_t dimension)
      {
         if( dimension == 0 )
            return "";

         --dimension;
         std::string num = "";
         while( dimension != 0 )
         {
            num = (char)('0' + dimension % 10) + num;
            dimension /= 10;
         }
         
         const std::string real = "[[:space:]]*-?[[:digit:]]+(\\.[[:digit:]]+)?[[:space:]]*";
         return "^" + real + "(," + real + "){" + num + "}$";
      }

   }; //namespace

   CSV::CSV(const std::string& filename)
      :m_filename(filename), m_file(filename)
   {
      if( !m_file.good() )
      {
         throw CsvException("[" + m_filename + "] can't be opened");
      }
   }

   void CSV::fill(DataSet& data)
   {
      const std::regex csvLine(generate_regex(data.dimension()));
      std::istringstream lineStream;

      for( size_t i = 0; i < data.count(); ++i )
      {
         std::string line;
         std::getline(m_file, line);
         if( !std::regex_match(line, csvLine) )
         {
            throw CsvException("[" + m_filename + "] contains invalid data");
         }

         lineStream.str(line + ',');
         for( size_t j = 0; j < data.dimension(); ++j )
         {
            char dummy;
            lineStream >> data[i][j] >> dummy;
         }
      }
      if( !m_file.eof() )
      {
         throw CsvException("[" + m_filename + "] contains invalid data");
      }
    }

}; //namespace distcal