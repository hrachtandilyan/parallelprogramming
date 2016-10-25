#pragma once

#include <cmath>

#include "../utilities/types.h"

namespace distcal
{
   class Metric
   {
   public:
      enum MetricType
      {
         HAMMING_TYPE = 0,
         L1_TYPE,
         L2_TYPE
      };


      static double Hamming(const types::DataVector& lhs, const types::DataVector& rhs)
      {
         const double eps = 1e-10;
         double res = 0;
         for (int i = 0; i < lhs.size(); ++i)
         {
            res += (int)(lhs[i] + rhs[i] + eps) % 2;
         }
         return res;
      }

      static double L1(const types::DataVector& lhs, const types::DataVector& rhs)
      {
         double res = 0;
         for (int i = 0; i < lhs.size(); ++i)
         {
            res += std::abs(lhs[i] - rhs[i]);
         }
         return res;
      }

      static double L2(const types::DataVector& lhs, const types::DataVector& rhs)
      {
         double res = 0;
         for (int i = 0; i < lhs.size(); ++i)
         {
            double delta = lhs[i] - rhs[i];
            res += delta * delta;
         }
         return std::sqrt(res);
      }
   }; 

}; //namespace distcal