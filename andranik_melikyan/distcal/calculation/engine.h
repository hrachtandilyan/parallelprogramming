#pragma once

#include "generic.h"
#include "quadratic.h"

#include "../utilities/types.h"

namespace distcal
{
   namespace calculation
   {
      enum EngineType
      {
         QUADRATIC_TYPE = 0
      };

      class Engine
      {
      public:
         Engine() { m_engineImpl = NULL; }

         void setEngineAndInit( EngineType engine, Metric::MetricType metric, types::DataSet* dataset, types::DataSet* queries, types::DataSet* result )
         {
            switch( engine )
            {
            case EngineType::QUADRATIC_TYPE:
            default:
               m_engineImpl = new QuadraticEngine( dataset, queries, result );
            }

            m_engineImpl->setDistanceMetric( metric );
         }

         void start()
         {
            m_engineImpl->start();
         }

      private:
         GenericEngine* m_engineImpl;
      };


   }; //namespace calculation
}; //namespace distcal