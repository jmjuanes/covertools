//Print a region list in console
void region_print(RegionList list)
{
  //Auxiliar pointer
  RegionList aux = list;

  //Tab character
  string tab = "\t";

  //Read all the regions
  while(aux != NULL)
  {
    //Add the values
    cout << aux->chromosome << tab << aux->start << tab << aux->end;

    //Check the region name
    if(aux->name != "")
    {
      //Add the region name
      cout << tab << aux->name;
    }

    //end this line
    cout << endl;

    //Next region
    aux = aux->next;
  }

  //Close the output file
  output.close();

  //Exit
  return;
}
