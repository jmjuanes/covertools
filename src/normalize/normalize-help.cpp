//Display the help
int normalize_help(void)
{
  //Display the normalize help
  cout << "Cover Normalize " << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Normalize the coverage matrix" << endl << endl;

  //Display the usage
  cout << "Usage: covertools normalize [OPTIONS] --cover <COVER_INPUT> --out <COVER_OUTPUT>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory: " << endl;
  cout << " --cover  " << "Path to the input coverage file." << endl;
  cout << " --out    " << "Path to the output coverage file." << endl;

  //Add an extra line
  cout << endl;

  //Display the optional arguments
  cout << "Options: " << endl;
  cout << " --a      " << "Select the algorithm to apply. Default is 'mean' algorithm." << endl;

  //Exit
  return 0;
}
