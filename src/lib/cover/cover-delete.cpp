//Delete a cover structure
void coverDelete(Chr & l)
{
  //Auxiliar pointer for chromosome
  Chr c1 = l, c2;

  //Auxiliar pointers for positions
  Pos p1, p2;

  //Tab character
  string tab = "\t";

  //Read all the chromosomes
  while(c1 != NULL)
  {
    //Initialize the positions pointer
    p1 = c1->positions;

    //Read all the positions
    while(p1 != NULL)
    {
      //Get the actual position
      p2 = p1;

      //Save the next position
      p1 = p1->next;

      //Delete this position
      delete p2;
    }

    //Save this chromosome
    c2 = c1;

    //Next chromosome
    c1 = c1->next;

    //Delete this chromosome
    delete c2;
  }
}
