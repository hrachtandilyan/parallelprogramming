#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include <cstdlib>
#include <ctime>

#include "types.h"

namespace distcal
{
   namespace utility
   {
      class SetFetcher
      {
      public:
         SetFetcher(const std::string& filename, int count, int size )
            :m_data( count, types::DataVector(size) )
         {
            std::ifstream fin(filename.c_str());
            if (!fin.is_open())
            {
               std::srand(time(0));
               
               for (int i = 0; i < count; ++i)
               {
                  for (int j = 0; j < size; ++j)
                  {
                     m_data[i][j] = 1.0 * rand() / RAND_MAX * 100;
                  }
               }
            }
            
            for (int i = 0; i < count; ++i)
            {
               for (int j = 0; j < size; ++j)
               {
                  fin >> m_data[i][j];
               }
            }
         }

         types::DataSet fetch() { return m_data; }

      private:
         types::DataSet m_data;
      };

      void outputDataSet(std::ostream& out, types::DataSet set)
      {
         for (int i = 0; i < set.size(); ++i)
         {
            for (int j = 0; j < set[i].size(); ++j)
            {
               std::cout << std::setprecision(3) << std::fixed << std::setw(9) << set[i][j] << ' ';
            }
            std::cout << std::endl;
         }
      }

   };//namespace utility
}; //namespace distcalc