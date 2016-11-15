//Import dependencies
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>

//Namespace
using namespace std;

//Include libs
#include "lib/arguments.cpp"
#include "lib/str-arr.cpp"
#include "lib/region.cpp"
#include "lib/version.cpp"

//Include cover libs
#include "lib/cover/cover-struct.cpp"
#include "lib/cover/cover-delete.cpp"
#include "lib/cover/cover-read.cpp"
#include "lib/cover/cover-save.cpp"

//Include fix command functions
#include "fix/fix-help.cpp"
#include "fix/fix-main.cpp"

//Include get command function
#include "get/get-help.cpp"
#include "get/get-main.cpp"

//Include index command functions
#include "index/index-help.cpp"
#include "index/index-main.cpp"

//Include normalize command functions
#include "normalize/normalize-help.cpp"
#include "normalize/normalize-apply.cpp"
#include "normalize/normalize-mean.cpp"
#include "normalize/normalize-main.cpp"

//Include covertools submodules
#include "covertools-help.cpp"

//Main function
int main(int argc, char **argv)
{
  //Check the number of commands
  if(argc < 2){ return covertools_help(1); }

  //Get the command
  string cmd = argv[1];

  //Check the fix command
  if(cmd == "fix"){ return fix_main(argc-1, argv+1); }

  //Check the get command
  if(cmd == "get"){ return get_main(argc-1, argv+1); }

  //Check the index command
  if(cmd == "index"){ return index_main(argc-1, argv+1); } 

  //Check the normalize command
  else if(cmd == "normalize"){ return normalize_main(argc-1, argv+1); }

  //Check for help
  else if(cmd == "-h" || cmd == "--help" || cmd == "help"){ return covertools_help(0); }

  //Unknow command
  else
  {
    //Display error
    cerr << "Unknown command " << cmd << endl;
    return 1;
  }

  //Exit
  return 0;
}
