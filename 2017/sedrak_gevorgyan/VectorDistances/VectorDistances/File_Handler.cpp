#include "File_Handler.h"
#include "Global_variables.h"

#include <sstream>
#include <fstream>

void handle(std::vector< std::vector< float > >& recordingVectors, const std::string& filePath)
{
	std::ifstream fin;
	fin.open(filePath);
	if (!fin)
	{
		throw std::exception("can't open the file");
	}
	int lineCounter = -1;
	std::string nextLine;
	while (std::getline(fin, nextLine))
	{
		++lineCounter;
		if (lineCounter >= 1024)
		{
			throw std::exception("Exceeded default vector quantity 1024");
		}
		std::istringstream iss(nextLine);
		float elem;
		int elemCounter = -1;
		while (iss >> elem)
		{
			++elemCounter;
			if (elemCounter >= 512)
			{
				throw std::exception("Exceeded default element quantity 512");
			}
			recordingVectors[lineCounter][elemCounter] = elem;
		}
	}
	fin.close();
}
