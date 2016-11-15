#pragma once

#include "generic.h"
#include "quadratic.h"

#include "../dataset.h"
#include "../utilities/performance.h"

namespace distcal
{
   namespace calculation
   {
      class Engine
      {
      public:
         Engine( const DataSet& data, const DataSet& queries, DataSet& result, 
                 GenericEngine::EngineType eType = GenericEngine::EngineType::QUADRATIC_TYPE, 
                 Metric::MetricType        mType = Metric::MetricType::L2_TYPE )
            :m_data( data ), m_queries( queries ), m_result( result ), m_engineImpl(NULL)
         {             
            setEngine( eType );
            setMetric( mType );
         }

         void setEngine( GenericEngine::EngineType engine )
         {
            if( m_engineImpl != NULL )
            {
               delete m_engineImpl;
            }

            switch( engine )
            {
            case GenericEngine::EngineType::QUADRATIC_TYPE:
            default:
               m_engineImpl = new QuadraticEngine( m_data, m_queries, m_result );
            }
         }

         void setMetric( Metric::MetricType metric )
         {
            switch( metric )
            {
            case Metric::MetricType::HAMMING_TYPE:
               m_metricImpl = Metric::Hamming;
               break;
            case Metric::MetricType::L1_TYPE:
               m_metricImpl = Metric::L1;
               break;
            case Metric::MetricType::L2_TYPE:
            default:
               m_metricImpl = Metric::L2;
            }
         }

         Performance::Result calculate()
         {
            return m_engineImpl->calculate( m_metricImpl );
         }

      private:
         const DataSet& m_data;
         const DataSet& m_queries;
         DataSet& m_result;

         GenericEngine* m_engineImpl;
         DistanceMetric m_metricImpl;
      };


   }; //namespace calculation
}; //namespace distcal