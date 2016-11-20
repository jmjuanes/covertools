//Display the help
int fix_help(void)
{
  //Display the help
  cout << "Cover Fix " << endl;
  cout << "Version: " << _VERSION << endl;
  cout << "Add all positions on the coverage matrix that has zero depth." << endl << endl;

  //Display the usage
  cout << "Usage: covertools fix -bed <BED_FILE> -ci <COVER_INPUT> -co <COVER_OUTPUT>" << endl << endl;

  //Display the mandatory arguments
  cout << "Mandatory: " << endl;
  cout << "\t-bed\t"    << "Path to the BED file with the delimited regions." << endl;
  cout << "\t-ci\t"     << "Path to the input coverage file." << endl;
  cout << "\t-co\t"     << "Path to the output coverage file." << endl;

  //Exit
  return 0;
}
