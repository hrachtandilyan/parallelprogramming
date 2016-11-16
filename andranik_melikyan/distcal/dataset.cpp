#include "dataset.h"

#include <fstream>
#include <iomanip>

#include <random>

#include "utilities/csv.h"

namespace distcal
{
   void DataSet::fetch( const std::string& filename )
   {
      if( filename.empty() )
      {
         randomize( 0., 100. );
         return;
      }

      CSV datafile(filename);
      datafile.fill(*this);
   }

   void DataSet::randomize( double minimum, double maximum )
   {
      std::random_device rd;
      std::mt19937 rng( rd() );
      std::uniform_real_distribution<double> dist( minimum, maximum );

      for( unsigned int i = 0; i < m_count; ++i )
      {
         for( unsigned int j = 0; j < m_dimension; ++j )
         {
            m_dataset[i][j] = dist(rng);
         }
      }
   }

   std::ostream& operator <<( std::ostream& out, const DataSet& rhs )
   {
      for( unsigned int i = 0; i < rhs.count(); ++i )
      {
         for( unsigned int j = 0; j < rhs.dimension(); ++j )
            out << std::setw( 7 ) << rhs[i][j] << ' ';
         if( i != rhs.count() - 1 )
            out << std::endl;
      }
      return out;
   }

}; //namespace distcal