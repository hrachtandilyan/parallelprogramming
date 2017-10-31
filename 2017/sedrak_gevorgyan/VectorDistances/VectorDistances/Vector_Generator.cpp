#include "Vector_Generator.h"
#include "Global_variables.h"

#include <time.h>
#include <random>

void generate(std::vector< std::vector < float > >& generatingVector)
{

	///To Do : Solve the problem of
	///equal generating sets	
	srand(time(NULL));
	for (int i = 0; i < /*Global_Variables::setSize*/10; ++i)
	{
		for (int j = 0; j < /*Global_Variables::vectorSize*/10; ++j)
		{
			generatingVector[i][j] = (static_cast<float> (rand()))/ 1000;
		}
	}
}