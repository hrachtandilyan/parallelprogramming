#pragma once

#include "metric.h"

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
         GenericEngine( const DataSet& dataset, const DataSet& queries, DataSet& result )
            :m_dataset( dataset ), m_queries( queries ), m_result( result ) { };

         void start( DistanceMetric distance ) { engineImpl( distance ); }

      private:
         virtual void engineImpl( DistanceMetric distance ) = 0;

      protected:
         const DataSet& m_dataset;
         const DataSet& m_queries;
         DataSet& m_result;
      };

   }; //namespace calculation
}; //namespace distcal