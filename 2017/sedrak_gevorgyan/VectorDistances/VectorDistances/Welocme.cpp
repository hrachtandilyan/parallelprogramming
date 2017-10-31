///To Do:
///Make welcoming more "interactive"

#include "Welcome.h"
#include "Global_variables.h"

#include <iostream>
#include <string>

void Welcome()
{
	std::cout << "Welcome to vector distance calculator!" << std::endl;
	std::cout << "For further use, please input the data, or just skip this part" << std::endl;
	std::cout << "Please input query vectors file path, or leave empty for random generation" << std::endl;
	std::string qFilePath = "";
	std::getline(std::cin, qFilePath);
	std::cout << "Please input dataset vectors file path, or leave empty for random generation" << std::endl;
	std::string dFilePath = "";
	std::getline(std::cin, dFilePath);
	///To Do: 
	///Implement a way for checking correctness of the path
	Global_Variables::datasetBaseFile = dFilePath;
	Global_Variables::queryBaseFile = qFilePath;
	std::cout << "We will now start calculating, thanks for using this calculator" << std::endl;	
}
