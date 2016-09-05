#include "sample_component/sample_class.h"

// Standard Library headers
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

int main()
{
    sample_class sco;

    std::vector<std::string> cities = { "Yerevan", "Moscow", "London", "New York" };

    for ( const auto& city : cities )
    {
        std::cout << city << std::endl;
    }

    std::copy( cities.begin(), cities.end(), std::ostream_iterator< std::string >( std::cout, "\n" ) );
    
    return 0;
}
