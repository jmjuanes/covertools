//Save the list to file
void coverSave(string file, CoverList l, int n)
{
  //Ofstream object
  ofstream output;

  //Open the files
  output.open(file.c_str());

  //Check for error opening the cover file
  if(output.is_open() == false)
  {
    //Display the error
    cerr << "Error opening " << file << endl;

    //Exit
    exit(EXIT_FAILURE);
  }

  //Auxiliar pointer
  CoverList aux = l;

  //Tab character
  string tab = "\t";

  //Read all the coverage positions
  while(aux != NULL)
  {
    //Save to file
    output << aux->chromosome << tab << aux->position << tab;

    //Save all the covers
    for(int i = 0; i < n; i++)
    {
      //Check the index
      if(i > 0){ output << tab; }

      //Save the cover for the file i
      output << aux->values[i];
    }

    //End the line
    output << endl;

    //Next coverage value
    aux = aux->next;
  }

  //Close the output file
  output.close();

  //Exit
  return;
}
