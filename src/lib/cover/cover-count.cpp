//Count the number of coverage columns in a file
int cover_count(string file)
{
  //Create the ifstream object
  ifstream input;

  //Number of cover columns
  int num = 0;

  //Auxuliar strings
  string str, arr[_MAX_BAMS];

  //Open the cover file
  input.open(file.c_str());

  //Check for error opening the cover file
  if(input.is_open() == false)
  {
    //Display the error
    cerr << "Error opening " << file << endl;

    //Exit
    exit(EXIT_FAILURE);
  }

  //Read the input file
  while(!input.eof())
  {
    //Get the first line
    getline(input, str);

    //Check if is empty string
    if(str == "") { continue; }

    //Converts string to array
    num = str_split(str, arr, _MAX_BAMS, "\t") - 2;

    //Exit loop
    break;
  }

  //Close the file
  input.close();

  //Return the number of cover values
  return num;
}
