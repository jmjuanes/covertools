//Import dependencies
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cctype>

//Namespace
using namespace std;

//Include libs
#include "lib/variables.cpp"
#include "lib/options.cpp"
#include "lib/str.cpp"

//Include cover libs
#include "lib/cover/cover-struct.cpp"
#include "lib/cover/cover-count.cpp"
#include "lib/cover/cover-delete.cpp"
#include "lib/cover/cover-read.cpp"
#include "lib/cover/cover-save.cpp"

//Include regions libs
#include "lib/region/region-struct.cpp"
#include "lib/region/region-delete.cpp"
#include "lib/region/region-print.cpp"
#include "lib/region/region-save.cpp"
#include "lib/region/region-str.cpp"

//Include fix command functions
#include "fix/fix-help.cpp"
#include "fix/fix-main.cpp"

//Include get command function
#include "get/get-help.cpp"
#include "get/get-main.cpp"

//Include indel command functions
#include "indel/indel-help.cpp"
#include "indel/indel-control.cpp"
#include "indel/indel-find-valid.cpp"
#include "indel/indel-find-compare.cpp"
#include "indel/indel-find.cpp"
#include "indel/indel-main.cpp"

//Include index command functions
#include "index/index-help.cpp"
#include "index/index-main.cpp"

//Include normalize command functions
#include "normalize/normalize-help.cpp"
#include "normalize/normalize-mean.cpp"
#include "normalize/normalize-main.cpp"

//Include covertools submodules
#include "covertools-help.cpp"

//Main function
int main(int argc, char **argv)
{
  //Check the number of commands
  if(argc < 2){ return covertools_help(); }

  //Get the command
  string cmd = argv[1];

  //Check the fix command
  if(cmd == "fix"){ return fix_main(argc-1, argv+1); }

  //Check the get command
  if(cmd == "get"){ return get_main(argc-1, argv+1); }

  //Check the indel command
  if(cmd == "indel"){ return indel_main(argc-1, argv+1); }

  //Check the index command
  if(cmd == "index"){ return index_main(argc-1, argv+1); }

  //Check the normalize command
  else if(cmd == "normalize"){ return normalize_main(argc-1, argv+1); }

  //Check for help
  else if(cmd == "-h" || cmd == "--help" || cmd == "help"){ return covertools_help(); }

  //Unknow command
  else
  {
    //Display error
    cerr << "Unknown command " << cmd << endl;

    //Exit with error
    return 1;
  }

  //Exit
  return 0;
}
