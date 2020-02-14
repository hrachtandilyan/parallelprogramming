#pragma once

#include "calculation_engine.h"

#include <cmath>
#include <limits>

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
class L1Engine : public virtual CalculationEngine<ScalarType, VectorType>
{
protected:
	ScalarType componentOperation(ScalarType difference) const override
	{
		return std::abs(difference);
	}
};

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
class L2Engine : public virtual CalculationEngine<ScalarType, VectorType>
{
protected:
	ScalarType componentOperation(ScalarType difference) const override
	{
		return difference * difference;
	}

	ScalarType distanceCorrectionFunction(ScalarType distance) const override
	{
		return std::sqrt(distance);
	}
};

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
class HammingEngine : public virtual CalculationEngine<ScalarType, VectorType>
{
protected:
	ScalarType componentOperation(ScalarType difference) const override
	{
		return difference < std::numeric_limits<ScalarType>::epsilon() ? 0 : 1;
	}
};
