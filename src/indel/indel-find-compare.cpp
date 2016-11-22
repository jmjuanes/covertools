//Compare two coverage values
void indel_find_compare(CoverList list_cover, CoverList list_control, int index, RegionList & start, RegionList & end, float min_cover, float min_region, float threshold)
{
  //Coverage pointers
  CoverList aux_cover = list_cover, aux_control = list_control;

  //Regions pointers
  RegionList aux = NULL;

  //Read all the coverage positions
  while(aux_cover != NULL)
  {
    //Check if is a valid region
    bool is_valid = indel_find_valid(aux_cover->values[index], aux_control->values[0], min_cover, threshold);

    //Check the conditions
    if(is_valid == false)
    {
      //Next coverage list position
      aux_cover = aux_cover->next;

      //Next control list position
      aux_control = aux_control->next;

      //Continue
      continue;
    }

    //Initialize the new region
    aux = new Region;

    //Add the region chromosome
    aux->chromosome = aux_cover->chromosome;

    //Add the region start position
    aux->start = aux_cover->position;

    //Add the region name
    aux->name = "";

    //Initialize the next position
    aux->next = NULL;

    //Loop
    do
    {
      //Save the last position
      aux->end = aux_cover->position;

      //Next coverage list position
      aux_cover = aux_cover->next;

      //Next control list position
      aux_control = aux_control->next;

      //Check the chromosome
      if(aux_cover->chromosome != aux->chromosome){ break; }

      //Check the position
      if(aux->end + 1 < aux_cover->position){ break; }

      //Check if is a valid region
      is_valid = indel_find_valid(aux_cover->values[index], aux_control->values[0], min_cover, threshold);
    }
    while(is_valid == true && aux_cover->next != NULL);

    //Calculate the region length
    aux->length = abs(aux->end - aux->start) + 1;

    //Check the length
    if(aux->length > 1 && min_region <= aux->length)
    {
      //Check for empty region start
      if(start == NULL)
      {
        //Initialize the start element
        start = aux;
      }
      else
      {
        //Add the new region to the list
        end->next = aux;
      }

      //Save the last element
      end = aux;
    }

    //Next coverage list position
    aux_cover = aux_cover->next;

    //Next control list position
    aux_control = aux_control->next;
  }

  //Exit
  return;
}
