#include "Distances.h"
#include <cmath>

float Distances::L1_Calculator(const std::vector <float>& query, const std::vector <float>& dataset, const int& start, const int& end)
{
	float res = 0;
	for (int i = start; i < end; ++i)
	{
		res += std::abs(query[i] - dataset[i]);
	}
	return res;
}