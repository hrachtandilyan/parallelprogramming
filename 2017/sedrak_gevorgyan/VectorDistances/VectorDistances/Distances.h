#pragma once

///The declaration of distance calculating functions

#include <vector>

class Distances
{
public:
	///Start and end points are given here for multithreading purposes
	///This way each thread will know which section it must count

	static float L1_Calculator(const std::vector <float>& query, const std::vector <float>& dataset, const int& start, const int& end);
	static float L2_Calculator(const std::vector <float>& query, const std::vector <float>& dataset, const int& start, const int& end);
	static int Hamming_Calculator(const std::vector <float>& query, const std::vector <float>& dataset, const int& start, const int& end);
};