#pragma once

#include <string>
#include <vector>

namespace distcal
{
   typedef std::vector<double> DataVector;

   class DataSet
   {
   public:
      DataSet( size_t size, size_t dimension )
         :m_size( size ), m_dimension( dimension ), m_dataset( size, DataVector( dimension ) )
      { }

      void fetch( std::string filename = "" );

      size_t size() const { return m_size; }
      size_t dimension() const { return m_dimension; }

      DataVector& at( size_t index ) { return m_dataset.at(index); }
      DataVector& operator[]( size_t index ) { return m_dataset[index]; }
      const DataVector& operator[]( size_t index ) const { return m_dataset[index]; }
 
   private:
      std::vector<DataVector> m_dataset;
      size_t m_size;
      size_t m_dimension;   

      void randomize( double randMin = FLT_MIN, double randMax = FLT_MAX );      
   };      

   std::ostream& operator <<( std::ostream& out, const DataSet& rhs );

}; //namespace distcalc