//Print the indel command help
int cnv_help(void)
{
  //Display the help
  cout << "Covertools Insertions and Deletions " << _VERSION << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Find regions with insertions or deletions." << endl << endl;

  //Display the usage
  cout << "Usage: covertools indel [OPTIONS] -cover <COVER_FILE> -index <INDEX_FILE> -out <OUTPUT_FILE>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory: " << endl;
  cout << "\t-cover\t"  << "Path to the coverage file." << endl;
  cout << "\t-index\t"  << "Path to the index file." << endl;
  cout << "\t-out\t"    << "Path to the output regions file." << endl;

  //Line break
  cout << endl;

  //Display the options
  cout << "Options: "    << endl;
  cout << "\t-control\t" << "Column of the cover matrix to be used as a control." << endl;

  //Exit
  return 0;
}
