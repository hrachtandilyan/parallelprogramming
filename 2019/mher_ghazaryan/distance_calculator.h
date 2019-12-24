#pragma once

#include "calculation_engine.h"

#include <cstddef>
#include <vector>
#include <random>

template<class ElementType = float>
class DistanceCalculator
{
public:
	using VectorType = std::vector<ElementType>;

	DistanceCalculator()
		: DistanceCalculator(512, 1024, 1024)
	{
	}

	DistanceCalculator(size_t length, size_t querySize, size_t datasetSize)
		: queryVectors(querySize, VectorType(length))
		, datasetVectors(datasetSize, VectorType(length))
	{
		static std::random_device rd;
		static std::default_random_engine gen(rd());
		static std::uniform_real_distribution<ElementType> dist;

		for (VectorType& vec : queryVectors)
		{
			for (ElementType& elem : vec)
				elem = dist(gen);
		}

		for (VectorType& vec : datasetVectors)
		{
			for (ElementType& elem : vec)
				elem = dist(gen);
		}
	}

	std::vector<std::vector<ElementType>> calculate(const CalculationEngine<ElementType>& engine)
	{
		return engine.calculateFunction(queryVectors, datasetVectors);
	}
private:
	std::vector<VectorType> queryVectors;
	std::vector<VectorType> datasetVectors;
};
