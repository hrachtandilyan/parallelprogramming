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
         QuadraticEngine( const DataSet& data, const DataSet& queries, DataSet& result )
            :GenericEngine( data, queries, result ) { };

      private:
         virtual void engineImpl( DistanceMetric distance )
         {
            for( unsigned int i = 0; i < m_data.count(); ++i )
            {
               for( unsigned int j = 0; j < m_queries.count(); ++j )
               {
                  const int id = m_performance.registerIteration();
                  m_result[i][j] = distance(m_data[i], m_queries[j]);
                  m_performance.endIteration( id );
               }
            }
         }		 
      };

   }; //namespace calculation
}; //namespace distcal