#pragma once

///declaration of function for working with files
///that contain vector data

///Not tested practically though, may cause some problems
///If needed, make some adjustments

#include "Global_variables.h"

#include <string>


void handle(std::vector< std::vector< float > >& recordingVectors, const std::string& filePath);