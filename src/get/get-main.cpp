//Main function
int get_main(int argc, char *argv[])
{
  //Display help
  bool show_help = false;

  //Has parameters
  bool cover_has = false, index_has = false, region_name_has = false, region_file_has = false;

  //Files parameters
  string region_name, region_file, cover_file, index_file;

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
    if(check_opt("--region", 8, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set region name as true
      region_name_has = true;

      //Save the region name
      region_name = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }

    //Check the cover input argument
    else if(check_opt("--cover", 7, arg_value, arg_length) == true)
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

    //Check the output regions file argument
    // --> Now we will display the coverage values in console instead of save it to a file
    // --> If user wants to save it to a file, he must pipe the output to the file manually
    /*
    else if(check_opt("--out", 5, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set input cover
      region_file_has = true;

      //Save the input cover file
      region_file = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }
    */

    //Check the index argument
    else if(check_opt("--index", 7, arg_value, arg_length) == true)
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
  if(region_name_has == false){ cerr << "ERROR: no wanted region provided" << endl; show_help = true; }

  //Check for no input cover file
  if(cover_has == false){ cerr << "ERROR: no cover file provided" << endl; show_help = true; }

  //Check for no input index file
  if(index_has == false){ cerr << "ERROR: no index file provided" << endl; show_help = true; }

  //Check for no output regions file
  // --> Output will be printed in console
  //if(region_file_has == false){ cerr << "ERROR: no output regions file provided" << endl; show_help = true; }

  //Check for display the help
  if(show_help == true){ return get_help(); }

  //ifstreams
  ifstream input_cover, input_index;

  //Ofstreams
  //ofstream output_region;

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

  /*
  // --> Outputs will be printed in console
  //Open the output cover
  output_region.open(region_file.c_str());

  //Check for error
  if(output_region.is_open() == false)
  {
    //Display error
    cerr << "Error opening " << region_file << endl; return EXIT_FAILURE;
  }
  */

  //Auxiliar strings
  string aux, line = "", arr[4];

  //Parse the region name
  region_name = str_lower(region_name);

  //Read all the regions
  while(!input_index.eof())
  {
    //Get the line from the regions file
    getline(input_index, aux);

    //Check for empty region
    if(aux == ""){ break; }

    //Split the region
    str_split(aux, arr, 4, "\t");

    //Check the region name
    if(str_lower(arr[0]) != region_name){ continue; }

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

      //Save the line to ---file---- console
      //output_region << line << endl;
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

  //Close the region file
  //output_region.close();

  //Exit
  return 0;
}
