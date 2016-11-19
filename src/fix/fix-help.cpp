//Display the help
int fix_help(void)
{
  //Display the help
  cout << "Cover Fix " << _VERSION << endl;

  //Display the usage
  cout << "Usage: covertools fix -bed <BED_FILE> -cover <COVER_FILE> -out <OUT_FILE>" << endl << endl;

  //Options
  cout << "Options:" << endl;

  // -bed option
  cout << "\t-bed\t" << "Path to the BED file" << endl;

  // -cover option
  cout << "\t-cover\t" << "Path to the coverage file" << endl;

  // -out option
  cout << "\t-out\t" << "Path to the output cover file" << endl;

  //Exit
  return 0;
}
