//Region class
class Region
{
  //Public values
  public:
    //Region chromosome and name
    string chromosome, name;

    //Start and end positions
    int start, end;

    //Error boolean
    bool error;

    //Constructor
    Region(string);

    //Calculate the region length
    int length(void);
};

//Region constructor
Region::Region(string r)
{
  //Initialize the error
  error = true;

  //Generate the new array string
  string arr[10];

  //Split the region
  int total = strArr(r, arr, 10, "\t");

  //Check the total length
  if(total < 4)
  {
    //Display error
    cerr << "Invalid regions object" << endl;

    //Exit with error
    exit(EXIT_FAILURE);
  }

  //Save the chromosome name
  chromosome = arr[0];

  //Save the start position
  start = stoi(arr[1]);

  //Save the end position
  end = stoi(arr[2]);

  //Save the name
  name = arr[3];

  //Set error as false
  error = false;
}

//Return the length
int Region::length(void)
{
  //Return the legth
  return abs(end - start) + 1;
}
