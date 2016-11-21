//Display the help
int normalize_help(void)
{
  //Display the normalize help
  cout << "Cover Normalize " << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Normalize the coverage matrix" << endl << endl;

  //Display the usage
  cout << "Usage: covertools normalize [OPTIONS] -cover <COVER_INPUT> -n <NUMBER_COVERAGES> -out <COVER_OUTPUT>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory: " << endl;
  cout << "\t-cover\t"  << "Path to the input coverage file." << endl;
  cout << "\t-out\t"    << "Path to the output coverage file." << endl;
  cout << "\t-n\t"      << "Number of coverage columns on the coverage file" << endl;

  //Add an extra line
  cout << endl;

  //Display the optional arguments
  cout << "Options: " << endl;
  cout << "\t-a\t"    << "Select the algorithm to apply. Default is 'mean' algorithm." << endl;

  //Exit
  return 0;
}
