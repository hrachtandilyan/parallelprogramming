#pragma once
#include<string>
#include<vector>

class CSVtoVec
{
public:
	static void parse(std::string csv, std::vector<std::vector<float>>& res_vec);
};