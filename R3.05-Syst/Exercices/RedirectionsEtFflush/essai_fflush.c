#include <stdio.h>

int main(int argc,char*argv[]){
  int compteur = 40;

  while ( compteur-- ) {
    fprintf(stdout, "1");
    fprintf(stderr, "2");
  }
  printf("\n");
}


