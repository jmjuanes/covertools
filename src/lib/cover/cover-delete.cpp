//Delete a cover structure
void cover_delete(CoverList & l)
{
  //Auxiliar pointers
  CoverList aux1 = l, aux2;

  //Read all the coverage values
  while(aux1 != NULL)
  {
    //Save this coverage value
    aux2 = aux1;

    //Next coverage value
    aux1 = aux1->next;

    //Delete this coverage value
    delete aux2;
  }

  //Delete the list
  l = NULL;

  //Exit
  return;
}
