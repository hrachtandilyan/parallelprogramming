#pragma once
#include<vector>

class Distance
{
public:
	static int HammingDistance(std::vector<float>& vec1, std::vector<float>& vec2);
	static float L1Distance(std::vector<float>& vec1, std::vector<float>& vec2);
	static float L2Distance(std::vector<float>& vec1, std::vector<float>& vec2);
};