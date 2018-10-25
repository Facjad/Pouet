#include "base_elements.h"
#include <stdio.h>

int main(void){
  struct pool pool = { {}, pool.m }; // Trick to initialize the pool statically
  
  // Tester la file
  struct file_elem * file = init_file() ;
  struct cell* cell ;
  struct cell* cell2 ;
  char w[MAX_WORD_LENGTH] = "Youpi";
  if (file_vide(file)) {
    printf("Yeah\n") ;
  } else {
    printf("Nooo\n") ;
  }
    //  printf("NULL : %p, %p\n", (void*)file->content, (void*)file->next) ;
  cell = create_new_cell(&pool, w, 0, NULL) ;
  enfiler(&file, cell) ;
  if (file_vide(file)) {
    printf("Noo !\n") ;
  } else {
    printf("Yeah\n") ;
    printf("%s a %d occ\n", file->content->word, file->content->noccs) ;
  }
  //printf("Machins : %p, %p\n", (void*)file->content, (void*)file->next) ;
  cell2 = defiler(&file) ;
  if (file_vide(file)) {
    printf("Yeah\n") ;
  } else {
    printf("Nooo\n") ;
  }
  //printf("NULL : %p, %p\n", (void*)file->content, (void*)file->next) ; 
    
  return(0) ;
}
