//Main function
int fix_main(int argc, char *argv[])
{
  //Display help
  bool show_help = false;

  //Has parameters
  bool regions_has = false, cover_input_has = false, cover_output_has = false;

  //Files parameters
  string regions_file, cover_input_file, cover_output_file;

  //Check the number of arguments
  if(argc == 1){ show_help = true; }

  //Check for showing the help
  if(show_help == true){ return fix_help(); }

  //Read all the arguments
  for(int i = 1; i < argc; i++)
  {
    //Get the argument value
    string arg_value = argv[i];

    //Get the argument length
    int arg_length = (int) strlen(argv[i]);

    //Check the -bed option
    if(check_opt("--bed", 5, arg_value, arg_length) == true)
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

    //Check the cover input option -ci
    else if(check_opt("--cover", 7, arg_value, arg_length) == true)
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

    //Check the cover output option -out
    else if(check_opt("--out", 5, arg_value, arg_length) == true)
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

    //Unknown option
    else
    {
      //Display unknow parameter
      cerr << "ERROR: unknown parameter " << arg_value << endl; show_help = true;
    }
  }

  //Check for no regions file
  if(regions_has == false){ cerr << "ERROR: no BED file provided" << endl; show_help = true; }

  //Check for no input cover file
  if(cover_input_has == false){ cerr << "ERROR: no input coverage file provided" << endl; show_help = true; }

  //Check for no output cover file
  if(cover_output_has == false){ cerr << "ERROR: no output coverage file provided" << endl; show_help = true; }

  //Check for display the help
  if(show_help == true){ return fix_help(); }

  //ifstreams
  ifstream input_cover, input_regions;

  //Ofstreams
  ofstream output_cover;

  //Open the cover file
  input_cover.open(cover_input_file.c_str());

  //Open the regions file
  input_regions.open(regions_file.c_str());

  //Check for error opening the cover file
  if(input_cover.is_open() == false)
  {
    //Display the error
    cerr << "Error opening " << cover_input_file << endl; return EXIT_FAILURE;
  }

  //Check for error opening the regions file
  if(input_regions.is_open() == false)
  {
    //Display error and exit
    cerr << "Error opening " << regions_file << endl; return EXIT_FAILURE;
  }

  //Open the output cover
  output_cover.open(cover_output_file.c_str());

  //Check for error
  if(output_cover.is_open() == false)
  {
    //Display error
    cerr << "Error opening " << cover_output_file << endl; return EXIT_FAILURE;
  }

  //Auxiliar strings
  string aux, line = "", arr[3];

  //Auxiliar integers
  int position = 0;

  //Read all the regions
  while(!input_regions.eof())
  {
    //Get the line from the regions file
    getline(input_regions, aux);

    //Check for empty region
    if(aux == ""){ break; }

    //Build the region
    Region region = tab_to_region(aux);

    //Initialize the position
    position = region.start;

    //Read the cover file
    while(!input_cover.eof())
    {
      //Get the line
      if(line == ""){ getline(input_cover, line); }

      //Check for empty line
      if(line == ""){ break; }

      //Converts the string to array
      str_split(line, arr, 3, "\t");

      //Get the position
      int pos = stoi(arr[1]);

      //Check if the position is out of the region or if the chromosome is different
      if(pos < region.start || region.end < pos || region.chromosome != arr[0])
      {
        //Region finished
        break;
      }

      //Add the missing positions
      while(position < pos)
      {
        //Add the line
        output_cover << region.chromosome << "\t" << position << "\t" << "0" << endl;

        //Increment the position counter
        position = position + 1;
      }

      //Add the line
      output_cover << line << endl;

      //Update the position
      position = position + 1;

      //Reset the line
      line = "";
    }

    //Add the others positions on the region
    while(position <= region.end)
    {
      //Add the line
      output_cover << region.chromosome << "\t" << position << "\t" << "0" << endl;

      //Increment the position counter
      position = position + 1;
    }
  }

  //Close the output file
  output_cover.close();

  //Close the input cover file
  input_cover.close();

  //Close the regions file
  input_regions.close();

  //Exit
  return 0;
}
