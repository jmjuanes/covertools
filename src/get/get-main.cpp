//Main function
int get_main(int argc, char *argv[])
{
  //Display help
  bool show_help = false;

  //Has parameters
  bool cover_has = false, index_has = false, region_has = false;

  //Files parameters
  string region, cover_file, index_file;

  //Check the number of arguments
  if(argc == 1){ return get_help(); }

  //Read all the arguments
  for(int i = 1; i < argc; i++)
  {
    //Get the argument value
    string arg_value = argv[i];

    //Get the argument length
    int arg_length = (int) strlen(argv[i]);

    //Check the region argument
    if(checkOpt("-region", 8, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set region name as true
      region_has = true;

      //Save the region name
      region = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }

    //Check the cover input argument
    else if(checkOpt("-cover", 6, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set input cover
      cover_has = true;

      //Save the input cover file
      cover_file = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }

    //Check the index argument
    else if(checkOpt("-index", 2, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set output cover
      index_has = true;

      //Save the output cover file
      index_file = argv[i + 1];

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

  //Check for no region name
  if(region_has == false){ cerr << "ERROR: no wanted region provided" << endl; show_help = true; }

  //Check for no input cover file
  if(cover_has == false){ cerr << "ERROR: no cover file provided" << endl; show_help = true; }

  //Check for no output cover file
  if(index_has == false){ cerr << "ERROR: no output index file provided" << endl; show_help = true; }

  //Check for display the help
  if(show_help == true){ return get_help(); }

  //ifstreams
  ifstream input_cover, input_index;

  //Open the cover file
  input_cover.open(cover_file.c_str());

  //Open the index file
  input_index.open(index_file.c_str());

  //Check for error opening the cover file
  if(input_cover.is_open() == false)
  {
    //Display the error
    cerr << "Error opening " << cover_file << endl; return EXIT_FAILURE;
  }

  //Check for error opening the index file
  if(input_index.is_open() == false)
  {
    //Display error and exit
    cerr << "Error opening " << index_file << endl; return EXIT_FAILURE;
  }

  //Auxiliar strings
  string aux, line = "", arr[4];

  //Parse the region
  region = strLower(region);

  //Read all the regions
  while(!input_index.eof())
  {
    //Get the line from the regions file
    getline(input_index, aux);

    //Check for empty region
    if(aux == ""){ break; }

    //Split the region
    strSplit(aux, arr, 4, "\t");

    //Check the region name
    if(strLower(arr[0]) != region){ continue; }

    //Get the start position
    int start = stoi(arr[1]);

    //Get the lines count
    int lines = stoi(arr[3]);

    //Go to the start position
    input_cover.seekg(start, ios::beg);

    //Counter
    int counter = 0;

    //Get the number of lines
    while(counter < lines)
    {
      //Get the line
      getline(input_cover, line);

      //Display the line on console
      cout << line << endl;

      //Increment the counter
      counter = counter + 1;
    }

    //Exit
    break;
  }

  //Close the input cover file
  input_cover.close();

  //Close the index file
  input_index.close();

  //Exit
  return 0;
}
