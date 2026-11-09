#include <stdio.h>

int main(int argc,char*argv[]){
  int caractereCourant;

  caractereCourant = fgetc(stdin);
  while ( caractereCourant != EOF ) {
    fputc(caractereCourant, stdout);
    fflush(stdout);
    fputc(caractereCourant, stderr);
    fflush(stderr);
    caractereCourant = fgetc(stdin);
  }
}


