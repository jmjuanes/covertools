//Print the indel command help
int indel_help(void)
{
  //Display the help
  cout << "Covertools Insertions and Deletions " << _VERSION << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Find regions with insertions or deletions." << endl << endl;

  //Display the usage
  //cout << "Usage: covertools indel [OPTIONS] --cover <COVER_FILE> --out <OUTPUT_FILE>" << endl << endl;
  cout << "Usage: covertools indel [OPTIONS] --cover <COVER_FILE>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory:   " << endl;
  cout << " --cover      " << "Path to the coverage file." << endl;
  cout << " --threshold  " << "Threshold value" << endl;
  cout << " --minRegion  " << "Minimum region length" << endl;
  cout << " --minCover   " << "Minimum coverage value" << endl;
  //cout << " --out        " << "Path to the output regions file." << endl;

  //Line break
  cout << endl;

  //Display the options
  cout << "Options:      " << endl;
  cout << " --control    " << "Column of the cover matrix to be used as a control." << endl;

  //Exit
  return 0;
}
