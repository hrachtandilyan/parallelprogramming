#pragma once

#include "dataset.h"

#include <fstream>
#include <iomanip>

#include <random>

namespace distcal
{
   void DataSet::fetch( std::string filename )
   {
      std::ifstream fin( filename.c_str() );
      if( !fin.is_open() )
      {
         randomize( 0., 100. );
         return;
      }

      for( unsigned int i = 0; i < m_size; ++i )
      {
         for( unsigned int j = 0; j < m_dimension; ++j )
         {
            fin >> m_dataset[i][j];
         }
      }
   }

   void DataSet::randomize( double randMin, double randMax )
   {
      std::random_device rd;
      std::mt19937 rng( rd() );
      std::uniform_real_distribution<double> dist( randMin, randMax );

      for( unsigned int i = 0; i < m_size; ++i )
      {
         for( unsigned int j = 0; j < m_dimension; ++j )
         {
            m_dataset[i][j] = dist(rng);
         }
      }
   }

   std::ostream& operator <<( std::ostream& out, const DataSet& rhs )
   {
      for( unsigned int i = 0; i < rhs.size(); ++i )
      {
         for( unsigned int j = 0; j < rhs.dimension(); ++j )
            out << std::setw( 7 ) << rhs[i][j] << ' ';
         out << std::endl;
      }
      return out;
   }

}; //namespace distcalc