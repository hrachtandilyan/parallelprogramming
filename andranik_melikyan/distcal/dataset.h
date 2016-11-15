#pragma once

#include <string>
#include <vector>

namespace distcal
{
   typedef std::vector<double> DataVector;

   class DataSet
   {
   public:
      DataSet( size_t count, size_t dimension )
         :m_count( count ), m_dimension( dimension ), m_dataset( count, DataVector( dimension ) )
      { }

      void fetch( const std::string& filename = "" );

      size_t count() const { return m_count; }
      size_t dimension() const { return m_dimension; }

      DataVector& operator[]( size_t index ) { return m_dataset[index]; }
      const DataVector& operator[]( size_t index ) const { return m_dataset[index]; }
 
   private:
      std::vector<DataVector> m_dataset;
      size_t m_count;
      size_t m_dimension;   

      void randomize( double randMin = FLT_MIN, double randMax = FLT_MAX );      
   };      

   std::ostream& operator <<( std::ostream& out, const DataSet& rhs );

}; //namespace distcal