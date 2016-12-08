#include "dataset.h"

#include <fstream>
#include <iomanip>

#include <random>

#include "utilities/csv.h"
#include "utilities/log.h"

namespace distcal
{
   void DataSet::fetch( const std::string& filename )
   {
      if( filename.empty() )
      {
         randomize( -1024., 1024. );
         return;
      }
      else
      {
         CSV datafile(filename);
         datafile.fill(*this);
      }

      Log::debug() << *this;
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
      std::ios::fmtflags storeFlags(out.flags());

      for( unsigned int i = 0; i < rhs.count(); ++i )
      {
	      out << std::fixed;
         for( unsigned int j = 0; j < rhs.dimension(); ++j )
            out << std::setw( 7 ) << rhs[i][j] << ( j + 1 < rhs.dimension() ? ", " : "" );
         if( i != rhs.count() - 1 )
            out << std::endl;
      }

      out.flags(storeFlags);
      return out;
   }

}; //namespace distcal