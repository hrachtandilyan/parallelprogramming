#pragma once

#include <cmath>

#include "generic.h"

namespace distcal
{
   namespace calculation
   {
      class QuadraticEngine : public GenericEngine
      {
      public:
         QuadraticEngine( const DataSet& dataset, const DataSet& queries, DataSet& result )
            :GenericEngine( dataset, queries, result ) { };

      private:
         virtual void engineImpl( DistanceMetric distance )
         {
            for( unsigned int i = 0; i < m_dataset.size(); ++i )
            {
               for( unsigned int j = 0; j < m_queries.size(); ++j )
               {
                  m_result[i][j] = distance(m_dataset[i], m_queries[j]);
               }
            }
         }		 
      };

   }; //namespace calculation
}; //namespace distcal