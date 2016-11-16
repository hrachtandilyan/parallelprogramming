#pragma once

#include "metric.h"

#include "../utilities/performance.h"

namespace distcal
{
   namespace calculation
   {
      class GenericEngine
      {
      public:
         enum EngineType
         {
            QUADRATIC_TYPE = 0
         };

      public:
         GenericEngine( const DataSet& data, const DataSet& queries, DataSet& result )
            :m_data( data ), m_queries( queries ), m_result( result ) 
         { };

         Performance::Result calculate( DistanceMetric distance ) 
         { 
            m_performance.start();

            engineImpl( distance );

            m_performance.stop();
            return m_performance.getResult();
         }

      private:
         virtual void engineImpl( DistanceMetric distance ) = 0;

      protected:
         Performance m_performance;

         const DataSet& m_data;
         const DataSet& m_queries;
         DataSet& m_result;
      };

   }; //namespace calculation
}; //namespace distcal