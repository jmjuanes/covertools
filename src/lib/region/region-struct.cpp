//Define the region structure
struct Region;

//Define the new regions list
typedef Region * RegionList;

//Region structure
struct Region
{
  //Region start, end, length and strand
  int start, end, length, strand;

  //Region name and chromosome
  string chromosome, name;

  //Next region
  RegionList next = NULL;
};
