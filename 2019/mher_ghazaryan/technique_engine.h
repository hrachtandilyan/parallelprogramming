#pragma once

#include "calculation_engine.h"

#include <algorithm>
#include <numeric>
#include <thread>
#include <future>
#include <cmath>
#include <cassert>
#include <functional>

#if __cplusplus >= 201703L
#include <execution>
#endif

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
class SequentialDistanceEngine : public virtual CalculationEngine<ScalarType, VectorType>
{
public:
	ScalarType distanceFunction(const VectorType& v1, const VectorType& v2) const override
	{
		return std::inner_product(
			v1.begin(), v1.end(),
			v2.begin(),
			ScalarType{}, std::plus<>(), [this](ScalarType lhs, ScalarType rhs)
			{
				return this->componentOperation(rhs - lhs);
			});
	}
};

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
class SequentialDistributionEngine : public virtual CalculationEngine<ScalarType, VectorType>
{
public:
	std::vector<std::vector<ScalarType>> calculateFunction(const std::vector<VectorType>& lhs, const std::vector<VectorType>& rhs) const override
	{
		std::vector<std::vector<ScalarType>> result(lhs.size(),std::vector<ScalarType>(rhs.size()));
		for (size_t i = 0; i < lhs.size(); ++i)
		{
			for (size_t j = 0; j < rhs.size(); ++j)
				result[i][j] = this->distanceFunction(lhs[i], rhs[j]);
		}
		return result;
	}
};

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
class CPP11Engine : public virtual CalculationEngine<ScalarType, VectorType>
{
public:
	std::vector<std::vector<ScalarType>> calculateFunction(const std::vector<VectorType>& lhs, const std::vector<VectorType>& rhs) const override
	{
		std::vector<std::vector<ScalarType>> result(lhs.size(),std::vector<ScalarType>(rhs.size()));

		unsigned int maxThreads = std::thread::hardware_concurrency();
		if (maxThreads < 2)
		{
			calculateSequentially(result, lhs, rhs, 0, lhs.size(), 0, rhs.size());
			return result;
		}

		size_t blockCount1D = std::lround(std::sqrt(static_cast<double>(maxThreads)));
		assert(blockCount1D);

		size_t blockSize1 = (lhs.size() + blockCount1D - 1) / blockCount1D;
		size_t blockSize2 = (rhs.size() + blockCount1D - 1) / blockCount1D;

		std::vector<std::future<void>> futures(blockCount1D * blockCount1D - 1);
		for (size_t block = 0; block < futures.size(); ++block)
		{
			const size_t block1 = block / blockCount1D;
			const size_t block2 = block % blockCount1D;
			futures[block] = std::async(std::launch::async, std::mem_fn(&CPP11Engine::calculateSequentially), this,
				std::ref(result), std::cref(lhs), std::cref(rhs), block1 * blockSize1, blockSize1, block2 * blockSize2, blockSize2);
		}
		calculateSequentially(result, lhs, rhs,
			blockSize1 * blockCount1D, lhs.size() - blockSize1 * blockCount1D,
			blockSize2 * blockCount1D, rhs.size() - blockSize2 * blockCount1D);
		for (std::future<void>& future : futures)
			future.get();
		return result;
	}

private:
	void calculateSequentially(std::vector<std::vector<ScalarType>>& result, const std::vector<VectorType>& lhs, const std::vector<VectorType>& rhs, size_t start1, size_t size1, size_t start2, size_t size2) const
	{
		for (size_t i = start1; i < size1; ++i)
		{
			for (size_t j = start2; j < size2; ++j)
				result[i][j] = this->distanceFunction(lhs[i], rhs[j]);
		}
	}
};

#if __cplusplus >= 201703L
template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
class CPP17Engine : public virtual CalculationEngine<ScalarType, VectorType>
{
public:
	ScalarType distanceFunction(const VectorType& v1, const VectorType& v2) const override
	{
		return std::transform_reduce(std::execution::unseq,
			v1.begin(), v1.end(),
			v2.begin(),
			ScalarType{}, std::plus<>(), [this](ScalarType lhs, ScalarType rhs)
			{
				return this->componentOperation(rhs - lhs);
			});
	}
};
#endif
