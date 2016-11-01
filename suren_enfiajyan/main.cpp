#include <cstdlib>
#include <iostream>
#include "parallelVectorDistanceCounterEngine.h"


using namespace std;

int main()
{
    parallelVectorDistanceCounterEngine engine;
    
    std::vector<double> vec1(20, 1), vec2(20, 0);
    
    cout << engine.distance(vec1, vec2, 11) << endl;
    cout << engine.distance(vec1, vec2, 10) << endl;
    cout << engine.distance(vec1, vec2, 9) << endl;
    cout << engine.distance(vec1, vec2, 8) << endl;
    cout << engine.distance(vec1, vec2, 7) << endl;
    cout << engine.distance(vec1, vec2, 6) << endl;
    cout << engine.distance(vec1, vec2, 5) << endl;
    cout << engine.distance(vec1, vec2, 4) << endl;
    cout << engine.distance(vec1, vec2, 3) << endl;
    cout << engine.distance(vec1, vec2, 2) << endl;
    cout << engine.distance(vec1, vec2) << endl;
    
    return 0;
}

