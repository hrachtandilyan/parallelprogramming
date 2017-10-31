///Decided to use this instead of simple global variables 
///

#pragma once

#include <string>
#include <vector>

namespace Global_Variables
{
	extern std::string queryBaseFile;
	extern std::string datasetBaseFile;
	extern std::vector< std::vector< float > > queryVectors;
	extern std::vector< std::vector< float > > datasetVectors;
	extern int setSize;
	extern int vectorSize;
}

