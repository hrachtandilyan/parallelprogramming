/// Base algorithm:
/// 1.
///		a) get the file
///		read from file
///		create vectors
///		b) generate vectors
/// 2.  import structures for counting dostances
/// 3.	make threads with guards
/// 4.  calculate the distancess

#include <iostream>
#include <vector>
#include <string>

#include "Global_variables.h"
#include "Query_Vectors.h"
#include "Welcome.h"
#include "Input_Processor.h"
#include "Distances.h"

int main(/*int argumentQuantity, char** argumentList*/)  ///To Do: implement a method for starting with console
{
	Welcome();
	/// Change processing fucntion according with console call implementation
	Process();
	
	/// Just to show that vectors generate properly, delete comments for checing
	//for (int i = 0; i < Global_Variables::setSize; ++i)
	//{
	//	for (int j = 0; j < Global_Variables::vectorSize; ++j)
	//	{
	//		std::cout << Global_Variables::datasetVectors[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//for (int i = 0; i < Global_Variables::setSize; ++i)
	//{
	//	for (int j = 0; j < Global_Variables::vectorSize; ++j)
	//	{
	//		std::cout << Global_Variables::queryVectors[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}


	for (int i = 0; i < Global_Variables::setSize; ++i)
	{
		for (int j = 0; j < Global_Variables::setSize; ++j)
		{
			std::cout << Distances::Hamming_Calculator(Global_Variables::queryVectors[i], Global_Variables::datasetVectors[j], 0, Global_Variables::vectorSize) <<
				" " << Distances::L1_Calculator(Global_Variables::queryVectors[i], Global_Variables::datasetVectors[j], 0, Global_Variables::vectorSize) <<
				" " << Distances::L2_Calculator(Global_Variables::queryVectors[i], Global_Variables::datasetVectors[j], 0, Global_Variables::vectorSize) << std::endl;
		}
	}

	///To Do:
	///Add threads that on every iteration take the vectors, devide it between themselves 
	///and calculate appropriate distances
}