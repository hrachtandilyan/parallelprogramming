#include "process.h"
#include "utilities/exception.h"

#include <iostream>

int main( int argc, char* argv[] )
{
   try
   {
      distcal::Process(argc, argv).run();
   }
   catch( distcal::CsvException ex )
   {
      std::cout << ex.what() << ": " << ex.msg() << std::endl;
   }
}