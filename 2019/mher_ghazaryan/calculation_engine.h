#pragma once

#include <vector>

template<class ScalarType = float, class VectorType = std::vector<float>>
class CalculationEngine
{
public:
	using Scalar = ScalarType;

	CalculationEngine() = default;
	virtual ~CalculationEngine() = default;
	CalculationEngine(const CalculationEngine&) = default;
	CalculationEngine& operator=(const CalculationEngine&) = default;
	CalculationEngine(CalculationEngine&&) noexcept = default;
	CalculationEngine& operator=(CalculationEngine&&) noexcept = default;

	virtual ScalarType componentOperation(ScalarType difference) const = 0;
	virtual ScalarType distanceFunction(const VectorType& v1, const VectorType& v2) const = 0;
	virtual std::vector<std::vector<ScalarType>> calculateFunction(const std::vector<VectorType>& lhs, const std::vector<VectorType>& rhs) const = 0;
};
