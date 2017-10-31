#include "Distances.h"
#include <cmath>

float Distances::L2_Calculator(const std::vector <float>& query, const std::vector <float>& dataset, const int& start, const int& end)
{
	float res = 0;
	for (int i = start; i < end; ++i)
	{
		res += std::pow((query[i] - dataset[i]), 2);
	}
	return std::sqrt(res);
}
