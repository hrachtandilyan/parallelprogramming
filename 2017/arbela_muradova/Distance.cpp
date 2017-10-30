#include "Distance.h"
#include <cmath>
float Distance::Hamming(std::vector<float>& lhv, std::vector<float>& rhv)
{
	float dist = 0;
	for ( int i = 0 ; i < lhv.size() ; i++ )
	{
		dist += fabs(lhv[i] - rhv[i]);
	}
	return dist;
}