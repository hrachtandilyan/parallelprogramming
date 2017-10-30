#include <iostream>
#include "Input.h"

#include<fstream>
#include<sstream>

void CSVtoVec::parse(std::string csv, std::vector<std::vector<float>>& res_vec)
{
	res_vec.resize(1024, std::vector<float>(512));
	std::filebuf filebuf;
	filebuf.open(csv, std::ios::in);
	std::iostream is(&filebuf);
	std::string line;
	int line_number = 0;
	while (std::getline(is, line))
	{
		if (line_number == 1024)
		{
			throw std::exception("Wrong numbers of lines");
		}
		std::istringstream iss(line);
		float f;
		int element_number = 0;
		while (iss >> f)
		{
			if (element_number == 512)
			{
				throw std::exception(std::string("Wrong numbers of element in line " + std::to_string(line_number)).c_str());
			}
			res_vec[line_number][element_number] = f;
			element_number++;
		}
		line_number++;
	}
	filebuf.close();
}