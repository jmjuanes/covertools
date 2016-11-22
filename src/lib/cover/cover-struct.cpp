//Max number of bam files
const int _MAX_BAMS = 150;

//Initialize the structures
struct Cover;

//Initialize the typedefs
typedef Cover * CoverList;

//Define the structure for coverages
struct Cover
{
  //Chromosome
  string chromosome;
  
  //Position
  int position;

  //Array with all the coverages
  float * values;

  //Next coverage pointer
  CoverList next = NULL;
};
