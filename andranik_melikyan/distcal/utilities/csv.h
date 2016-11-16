#pragma once

#include <fstream>
#include <string>

#include "../dataset.h"

namespace distcal
{
   class CSV
   {
   public:
      CSV(const std::string& filename)
         :m_filename(filename), m_file(filename)
      {
         if( !m_file.good() )
         {
            //throw (???) something
         }
      }

      void fill( DataSet& data )       // Check for exact match will be here
      {
         char dummy;
         for( int i = 0; i < data.count(); ++i )
         {
            for( int j = 0; j < data.dimension(); ++j )
            {
               m_file >> data[i][j] >> dummy;
            }
         }
      }
      
   private:
      std::ifstream m_file;
      std::string m_filename;
   };
}; //namespace distcal