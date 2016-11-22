//Find the in-del regions
void indel_find(CoverList list_cover, CoverList list_control, RegionList & list_regions, int n, int control, float min_cover, float min_region, float threshold)
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
