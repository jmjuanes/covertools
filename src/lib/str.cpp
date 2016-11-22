//Covert a string to lower case
string strLower(string str)
{
  //Get the string length
  int str_length = (int) strlen(str);

  //Read all the characters
  for(int i = 0; i < str_length; i++)
  {
    //Convert the character to lower case
    str[i] = tolower(str[i]);
  }
  //Return the string in lower case
  return str;
}

//Lower case alias
string strLowerCase(string str)
{
  //Return the string in lower case
  return strLower(str);
}

//Convert a string to upper case
string strUpper(string str)
{
  //Get the string length
  int str_length = (int) strlen(str);

  //Read all the characters
  for(int i = 0; i < str_length; i++)
  {
    //Convert the character to upper case
    str[i] = toupper(str[i]);
  }
  //Return the string in upper case
  return str;
}

//Upper case alias
string strUpperCase(string str)
{
  //Return the string in upper case
  return strUpper(str);
}

//Convert a string to array
int strSplit(string str, string arr[], int tam, string sep)
{
  //Aux vars
  int pos = 0, counter = 0;

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
