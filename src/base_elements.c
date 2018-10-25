#include "base_elements.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Given a pool, and the constituents of a cell,
// return a pointer to a valid cell with the same constituents,
// or NULL if all the memory has been allocated.
struct cell* create_new_cell(struct pool *pool,
			     char word[], int noccs,
			     struct cell* next) {
  if(pool->next_free - pool->m >= MAX_CELLS)
    return NULL;
  struct cell* res = pool->next_free;
  strncpy(res->word, word, MAX_WORD_LENGTH+1); // Always take the null-terminator into account
  res->noccs = noccs;
  res->next = next;
  pool->next_free++;
  return res;
}

struct file_elem* init_file() {
  return NULL ;
}

bool file_vide(struct file_elem* file) {
  if (file == NULL) {
    return true ;
  } else {
    return false ;
  }
}

// modifie l'adresse de la file
void enfiler(struct file_elem** file, struct cell* elem) {
  struct file_elem* nouv = malloc(sizeof(struct file_elem)) ;
  nouv->content = elem ;
  nouv->next = *file ;
  *file = nouv ;
}

// retourne l'adresse de la cellule que l'on vient d'enlever
// renvoie NULL si déjà vide
struct cell* defiler(struct file_elem** file) {
  struct file_elem* la_file = *file ;
  struct file_elem* pred = NULL ;
  if (la_file == NULL) {
    return NULL ;
  }
  while (la_file->next != NULL) {
    pred = la_file ;
    la_file = la_file->next ;
  }
  if (pred == NULL) {
    *file = NULL ;
    return la_file->content ;
  } else {
    pred->next = la_file ;
    return la_file->content ;
  }
}
