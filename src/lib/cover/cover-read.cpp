//Read a cover file
void coverRead(string file, Chr & l, int n)
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
  string aux, arr[_MAX_BAMS], chrnow = "null";

  //Auxiliar pointers for the positions
  Pos p, endp = NULL;

  //Auxiliar pointers for the chromosomes
  Chr c, endc = NULL;

  //Read the input file
  while(!input.eof())
  {
    //Get the first line
    getline(input, aux);

    //Check if is empty string
    if(aux == "") { continue; }

    //Converts string to array
    strArr(aux, arr, _MAX_BAMS, "\t");

    //Create the new position
    p = new Position;

    //Save the position
    p->pos = stoi(arr[1]);

    //Initialize the cover values
    p->cover = new float[n];

    //Read all the cover values
    for(int i = 0; i < n; i++)
    {
      //Save the cover value
      p->cover[i] = stof(arr[i + 2]);
    }

    //Next element
    p->next = NULL;

    //Check the chromosome
    if(arr[0] != chrnow)
    {
      //Create a new chromosome
      c = new Chromosome;

      //Save the chromosome name
      c->name = arr[0];

      //Save the positions list
      c->positions = p;

      //Get the last element
      endp = p;

      //Save the chromosome now
      chrnow = arr[0];

      //Initialize the list
      if(l == NULL){ l = c; }

      //Save the next point
      else{ endc->next = c; }

      //Next
      endc = c;
    }
    else
    {
      //Add the next position
      endp->next = p;

      //Save the position
      endp = p;
    }
  }

  //Finish the list
  endp->next = NULL;

  //Close the file
  input.close();
}
