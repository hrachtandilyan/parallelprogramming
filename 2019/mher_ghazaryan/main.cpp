#include <iostream>

#include "distance_calculator.h"
#include "engines.h"
#include "stopwatch.h"

template<class T>
void print_result(const std::vector<std::vector<T>>& result)
{
	for (const auto& row : result)
	{
		for (const auto& elem : row)
			std::cout << elem << " ";
		std::cout << "\n";
	}
}

template<class T>
bool check(const std::vector<std::vector<T>>& result1, const std::vector<std::vector<T>>& result2)
{
	for (size_t i = 0; i < result1.size(); ++i)
	{
		for (size_t j = 0; j < result1[i].size(); ++j)
		{
			if (std::abs(result1[i][j] - result2[i][j]) >= std::numeric_limits<float>::epsilon())
				return false;
		}
	}
	return true;
}

int main()
{
	DistanceCalculator<> calculator;
	std::vector<std::vector<float>> resultSequenced;
	std::vector<std::vector<float>> resultCPP11;
	bool success = false;

	std::cout << "L1: " << "\n";
	{
		Stopwatch<> stopwatch("L1Sequential");
		resultSequenced = calculator.calculate(L1SequentialEngine<>());
	}
	{
		Stopwatch<> stopwatch("L1CPP11");
		resultCPP11 = calculator.calculate(L1CPP11Engine<>());
	}
	success = check(resultSequenced, resultCPP11);
	std::cout << "\t" << "CPP11: " << (success ? "Success" : "Error") << "\n";

	std::cout << "L2: " << "\n";
	{
		Stopwatch<> stopwatch("L2Sequential");
		resultSequenced = calculator.calculate(L2SequentialEngine<>());
	}
	{
		Stopwatch<> stopwatch("L2CPP11");
		resultCPP11 = calculator.calculate(L2CPP11Engine<>());
	}
	success = check(resultSequenced, resultCPP11);
	std::cout << "\t" << "CPP11: " << (success ? "Success" : "Error") << "\n";

	std::cout << "Hamming: " << "\n";
	{
		Stopwatch<> stopwatch("HammingSequential");
		resultSequenced = calculator.calculate(HammingSequentialEngine<>());
	}
	{
		Stopwatch<> stopwatch("HammingCPP11");
		resultCPP11 = calculator.calculate(HammingCPP11Engine<>());
	}
	success = check(resultSequenced, resultCPP11);
	std::cout << "\t" << "CPP11: " << (success ? "Success" : "Error") << "\n";

	return 0;
}
