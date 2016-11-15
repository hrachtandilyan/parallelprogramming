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
            for( unsigned int i = 0; i < m_dataset.count(); ++i )
            {
               for( unsigned int j = 0; j < m_queries.count(); ++j )
               {
                  const int id = m_performance.registerIteration();
                  m_result[i][j] = distance(m_dataset[i], m_queries[j]);
                  m_performance.endIteration( id );
               }
            }
         }		 
      };

   }; //namespace calculation
}; //namespace distcal