#pragma once

#include "metric.h"

#include "../utilities/types.h"

namespace distcal
{
   namespace calculation
   {
      class GenericEngine
      {
      public:
         GenericEngine( types::DataSet* const dataset, types::DataSet* const queries, types::DataSet* const result )
            :m_datasetPtr( dataset ), m_queriesPtr( queries ), m_resultPtr( result ) { };

         void setDistanceMetric( Metric::MetricType type ) 
         { 
            switch(type)
            {
            case Metric::MetricType::HAMMING_TYPE:
               m_distFunc = &Metric::Hamming;
               break;
            case Metric::MetricType::L1_TYPE:
               m_distFunc = &Metric::L1;
               break;
            case Metric::MetricType::L2_TYPE:
            default:
               m_distFunc = &Metric::L2;
            }
         }

         void start()
         {
            engineImpl();
         }

      private:
         virtual void engineImpl() = 0;

      protected:
         types::DistanceMetricPtr m_distFunc;
         types::DataSet* m_datasetPtr;
         types::DataSet* m_queriesPtr;
         types::DataSet* m_resultPtr;
      };

   }; //namespace calculation
}; //namespace distcal