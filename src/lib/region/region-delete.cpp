//Delete a region list
void regionDelete(RegionList & r)
{
  //Auxiliar pointers
  RegionList aux1 = r, aux2;

  //Read the full list
  while(aux1 != NULL)
  {
    //Get this region
    aux2 = aux1;

    //Next region
    aux1 = aux1->next;

    //Delete this region
    delete aux2;
  }

  //Delete the list
  r = NULL;

  //Exit
  return;
}
