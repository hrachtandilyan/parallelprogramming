#ifndef PARALLELVECTORDISTANCECOUNTERENGINE_H
#define PARALLELVECTORDISTANCECOUNTERENGINE_H

#include <vector>

class parallelVectorDistanceCounterEngine
{
public:
    double distance(const std::vector<double> &vec1, const std::vector<double> &vec2, unsigned numberOfThreads = 1);
};

#endif /* PARALLELVECTORDISTANCECOUNTERENGINE_H */

