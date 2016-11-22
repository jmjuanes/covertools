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
