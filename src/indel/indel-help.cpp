//Print the indel command help
int indel_help(void)
{
  //Display the help
  cout << "Covertools Insertions and Deletions " << _VERSION << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Find regions with insertions or deletions." << endl << endl;

  //Display the usage
  cout << "Usage: covertools indel [OPTIONS] -cover <COVER_FILE> -n <NUM_COVERS> -out <OUTPUT_FILE>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory: "  << endl;
  cout << "\t-cover\t"   << "Path to the coverage file." << endl;
  cout << "\t-n\t"       << "Number of coverage columns." << endl;
  cout << "\t-threshold" << "Threshold value" << endl;
  cout << "\t-minRegion" << "Minimum region length" << endl;
  cout << "\t-minCover"  << "Minimum coverage value" << endl;
  cout << "\t-out\t"     << "Path to the output regions file." << endl;

  //Line break
  cout << endl;

  //Display the options
  cout << "Options: "    << endl;
  cout << "\t-control\t" << "Column of the cover matrix to be used as a control." << endl;

  //Exit
  return 0;
}
