cmake_minimum_required(VERSION 3.15)
project(PPProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(PPProject main.cpp stopwatch.h distance_calculator.h calculation_engine.h distance_engine.h technique_engine.h engines.h)

if(MSVC)
    target_compile_options(PPProject PRIVATE /W4 /WX)
else()
    target_compile_options(PPProject PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

if (${CMAKE_CXX_STANDARD} GREATER_EQUAL 17 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(PPProject tbb)
endif()
