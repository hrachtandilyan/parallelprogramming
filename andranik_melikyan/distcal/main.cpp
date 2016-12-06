#include "version.h"

#include "process.h"
#include "utilities/exception.h"

#include <iostream>

int main( int argc, char* argv[] )
{
   try
   {
      distcal::Process(argc, argv).run();
   }
   catch( distcal::CommandLineException ex )
   {
      std::cout << ex.what() << ": " << ex.msg() << std::endl;
      std::cout << "distcal v" << distcal::Version << "\n"
                << "Usage: distcal [option] ..."   << "\n"
                << "Options: "                     << "\n"
                << "\t-v   Verbosity [0-3]"        << "\n"
                << "\t-l   Log Filename"           << "\n"
                << "\t-D   Data Filename"          << "\n"
                << "\t-Q   Query Filename"         << "\n"
                << "\t-d   Data Count"             << "\n"
                << "\t-q   Query Count"            << "\n"
                << "\t-s   Vector Dimension"       << std::endl;
   }
   catch( distcal::CsvException ex )
   {
      std::cout << ex.what() << ": " << ex.msg() << std::endl;
   }
}