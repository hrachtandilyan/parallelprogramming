#include "Input_Processor.h"
#include "File_Handler.h"
#include "Vector_Generator.h"
#include "Global_variables.h"

void Process()
{
	if (!Global_Variables::queryBaseFile.empty())
	{
		Global_Variables::queryVectors = std::vector< std::vector< float > >(1024, std::vector< float >(512));
		handle(Global_Variables::queryVectors, Global_Variables::queryBaseFile);
	}
	else
	{
		Global_Variables::setSize = 10;
		Global_Variables::vectorSize = 10;
		Global_Variables::queryVectors = std::vector< std::vector< float > >(Global_Variables::setSize, std::vector< float >(Global_Variables::vectorSize));
		generate(Global_Variables::queryVectors);
	}
	if (!Global_Variables::datasetBaseFile.empty())
	{
		Global_Variables::datasetVectors = std::vector< std::vector< float > >(1024, std::vector< float >(512));
		handle(Global_Variables::datasetVectors, Global_Variables::datasetBaseFile);
	}
	else
	{
		Global_Variables::setSize = 10;
		Global_Variables::vectorSize = 10;
		Global_Variables::datasetVectors = std::vector< std::vector< float > >(Global_Variables::setSize, std::vector< float >(Global_Variables::vectorSize));
		generate(Global_Variables::datasetVectors);
	}

	bool sizeIsOk = true;
	if (Global_Variables::datasetVectors.size() != Global_Variables::queryVectors.size())
	{
		sizeIsOk = false;
	}
	else
	{
		Global_Variables::setSize = Global_Variables::datasetVectors.size();
	}
	for (int i = 0; i < Global_Variables::setSize; ++i)
	{
		if (Global_Variables::datasetVectors[i].size() != Global_Variables::queryVectors[i].size())
		{
			sizeIsOk = false;
		}
	}
	if (!sizeIsOk)
	{
		throw std::exception("Your given dataset and query are not equal, check please");
	}
	else
	{
		Global_Variables::vectorSize = Global_Variables::datasetVectors[0].size();
	}

}