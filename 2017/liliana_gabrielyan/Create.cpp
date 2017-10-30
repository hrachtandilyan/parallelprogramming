#include "Create.h"

void Create::create_data(std::vector<std::vector<float> >& res_vec)
{
	res_vec.resize(1024, std::vector<float>(512));
	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			res_vec[i][j] = static_cast<float>(rand());
		}
	}
}