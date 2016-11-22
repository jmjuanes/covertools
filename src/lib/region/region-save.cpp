//Save a region list to a file
void regionSave(string file, RegionList list)
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
  RegionList aux = list;

  //Tab character
  string tab = "\t";

  //Read all the regions
  while(aux != NULL)
  {
    //Add the values
    output << aux->chromosome << tab << aux->start << tab << aux->end << tab << aux->name << endl;

    //Next region
    aux = aux->next;
  }

  //Close the output file
  output.close();

  //Exit
  return;
}
