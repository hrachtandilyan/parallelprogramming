#include <iostream>
#include "Distance.h"

int Distance::HammingDistance(std::vector<float>& vec1, std::vector<float>& vec2)
{
	if (vec1.size() != vec2.size()) {
		std::cout << "Incorrect size";
		return -1;
	}
	int res = 0;
	std::vector<std::vector<float>> matrix(1024, std::vector<float>(1024));
	for (int i = 0; i < vec1.size(); i++)
	{
		if (vec1[i] != vec2[i]) {
			res++;
		}
		return res;
	}
	return 0;
}