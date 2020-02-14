#pragma once

#include "distance_engine.h"
#include "technique_engine.h"

template<class... Engine>
class CombinedEngine : public Engine... {};

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
using L1SequentialEngine = CombinedEngine<
	L1Engine<ScalarType, VectorType>,
	SequentialDistanceEngine<ScalarType, VectorType>,
	SequentialDistributionEngine<ScalarType, VectorType>>;

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
using L1CPP11Engine = CombinedEngine<
	L1Engine<ScalarType, VectorType>,
	SequentialDistanceEngine<ScalarType, VectorType>,
	CPP11Engine<ScalarType, VectorType>>;

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

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
using HammingSequentialEngine = CombinedEngine<
	HammingEngine<ScalarType, VectorType>,
	SequentialDistanceEngine<ScalarType, VectorType>,
	SequentialDistributionEngine<ScalarType, VectorType>>;

template<class ScalarType = float, class VectorType = std::vector<ScalarType>>
using HammingCPP11Engine = CombinedEngine<
	HammingEngine<ScalarType, VectorType>,
	SequentialDistanceEngine<ScalarType, VectorType>,
	CPP11Engine<ScalarType, VectorType>>;
