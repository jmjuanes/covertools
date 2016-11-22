//Read a cover file
void coverRead(string file, CoverList & l, int n)
{
  //Create the ifstream object
  ifstream input;

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

  //Auxuliar strings
  string str, arr[_MAX_BAMS], chrnow = "null";

  //Auxiliar pointers for the chromosomes
  CoverList aux, end;

  //Initialize the list
  l = NULL;

  //Read the input file
  while(!input.eof())
  {
    //Get the first line
    getline(input, str);

    //Check if is empty string
    if(str == "") { continue; }

    //Converts string to array
    strArr(str, arr, _MAX_BAMS, "\t");

    //Create the new cover value
    aux = new Cover;

    //Save the chromosome
    aux->chromosome = arr[0];

    //Save the position
    aux->position = stoi(arr[1]);

    //Initialize the coverage values
    aux->values = new float[n];

    //Read all the cover values
    for(int i = 0; i < n; i++)
    {
      //Save the cover value
      aux->values[i] = stof(arr[i + 2]);
    }

    //Next element
    aux->next = NULL;

    //Check for empty list
    if(l == NULL)
    {
      //Initialize the list
      l = aux;

      //Initialize the last element pointer
      end = l;
    }
    else
    {
      //Save this element
      end->next = aux;

      //Point to the next element
      end = aux;
    }
  }

  //Finish the list
  end->next = NULL;

  //Close the file
  input.close();
}
