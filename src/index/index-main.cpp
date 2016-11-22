//Main function
int index_main(int argc, char *argv[])
{
  //Display help
  bool show_help = false;

  //Has parameters
  bool regions_has = false, cover_has = false, index_has = false;

  //Files parameters
  string regions_file, cover_file, index_file;

  //Check the number of arguments
  if(argc == 1){ return index_help(); }

  //Read all the arguments
  for(int i = 1; i < argc; i++)
  {
    //Get the argument value
    string arg_value = argv[i];

    //Get the argument length
    int arg_length = (int) strlen(argv[i]);

    //Check the bed file argument
    if(checkOpt("-bed", 4, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set regions file as true
      regions_has = true;

      //Save the regions file
      regions_file = argv[i + 1];

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

    //Check the index output file option
    else if(checkOpt("-out", 4, arg_value, arg_length) == true)
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

  //Check for no regions file
  if(regions_has == false){ cerr << "ERROR: no regions file provided" << endl; show_help = true; }

  //Check for no input cover file
  if(cover_has == false){ cerr << "ERROR: no input cover file provided" << endl; show_help = true; }

  //Check for no output cover file
  if(index_has == false){ cerr << "ERROR: no output index file provided" << endl; show_help = true; }

  //Check for display the help
  if(show_help == true){ return index_help(); }

  //ifstreams
  ifstream input_cover, input_regions;

  //Ofstreams
  ofstream output_index;

  //Open the cover file
  input_cover.open(cover_file.c_str());

  //Open the regions file
  input_regions.open(regions_file.c_str());

  //Check for error opening the cover file
  if(input_cover.is_open() == false)
  {
    //Display the error
    cerr << "Error opening " << cover_file << endl; return EXIT_FAILURE;
  }

  //Check for error opening the regions file
  if(input_regions.is_open() == false)
  {
    //Display error and exit
    cerr << "Error opening " << regions_file << endl; return EXIT_FAILURE;
  }

  //Open the output cover
  output_index.open(index_file.c_str());

  //Check for error
  if(output_index.is_open() == false)
  {
    //Display error
    cerr << "Error opening " << index_file << endl; return EXIT_FAILURE;
  }

  //Auxiliar strings
  string aux, line = "", arr[3];

  //Auxiliar integers
  int lines_count = 0, buff_start = 0, buff_end = 0;

  //Read all the regions
  while(!input_regions.eof())
  {
    //Get the line from the regions file
    getline(input_regions, aux);

    //Check for empty region
    if(aux == ""){ break; }

    //Get the region object
    Region region = tabToRegion(aux);

    //Reset the lines count
    lines_count = 0;

    //Reset the buffer start
    buff_start = buff_end;

    //Read the cover file
    while(!input_cover.eof())
    {
      //Get the line
      if(line == ""){ getline(input_cover, line); }

      //Check for empty line
      if(line == ""){ break; }

      //Converts the string to array
      strArr(line, arr, 3, "\t");

      //Get the position
      int pos = stoi(arr[1]);

      //Check the position
      if(region.end < pos || region.chromosome != arr[0]){ break; }

      //Increment the buffer end
      buff_end = buff_end + line.size() + 1;

      //Increment the counter
      lines_count = lines_count + 1;

      //Reset the line
      line = "";
    }

    //Save the values
    output_index << region.name << "\t" << buff_start << "\t" << buff_end << "\t" << lines_count << endl;
  }

  //Close the index file
  output_index.close();

  //Close the input cover file
  input_cover.close();

  //Close the regions file
  input_regions.close();

  //Exit
  return 0;
}
