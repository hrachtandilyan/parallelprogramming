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
         QuadraticEngine( types::DataSet* dataset, types::DataSet* queries, types::DataSet* result )
            :GenericEngine( dataset, queries, result ) { };

      private:
         virtual void engineImpl()
         {
            for( int i = 0; i < m_datasetPtr->size(); ++i )
            {
               for( int j = 0; j < m_queriesPtr->size(); ++j )
               {
                  (*m_resultPtr)[i][j] = m_distFunc(m_datasetPtr->at(i), m_queriesPtr->at(j));
               }
            }
         }		 
      };

   }; //namespace calculation
}; //namespace distcal