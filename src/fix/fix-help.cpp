//Display the help
int fix_help(void)
{
  //Display the help
  cout << "Cover Fix " << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Add all positions on the coverage matrix that has zero depth." << endl << endl;

  //Display the usage
  cout << "Usage: covertools fix --bed <BED_FILE> --cover <COVER_INPUT> --out <COVER_OUTPUT>" << endl << endl;

  //Display the mandatory options
  cout << "Mandatory options: " << endl;
  cout << " --bed    " << "Path to the BED file with the delimited regions." << endl;
  cout << " --cover  " << "Path to the input coverage file." << endl;
  cout << " --out    " << "Path to the output coverage file." << endl;

  //Exit
  return 0;
}
