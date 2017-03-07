//Collapse a regions list
void region_collapse(Regions & r)
{
  //Initialize the new regions list
  Regions collapsed = NULL, aux1, aux2, aux3, last = NULL;

  //Initialize the regions
  aux1 = r;

  //Read all the regions
  while(aux1 != NULL)
  {
    //Initialize the collapsed list
    aux2 = collapsed;

    //Save the actual region
    aux3 = aux1;

    //Initialize the inserted boolean
    bool inserted = false;

    //Read all the regions
    while(aux2 != NULL)
    {
      //Check the chromosome
      if(aux1->chromosome != aux2->chromosome){ aux2 = aux2->next; continue; }

      //First condition
      if(aux1->end < aux2->start){ aux2 = aux2->next; continue; }

      //Second condition
      if(aux2->end < aux1->start){ aux2 = aux2->next; continue; }

      //Update the start position
      aux2->start = (aux2->start < aux1->start) ? aux2->start : aux1->start;

      //Update the end position
      aux2->end = (aux2->end < aux1->end) ? aux1->end : aux2->end;

      //Next region
      aux1 = aux1-> next;

      //Delete this region
      delete aux3;

      //Set inserted
      inserted = true;

      //Exit this loop
      break;
    }

    //Check for inserted
    if(inserted == true){ continue; }

    //Check for empty collapsed list
    if(aux2 == NULL)
    {
      //Initialize the collapsed list
      collapsed = aux1;
    }
    else
    {
      //Add this region
      last->next = aux1;
    }

    //Save this as the last region
    last = aux1;

    //Next region
    aux1 = aux1->next;

    //Finish the list
    last->next = NULL;
  }

  //Update the region list
  r = collapsed;

  //Exit
  return;
}
