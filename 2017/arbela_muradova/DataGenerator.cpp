#include "DataGenerator.h"

void DataGenerator::generate_data(std::vector<std::vector<float> >& vectors_to_fill, int seed)
{
	vectors_to_fill.resize(1024, std::vector<float>(512));
	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			vectors_to_fill[i][j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		}
	}
}
