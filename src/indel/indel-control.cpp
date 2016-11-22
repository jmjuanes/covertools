//Get the control coverage
void indel_control(CoverList & list_cover, CoverList & list_control, int n, int control)
{
  //Auxiliar pointers
  CoverList aux1 = list_cover, aux2 = NULL, end2 = NULL;

  //Initialize the control list
  list_control = NULL;

  //Read the full coverage list
  while(aux1 != NULL)
  {
    //Build the new coverage element
    aux2 = new Cover;

    //Add the chromosome
    aux2->chromosome = aux1->chromosome;

    //Add the position
    aux2->position = aux1->position;

    //Initialize the values array
    aux2->values = new float[1];

    //Check the control case
    if(control == -1)
    {
      //Sumatory counter
      float sum = 0;

      //Read all the coverage values
      for(int i = 0; i < n; i++)
      {
        //Increment the sum
        sum = sum + aux1->values[i];
      }

      //Calculate the mean
      aux2->values[0] = sum/n;
    }
    else
    {
      //Get the coverage of a column
      aux2->values[0] = aux1->values[control];
    }

    //Check the list
    if(list_control == NULL)
    {
      //Initialize the control list
      list_control = aux2;
    }
    else
    {
      //Add the next cover value
      end2->next = aux2;
    }

    //Update the end pointer
    end2 = aux2;

    //Next coverage value
    aux1 = aux1->next;
  }

  //Finish the list
  end2->next = NULL;

  //Exit
  return;
}
