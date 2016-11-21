//Save the list to file
void coverSave(string file, Chr l, int n)
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

  //Auxiliar pointer for chromosome
  Chr c = l;

  //Auxiliar pointer for position
  Pos p;

  //Tab character
  string tab = "\t";

  //Read all the chromosomes
  while(c != NULL)
  {
    //Initialize the positions pointer
    p = c->positions;

    //Read all the positions
    while(p != NULL)
    {
      //Save to file
      output << c->name << tab << p->pos << tab;

      //Save all the covers
      for(int i = 0; i < n; i++)
      {
        //Check the index
        if(i > 0){ output << tab; }

        //Save the cover for the file i
        output << p->cover[i];
      }

      //End the line
      output << endl;

      //Next
      p = p->next;
    }

    //Next chromosome
    c = c->next;
  }

  //Close the output file
  output.close();
}
