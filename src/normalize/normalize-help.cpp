//Display the help
int normalize_help(void)
{
  //Display the normalize help
  cout << "Cover Normalize " << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Normalize the coverage matrix" << endl << endl;

  //Display the usage
  cout << "Usage: covertools normalize -a <ALGORITHM> -ci <COVER_INPUT> -co <COVER_OUTPUT>" << endl << endl;

  //Display the options
  cout << "Options: " << endl;
  cout << "\t-a\t"    << "Select the algorithm to apply. Default is 'mean' algorithm." << endl;
  cout << "\t-ci\t"   << "Path to the input coverage file." << endl;
  cout << "\t-co\t"   << "Path to the output coverage file." << endl;

  //Exit
  return 0;
}
