//Display the help
int index_help(void)
{
  //Display the help
  cout << "Cover Index " << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Index a coverage file." << endl << endl;

  //Display the usage
  cout << "Usage: covertools index -bed <BED_FILE> -cover <COVER_FILE> -out <INDEX_OUTPUT_FILE>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory: " << endl;
  cout << "\t-bed\t"    << "Path to the BED file with the delimited regions." << endl;
  cout << "\t-cover\t"  << "Path to the input coverage file." << endl;
  cout << "\t-out\t"    << "Path to the output index file." << endl;

  //Exit
  return 0;
}
