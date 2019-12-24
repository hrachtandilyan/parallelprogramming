#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <utility>

template<class DurationType = std::chrono::duration<double>, class ClockType = std::chrono::high_resolution_clock>
class Stopwatch
{
public:
	explicit Stopwatch(std::string label)
		: start()
		, label(std::move(label))
	{
		std::clog << "Starting \"" << this->label << "\"\n";
		start = ClockType::now();
	}

	~Stopwatch()
	{
		TimePoint end = ClockType::now();
		DurationType delta = end - start;
		std::clog << "\"" << label << "\" ended in " << delta.count() << " units" << "\n";
	}
private:
	using TimePoint = typename ClockType::time_point;

	TimePoint start;
	std::string label;
};
