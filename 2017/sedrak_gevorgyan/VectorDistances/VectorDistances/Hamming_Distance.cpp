#include "Distances.h"

int Distances::Hamming_Calculator(const std::vector <float>& query, const std::vector <float>& dataset, const int& start, const int& end)
{
	int res = 0;
	for (int i = start; i < end; ++i)
	{
		res += (query[i] != dataset[i]);
	}
	return res;
}
