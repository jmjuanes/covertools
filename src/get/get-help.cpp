//Display the help
int get_help(void)
{
  //Display the help
  cout << "Cover Get " << _VERSION << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Get coverage values of a region or list of regions." << endl << endl;

  //Display the usage
  //cout << "Usage: covertools get --region <REGION> --cover <COVER_FILE> --index <INDEX_FILE> --out <OUTPUT_FILE>" << endl << endl;
  cout << "Usage: covertools get --region <REGION> --cover <COVER_FILE> --index <INDEX_FILE>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory options: " << endl;
  cout << " --region  " << "Wanted region name." << endl;
  cout << " --cover   " << "Path to the input coverage file." << endl;
  cout << " --index   " << "Path to the index file." << endl;
  //cout << " --out     " << "Path to the output coverage file." << endl;

  //Exit
  return 0;
}
