#include "parallelVectorDistanceCounterEngine.h"
#include "vectorDistanceCore.h"
#include <cmath>
#include <thread>
#include <functional>
#include <iostream>

double parallelVectorDistanceCounterEngine::distance(const std::vector<double> &vec1, const std::vector<double> &vec2, unsigned numberOfThreads)
{
    if (vec1.size() == vec2.size() && numberOfThreads > 0 && vec1.size() > 0)
    {
        if (numberOfThreads == 1)
        {
            double result;
            vectorSquaredDistanceCoreFunction(vec1, vec2, 0, vec1.size() - 1, result);

            return sqrt(result);
        }
        else if (numberOfThreads < 16)
        {
            if (vec1.size() / numberOfThreads < 10)
            {
                numberOfThreads = vec1.size() / 10;
                if (numberOfThreads == 0)
                    numberOfThreads = 1;

                std::cout << "Too many threads for a vector of size " << vec1.size() <<
                        ", reducing to " << numberOfThreads << " thread" << (numberOfThreads > 1 ? "s." : ".") << std::endl;
            }

            try
            {
                std::vector<std::thread> threads(numberOfThreads);
                std::vector<double> results(numberOfThreads);

                unsigned threadDose = vec1.size() / numberOfThreads;
                if (threadDose * numberOfThreads < vec1.size())
                    ++threadDose;

                for (unsigned i = 0, index = 0; i < threads.size(); ++i, index += threadDose)
                {
                    unsigned endIndex = index + threadDose - 1;
                    if (endIndex >= vec1.size())
                        endIndex = vec1.size() - 1;

                    threads[i] = std::thread(vectorSquaredDistanceCoreFunction, std::cref(vec1), std::cref(vec2),
                                             index, endIndex, std::ref(results[i]));
                }
                
                for (auto &x : threads)
                    x.join();
                
                double res = 0.0;
                
                for(const auto &x : results)
                    res += x;
                
                return sqrt(res);
            }
            catch (std::exception error)
            {
                std::cerr << error.what() << std::endl;
                return -1.0;
            }
        }
    }
    return -1.0;
}