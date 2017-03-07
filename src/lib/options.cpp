//Check options
bool check_opt(string def_str, int def_size, string actual_str, int actual_size)
{
  //Check the size
  if(def_size != actual_size){ return false; }

  //Check the value
  if(def_str != actual_str){ return false; }

  //Default, return true
  return true;
}
