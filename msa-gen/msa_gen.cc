#include <stdio.h>
#include <cstdlib>
#include <time.h>



// Input: <number of sequences> <average length> <diversity of the length>
// Output: Sequences in tfa format.
int main(int argc, char* argv[]) {
  char pamcode[24] = { 'A', 'R', 'N', 'D', 'C', 'Q', 'E', 
		       'G', 'H', 'I', 'L', 'K', 'M', 'F', 
		       'P', 'S', 'T', 'W', 'Y', 'V', 'B', 
		       'J', 'Z', 'X'};
  srand(time(NULL));
  unsigned int number_of_sequences;
  FILE* outfile;
  char filename[30];

  int inst_num = 1;
  if (argc > 1 && sscanf(argv[1], "%d", &inst_num) != 1) {
  }
  printf("%d instances\n", inst_num);

  for (int inst = 0; inst < inst_num; ++inst) {
    int av_length = 80;
    int div = 10;
    if(argc > 2 && sscanf(argv[2], "%u", &number_of_sequences) == 1) {
    }
    if (argc > 3 && sscanf(argv[3], "%d", &av_length) != 1) {
    }
    if (argc > 4 && sscanf(argv[4], "%d", &div) != 1) {
    }

    sprintf(filename, "%d_%d", number_of_sequences, inst);
    outfile = fopen(filename, "w");
        
    for (int seq = 0; seq < number_of_sequences; ++ seq) {
      int length = av_length - div + rand() % (div * 2);
      fprintf(outfile, ">seq%d\n", seq);
      for (int i = 0; i < length; ++i) {
	fprintf(outfile, "%c", pamcode[rand() % 24]);
      }
      fprintf(outfile, "\n");
    }
    fclose(outfile);
  }
}
