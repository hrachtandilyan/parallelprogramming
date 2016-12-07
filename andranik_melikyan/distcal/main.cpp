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
                << "Options list:"                 << "\n"
                << "\t-v/--verbosity      Verbosity [0-3]"        << "\n"
                << "\t-l/--log-file       Log Filename"           << "\n"
                << "\t-D/--data-file      Data Filename"          << "\n"
                << "\t-Q/--queries-file   Query Filename"         << "\n"
                << "\t-d/--data-count     Data Count"             << "\n"
                << "\t-q/--queries-count  Query Count"            << "\n"
                << "\t-s/--dimention      Vector Dimension"       << "\n"
                << "\t--console-log       Log only to console"    << std::endl;
   }                       
   catch( distcal::CsvException ex )
   {
      std::cout << ex.what() << ": " << ex.msg() << std::endl;
   }
}