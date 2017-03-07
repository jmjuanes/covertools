//Main indel command function
int indel_main(int argc, char *argv[])
{
  //Display help
  bool show_help = false;

  //Has parameters
  bool regions_has = false, cover_has = false, cover_control_has = false;
  bool min_region_has = false, min_cover_has = false, threshold_has = false;

  //Files parameters
  string cover_file, regions_file;

  //Integer parameters
  int cover_num, cover_control;

  //Float parameters
  float min_region = 0, min_cover = 0, threshold = 0;

  //Check the number of arguments
  if(argc == 1){ show_help = true; }

  //Check for showing the help
  if(show_help == true){ return indel_help(); }

  //Read all the arguments
  for(int i = 1; i < argc; i++)
  {
    //Get the argument value
    string arg_value = argv[i];

    //Get the argument length
    int arg_length = (int) strlen(argv[i]);

    //Check the cover input option
    if(check_opt("--cover", 7, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set cover as true
      cover_has = true;

      //Save the cover file
      cover_file = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }

    //Check the output regions file
    else if(check_opt("--out", 5, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set regions file path as true
      regions_has = true;

      //Save the regions file path
      regions_file = argv[i + 1];

      //Increment the i counter
      i = i + 1;
    }

    //Check the control column
    else if(check_opt("--control", 9, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set control as true
      cover_control_has = true;

      //Save the control column
      cover_control = stoi(argv[i + 1]);

      //Increment the i counter
      i = i + 1;
    }

    //Check the threshold option
    else if(check_opt("--threshold", 11, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set threshold as true
      threshold_has = true;

      //Save the threshold value
      threshold = stof(argv[i + 1]);

      //Increment the i counter
      i = i + 1;
    }

    //Check the min region option
    else if(check_opt("--minRegion", 11, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set min region as true
      min_region_has = true;

      //Save the min region value
      min_region = stof(argv[i + 1]);

      //Increment the i counter
      i = i + 1;
    }

    //Check the min cover option
    else if(check_opt("--minCover", 9, arg_value, arg_length) == true)
    {
      //Check the count
      if(argc <= i + 1){ continue; }

      //Set min cover as true
      min_cover_has = true;

      //Save the min cover value
      min_cover = stof(argv[i + 1]);

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

  //Check for no cover file
  if(cover_has == false){ cerr << "ERROR: no coverage file provided" << endl; show_help = true; }

  //Check for no output regions file
  if(regions_has == false){ cerr << "ERROR: no output regions file provided" << endl; show_help = true; }

  //Check for no control option
  if(cover_control_has == false){ cover_control = -1; }

  //Check for no threshold
  if(threshold_has == false){ cerr << "ERROR: no threshold value provided" << endl; show_help = true; }

  //Check for no min cover value
  if(min_cover_has == false){ cerr << "ERROR: no minimum cover value provided" << endl; show_help = true; }

  //Check for no min region size
  if(min_region_has == false){ cerr << "ERROR: no minimum region size provided" << endl; show_help = true; }

  //Check for display the help
  if(show_help == true){ return indel_help(); }

  //Count the number of coverage columns
  cover_num = cover_count(cover_file);

  //Initialize the coverage lists
  CoverList list_cover, list_control;

  //Initialize the regions list
  RegionList list_regions;

  //Initialize the list
  cover_read(cover_file, list_cover, cover_num);

  //Build the control coverage
  indel_control(list_cover, list_control, cover_num, cover_control);

  //Find the regions
  indel_find(list_cover, list_control, list_regions, cover_num, cover_control, min_cover, min_region, threshold);

  //Save the regions
  region_save(regions_file, list_regions);

  //Delete the cover list
  cover_delete(list_cover);

  //Delete the cover control list
  cover_delete(list_control);

  //Delete the regions list
  region_delete(list_regions);

  //Exit
  return 0;
}
