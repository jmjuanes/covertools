//Normalize main function
int normalize_main(int argc, char *argv[])
{
  //Display help
  bool show_help = false;

  //Has parameters
  bool cover_input_has = false, cover_output_has = false, cover_num_has = false, algorithm_has = false;

  //String parameters
  string cover_input_file, cover_output_file, algorithm;

  //Cover num
  int cover_num = 0;

  //Check the number of arguments
  if(argc == 1){ show_help = true; }

  //Check for show the help
  if(show_help == true){ return normalize_help(); }

  //Read all the arguments
  for(int i = 1; i < argc; i++)
  {
    //Get the argument value
    string arg_value = argv[i];

    //Get the argument length
    int arg_length = (int) strlen(argv[i]);

    //Check the algorithm option
    if(checkOpt("-a", 2, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set the algorithm
      algorithm_has = true;

      //Save the algorithm name
      algorithm = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }

    //Check the cover input option
    else if(checkOpt("-cover", 6, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set input cover
      cover_input_has = true;

      //Save the input cover file
      cover_input_file = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }

    //Check the cover output option
    else if(checkOpt("-out", 4, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set output cover
      cover_output_has = true;

      //Save the output cover file
      cover_output_file = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }

    //Check the -n option
    else if(checkOpt("-n", 2, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set num
      cover_num_has = true;

      //Save the number
      cover_num = stoi(argv[i + 1]);

      //Increment the i counter
      i = i + 1;
    }

    //Unknown option
    else
    {
      //Display unknow parameter
      cerr << "ERROR: unknown parameter " << arg_value << endl; show_help = true;
    }
  }

  //Check for no input cover file
  if(cover_input_has == false){ cerr << "ERROR: no input cover file provided" << endl; show_help = true; }

  //Check for no output cover file
  if(cover_output_has == false){ cerr << "ERROR: no output cover file provided" << endl; show_help = true; }

  //Check for no cover num
  if(cover_num_has == false){ cerr << "ERROR: no cover num provided" << endl; show_help = true; }

  //Check for no algorithm
  if(algorithm_has == false){ algorithm = "mean"; }

  //Check for display the help
  if(show_help == true){ return normalize_help(); }

  //Get the new list
  Chr l = NULL;

  //Initialize the list
  coverRead(cover_input_file, l, cover_num);

  //Check the normalize algorithm
  if(algorithm == "mean")
  {
    //Apply the mean algorithm
    normalize_mean(l, cover_num);
  }

  //Save the cover file
  coverSave(cover_output_file, l, cover_num);

  //Delete the cover list
  coverDelete(l);

  //Exit
  return 0;
}
