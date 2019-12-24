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

int main()
{
	DistanceCalculator<> calculator;//(3, 10, 10);
	std::vector<std::vector<float>> l2Result;

	{
		Stopwatch<> stopwatch;
		l2Result = calculator.calculate(L2SequentialEngine<>());
	}

	{
		Stopwatch<> stopwatch;
		l2Result = calculator.calculate(L2CPP11Engine<>());
	}

#if __cplusplus >= 201703L
	{
		Stopwatch<> stopwatch;
		l2Result = calculator.calculate(L2MixedEngine<>());
	}
#endif

	return 0;
}
