#include <cmath>
#include "vectorDistanceCore.h"

void vectorSquaredDistanceCoreFunction(const std::vector<double> &vec1, const std::vector<double> &vec2, unsigned startIndex, unsigned endIndex, double& result)
{
    double res = 0.0;
    
    if (vec1.size() == vec2.size() && startIndex < vec1.size() && endIndex < vec1.size())
    {
        do
        {
            double temp = std::abs(vec1[startIndex]) - std::abs(vec2[startIndex]);
            res += temp * temp;
            
            ++startIndex;
        }
        while(startIndex <= endIndex);
    }
    
    result = res;
}


