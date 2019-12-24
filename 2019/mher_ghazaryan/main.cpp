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
	DistanceCalculator<> calculator;//(3, 10, 10);
	std::vector<std::vector<float>> l2Result1;
	std::vector<std::vector<float>> l2Result2;

	{
		Stopwatch<> stopwatch;
		l2Result1 = calculator.calculate(L2SequentialEngine<>());
	}

	{
		Stopwatch<> stopwatch;
		l2Result2 = calculator.calculate(L2CPP11Engine<>());
	}

//	print_result(l2Result1);
//	std::cout << "\n";
//	print_result(l2Result2);

	bool success = check(l2Result1, l2Result2);
	std::cout << (success ? "Success" : "Error") << "\n";

#if __cplusplus >= 201703L
	{
		Stopwatch<> stopwatch;
		l2Result2 = calculator.calculate(L2MixedEngine<>());
	}
#endif

	return 0;
}
