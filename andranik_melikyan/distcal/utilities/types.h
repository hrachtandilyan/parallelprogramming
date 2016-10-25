#pragma once

#include <vector>

namespace distcal
{
   namespace types
   {
      typedef std::vector<double> DataVector;
      typedef std::vector<DataVector> DataSet;
      typedef double (*DistanceMetricPtr)( const types::DataVector&, const types::DataVector& );
   }; //namespace types
}; //namespace distcalc