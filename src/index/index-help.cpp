//Display the help
int index_help(void)
{
  //Display the help
  cout << "Cover Index " << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Index a coverage file." << endl << endl;

  //Display the usage
  cout << "Usage: covertools index --bed <BED_FILE> --cover <COVER_FILE> --out <INDEX_OUTPUT_FILE>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory: " << endl;
  cout << " --bed    " << "Path to the BED file with the delimited regions." << endl;
  cout << " --cover  " << "Path to the input coverage file." << endl;
  cout << " --out    " << "Path to the output index file." << endl;

  //Exit
  return 0;
}
