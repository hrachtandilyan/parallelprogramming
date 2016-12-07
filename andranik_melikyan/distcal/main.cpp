#include "version.h"

#include <iostream>
#include <regex>

#include "process.h"
#include "utilities/exception.h"

int main( int argc, char* argv[] )
{
   try
   {
      distcal::Process(argc, argv).run();
   }
   catch( distcal::ConfigException ex )
   {
      std::cout << ex.what() << ": " << ex.msg() << std::endl;
      std::cout << "distcal v" << distcal::Version << "\n"
                << "Usage: distcal [option] ..."   << "\n"
                << "Options list:"                 << "\n"
                << "\t-v/--verbosity      Verbosity [0-3]"        << "\n"
                << "\t-l/--log-file       Log Filename"           << "\n"
                << "\t--no-log            Disable logging"        << "\n"
                << "\t--console-log       Log to console"         << "\n"
                << "\t-D/--data-file      Data Filename"          << "\n"
                << "\t-Q/--queries-file   Query Filename"         << "\n"
                << "\t-d/--data-count     Data Count"             << "\n"
                << "\t-q/--queries-count  Query Count"            << "\n"
                << "\t-s/--dimention      Vector Dimension"       << std::endl;
   }                       
   catch( distcal::CsvException ex )
   {
      std::cout << ex.what() << ": " << ex.msg() << std::endl;
   }
   catch (const std::regex_error& ex)
   {
      std::cout << ex.what();
   }
}