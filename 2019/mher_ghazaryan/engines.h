#pragma once

#include "distance_engine.h"
#include "technique_engine.h"

template<class... Engine>
class CombinedEngine : public Engine... {};

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
using L2SequentialEngine = CombinedEngine<
    L2Engine<ScalarType, VectorType>,
	SequentialDistanceEngine<ScalarType, VectorType>,
	SequentialDistributionEngine<ScalarType, VectorType>>;

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
using L2CPP11Engine = CombinedEngine<
	L2Engine<ScalarType, VectorType>,
	SequentialDistanceEngine<ScalarType, VectorType>,
	CPP11Engine<ScalarType, VectorType>>;

#if __cplusplus >= 201703L
template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
using L2CPP17Engine = CombinedEngine<
	L2Engine<ScalarType, VectorType>,
	CPP17Engine<ScalarType, VectorType>,
	SequentialDistributionEngine<ScalarType, VectorType>>;

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
using L2MixedEngine = CombinedEngine<
	L2Engine<ScalarType, VectorType>,
	CPP17Engine<ScalarType, VectorType>,
	CPP11Engine<ScalarType, VectorType>>;
#endif
