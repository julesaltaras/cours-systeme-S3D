#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  gcc -g -o essai_variables essai_variables.c
  ./essai_variables
  ddd ./essai_variables
*/

int main (int argc, char *argv[], char **environ) {
  int i ;
  printf("Arguments:\n") ;
  for (i = 0 ; i < argc ; i++) {
    printf("%d : %s \n", i, argv[i]) ;
  }

  printf("Variables d'environnement:\n") ;
  for (i = 0 ; environ[i] != NULL ; i++) {
    if ( (i < 3) || (strncmp(environ[i], "PATH=", 5) == 0) ) {
      printf("%d : %s \n", i, environ[i]) ;
    }
  }

  printf("Variable PATH:\n%s\n", getenv("PATH")) ;

  exit(0);
}
    
