#include<iostream>
#include<fstream>
#include<vector>


#include "Distance.h"
#include "CSVParser.h"
#include "DataGenerator.h"

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

int main(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string command = argv[i];
		if (command == "-path_to_query_vectors")
		{
			i++;
			Input::path_to_query_vectors = argv[i];
		} 
		else if (command == "-path_to_dataset_vectors")
		{
			i++;
			Input::path_to_dataset_vectors = argv[i];
		}
		else if (command == "-output_file")
		{
			i++;
			Input::output_file = argv[i];
		}
		else if (command == "-disable_cmd_output")
		{
			Input::disable_cmd_output = 1;
		}
		else if (command == "-logging_level")
		{
			i++;
			Input::logging_level = std::atoi(argv[i]);
		}
		else
		{
			std::cout << "Incorrect arg " << argv[i] << ". You can use the following commands: " << std::endl;
			std::cout << "\t-path_to_query_vectors - description" << std::endl;
			std::cout << "\t-path_to_dataset_vectors - description" << std::endl;
			std::cout << "\t-output_file - description" << std::endl;
			std::cout << "\t-disable_cmd_output - description" << std::endl;
			std::cout << "\t-logging_level - description" << std::endl;
		}
	}

	try
	{
		if (!Input::path_to_query_vectors.empty())
		{
			CSVParser::parse(Input::path_to_query_vectors, Data::query_vectors);
		}
		else
		{
			DataGenerator::generate_data(Data::query_vectors);
		}

		if (!Input::path_to_dataset_vectors.empty())
		{
			CSVParser::parse(Input::path_to_dataset_vectors, Data::dataset_vectors);
		}
		else
		{
			DataGenerator::generate_data(Data::dataset_vectors);
		}
	}
	catch (std::exception err)
	{
		std::cout << err.what() << std::endl;
		return -1;
	}

	/// TODO
	//for (i -> 1024)
	//	for (j -> 1024)
	//		matrix[i][j] = Distance::Hamming(query_vectors[i], Data::dataset[j]);


}