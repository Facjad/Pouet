#include "singes.h"

#include<stdio.h>
#include"base_elements.h"

void lecteur(struct pool *pool, FILE *fichier, struct file_elem **file) {
  static unsigned int nb_mots_lus = 0 ;
  char mot[MAX_WORD_LENGTH];
  /* assumes no word exceeds length of 1023 */
  if (fscanf(fichier, " %20s", mot) == 1) {
    // Créer nouvelle cellule et l'enfiler
    struct cell *cellule ;
    cellule = create_new_cell(pool, mot, 0, NULL) ;
    *file = enfiler(*file, cellule) ;
    nb_mots_lus++ ;
  }
}

void imprimeur(struct file_elem **file) {
  
}
