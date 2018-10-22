#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS   4000
#define MAX_CELLS       20000

struct cell {
  char word[MAX_WORD_LENGTH+1];  // a char array for words of length MAX_WORD_LENGTH
  int  noccs;                    // an integer for counting occurrences
  struct cell* next;             // a (possibly NULL) pointer to the following cell
};

struct pool {
  struct cell m[MAX_CELLS];      // an array of memory cells
  struct cell* next_free;        // a pointer to the first free cell
};

struct file_elem {
  struct cell* content ;
  struct file_elem* next ;
};

struct cell* create_new_cell(struct pool *pool, char word[], int noccs, struct cell* next) ;
struct file_elem* init_file() ;
bool file_vide(struct file_elem* file) ;
struct file_elem* enfiler(struct file_elem* file, struct cell* elem) ;
struct cell* defiler(struct file_elem** file) ;

#endif
