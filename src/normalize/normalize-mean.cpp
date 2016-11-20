//Use the mean algorithm to normalize the coverage matrix
void normalize_mean(Chr l, int num)
{
  //Initialize the cover mean
  double * mean = new double[num];

  //Calculate the mean
  normalize_mean_calculate(l, mean, num);

  //Apply the mean
  normalize_mean_apply(l, mean, num);

  //Delete the mean array
  delete[] mean;

  //Exit
  return;
}

//Calculate the mean of a cover list
void normalize_mean_calculate(Chr l, double mean[], int n)
{
  //Chromosome pointer
  Chr c = l;

  //Positions pointer
  Pos p = NULL;

  //Total count
  int total = 0;

  //Initialize the mean values
  for(int i = 0; i < n; i++){ mean[i] = 0; }

  //Read the full list
  while(c != NULL)
  {
    //Get the position
    p = c->positions;

    //Read all the positions
    while(p != NULL)
    {
      //Get all the coverage values
      for(int i = 0; i < n; i++)
      {
        //Increment the mean
        mean[i] = mean[i] + p->cover[i];
      }

      //Next position
      p = p->next;

      //Increment the counter
      total = total + 1;
    }

    //Next chromosome
    c = c->next;
  }

  //Calculate the mean
  for(int i = 0; i < n; i++)
  {
    //Calculate the mean of the column i
    mean[i] = mean[i]/total;
  }

  //Exit
  return;
}

//Apply the mean for each value
void normalize_mean_apply(Chr & l, double mean[], int n)
{
  //Chromosome pointer
  Chr c = l;

  //Positions pointer
  Pos p = NULL;

  //Read the full list
  while(c != NULL)
  {
    //Get the position
    p = c->positions;

    //Read all the positions
    while(p != NULL)
    {
      //Calculate the new cover values
      for(int i = 0; i < n; i++)
      {
        //Increment the mean
        p->cover[i] = float (p->cover[i] / mean[i]);
      }

      //Next position
      p = p->next;
    }

    //Next chromosome
    c = c->next;
  }

  //Exit
  return;
}
