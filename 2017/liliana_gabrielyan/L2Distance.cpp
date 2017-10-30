#include <iostream>
#include "Distance.h"

float Distance::L2Distance(std::vector<float>& vec1, std::vector<float>& vec2)
{
	if (vec1.size() != vec2.size()) {
		std::cout << "Incorrect size";
		return -1;
	}
	float res = 0.0f;
	float temp = 0.0f;
	for (int i = 0; i < vec1.size(); i++)
	{
		temp += std::pow((vec1[i] - vec2[i]), 2);
	}
	res = std::sqrt(temp);
	return res;
}