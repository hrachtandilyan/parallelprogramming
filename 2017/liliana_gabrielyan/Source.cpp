#include<iostream>
#include<fstream>
#include<vector>

#include "Input.h"
#include "Create.h"
#include "Distance.h"

namespace Input
{
	std::string path_to_query_vectors;
	std::string path_to_dataset_vectors;
	std::string output_file;
	bool disable_cmd_output;
	int logging_level;
}

namespace Data
{
	std::vector<std::vector<float>> query_vectors;
	std::vector<std::vector<float>> dataset_vectors;
}

int main()
{
	try
	{
		if (!Input::path_to_query_vectors.empty())
		{
			CSVtoVec::parse(Input::path_to_query_vectors, Data::query_vectors);
		}
		else
		{
			Create::create_data(Data::query_vectors);
		}

		if (!Input::path_to_dataset_vectors.empty())
		{
			CSVtoVec::parse(Input::path_to_dataset_vectors, Data::dataset_vectors);
		}
		else
		{
			Create::create_data(Data::dataset_vectors);
		}
	}
	catch (std::exception err)
	{
		std::cout << err.what() << std::endl;
		return -1;
	}
	std::vector<std::vector<float>> matrixHammingDistance(1024,std::vector<float>(1024));
	std::vector<std::vector<float>> matrixL1Distance(1024, std::vector<float>(1024));
	std::vector<std::vector<float>> matrixL2Distance(1024, std::vector<float>(1024));
	std::vector<std::vector<float>> query_vectors(1024, std::vector<float>(512));
	CSVtoVec::parse(Input::path_to_query_vectors, query_vectors);
	std::vector<std::vector<float>> dataset_vectors(1024, std::vector<float>(512));
	CSVtoVec::parse(Input::path_to_dataset_vectors, dataset_vectors);

	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			matrixHammingDistance[i][j] = Distance::HammingDistance(Data::query_vectors[i], Data::dataset_vectors[j]);
		}
	}
	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			matrixL1Distance[i][j] = Distance::L1Distance(Data::query_vectors[i], Data::dataset_vectors[j]);
		}
	}
	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			matrixL2Distance[i][j] = Distance::L2Distance(query_vectors[i], Data::dataset_vectors[j]);
		}
	}
	return 0;
}