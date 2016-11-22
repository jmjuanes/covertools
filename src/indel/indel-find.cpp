//Calculate the differences and return if is a valid region
bool indel_find_valid(float value1, float value2, float min, float threshold)
{
  //Calculate the first difference
  float diff1 = (value2 != 0) ? value1 / value2 : 1;

  //Calculate the second difference
  float diff2 = (value1 != 0) ? value2 / value1 : 1;

  //Check the first difference
  if(min <= value1 && diff1 == 1){ diff1 = value1; }

  //Check the second difference
  if(min <= value2 && diff2 == 1){ diff2 = value2; }

  //Check the first condition
  bool condition1 = (threshold <= diff1 || threshold <= diff2) ? true : false;

  //Get the second condition value
  bool condition2 = (min <= value1 || min <= value2) ? true : false;

  //Check the conditions
  if(condition1 == false || condition2 == false)
  {
    //Return false
    return false;
  }

  //Default, return true
  return true;
}

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
      if(aux->position + 1 < aux_cover->position){ break; }

      //Check if is a valid region
      is_valid = indel_find_valid(aux_cover->values[index], aux_control->values[0], min, threshold);
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

//Find the in-del regions
void indel_find(CoverList list_cover, CoverList list_control, RegionList & list_regions, int control, int n, float min_cover, float min_region, float threshold)
{
  //Initialize the regions list
  list_regions = NULL;

  //Regions pointers
  RegionList end = NULL, region_start = NULL, region_end = NULL;

  //Read all the coverage columns
  for(int i = 0; i < n; i++)
  {
    //Check the control value
    if(i == control){ continue; }

    //Reset the region start pointer
    region_start = NULL;

    //Reset the region end pointer
    region_end = NULL;

    //Compare the control with a column
    indel_find_compare(list_cover, list_control, i, region_start, region_end, min_cover, min_region, threshold);

    //Check the start region
    if(region_start == NULL){ continue; }

    //Check the regions list
    if(list_regions == NULL)
    {
      //Initialize the regions list
      list_regions = region_start;
    }
    else
    {
      //Update the end
      end->next = region_start;
    }

    //Save the end
    end = region_end;
  }

  //Finish the list
  end->next = NULL;

  //Exit
  return;
}
