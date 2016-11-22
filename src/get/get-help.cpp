//Display the help
int get_help(void)
{
  //Display the help
  cout << "Cover Get " << _VERSION << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Get coverage values of a region or list of regions." << endl << endl;

  //Display the usage
  cout << "Usage: covertools get -region <REGION> -cover <COVER_FILE> -index <INDEX_FILE>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory: " << endl;
  cout << "\t-region\t" << "Wanted region name." << endl;
  cout << "\t-cover\t"  << "Path to the input coverage file." << endl;
  cout << "\t-index\t"  << "Path to the output coverage file." << endl;

  //Exit
  return 0;
}
