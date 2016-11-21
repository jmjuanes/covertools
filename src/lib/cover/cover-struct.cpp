//Max number of bam files
const int _MAX_BAMS = 100;

//Initialize the structures
struct Position;
struct Chromosome;

//Initialize the typedefs
typedef Chromosome * Chr;
typedef Position * Pos;

//Define the structure for chromosomes
struct Chromosome
{
  //Chromosome name
  string name;

  //Positions sublist
  Pos positions = NULL;

  //Next chromosome
  Chr next = NULL;
};

//Define the structure for positions
struct Position
{
  //Position
  int pos;

  //Array with all the coverages
  float * cover;

  //Next position pointer
  Pos next = NULL;
};
