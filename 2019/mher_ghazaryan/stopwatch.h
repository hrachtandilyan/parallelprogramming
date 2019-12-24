#pragma once

#include <chrono>
#include <iostream>

template<class DurationType = std::chrono::duration<double>, class ClockType = std::chrono::high_resolution_clock>
class Stopwatch
{
public:
	Stopwatch()
		: start(ClockType::now())
	{
	}

	~Stopwatch()
	{
		TimePoint end = ClockType::now();
		DurationType delta = end - start;
		std::clog << delta.count() << "s\n";
	}
private:
	using TimePoint = typename ClockType::time_point;

	TimePoint start;
};
