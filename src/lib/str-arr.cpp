//Convert a string to an array
//Inputs:
// str: string to split
// arr: array to save the string
// tam: array size
// sep: character to use for splitting the string

int strArr(string str, string arr[], int tam, string sep)
{
  //Aux vars
  int pos = 0;

  //Counter
  int counter = 0;

  //Read all
  while(counter < tam)
  {
    //Find the next tab
    pos = str.find(sep);

    //Check for undefined position
    if(pos == string::npos)
    {
      //Save the last
      arr[counter] = str;

      //Increment the counter
      counter = counter + 1;

      //Exit loop
      break;
    }

    //Get the substring
    arr[counter] = str.substr(0, pos);

    //Cut the string
    str = str.substr(pos + 1);

    //Increment the counter
    counter = counter + 1;
  }

  //Return the counter
  return counter;
}
