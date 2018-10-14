#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

// Global seed for the random number generator
int seed = 0;

////////////////////////////////////////////////////////////////
// Function for parsing the options of the program
// Currently available options are :
// -s <seed> : sets the seed
void parse_opts(int argc, char* argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "s:")) != -1) {
    switch (opt) {
    case 's':
      seed = atoi(optarg);
      break;
    default: /* '?' */
      fprintf(stderr, "Usage: %s [-s seed] \n",
	      argv[0]);
      exit(EXIT_FAILURE);
    }
  }
}

////////////////////////////////////////////////////////////////
int main(int argc,  char* argv[]) {
  parse_opts(argc, argv);
  printf("Seed : %d\n", seed);
  return EXIT_SUCCESS;
}
