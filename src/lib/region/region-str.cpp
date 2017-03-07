//Convert a region structure to string
string region_to_str(Region region)
{
  //Initialize the output string
  string str = "";

  //Add the chromosome
  str = str + region.chromosome + ":";

  //Add the start and end positions
  str = str + to_string(region.start) + "-" + to_string(region.end);

  //Return the string
  return str;
}

//Convert a tabulated string to a region structure
Region tab_to_region(string str)
{
  //Initialize the new region
  Region region;

  //Generate the new array string
  string arr[10];

  //Split the region
  int total = str_split(str, arr, 10, "\t");

  //Check the total length
  if(total < 4)
  {
    //Display error
    cerr << "Invalid regions object" << endl;

    //Exit with error
    exit(EXIT_FAILURE);
  }

  //Save the chromosome name
  region.chromosome = arr[0];

  //Save the start position
  region.start = stoi(arr[1]);

  //Save the end position
  region.end = stoi(arr[2]);

  //Save the name
  region.name = arr[3];

  //Calculate the region length
  region.length = abs(region.end - region.start) + 1;

  //Return the new region
  return region;
}
