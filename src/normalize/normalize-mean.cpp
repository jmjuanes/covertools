//Use the mean algorithm to normalize the coverage matrix
void normalize_mean(CoverList l, int num)
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
void normalize_mean_calculate(CoverList l, double mean[], int n)
{
  //Auxiliar cover list pointer
  CoverList aux = l;

  //Total count
  int total = 0;

  //Initialize the mean values
  for(int i = 0; i < n; i++){ mean[i] = 0; }

  //Read the full list
  while(aux != NULL)
  {
    //Get all the coverage values
    for(int i = 0; i < n; i++)
    {
      //Increment the mean
      mean[i] = mean[i] + aux->values[i];
    }

    //Next cover position
    aux = aux->next;

    //Increment the counter
    total = total + 1;
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
void normalize_mean_apply(CoverList & l, double mean[], int n)
{
  //Auxiliar coverage list pointer
  CoverList aux = l;

  //Read the full list
  while(aux != NULL)
  {
    //Update the coverage values
    for(int i = 0; i < n; i++)
    {
      //Increment the mean
      aux->values[i] = float (aux->values[i] / mean[i]);
    }

    //Next coverage element
    aux = aux->next;
  }

  //Exit
  return;
}
