#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main (int argc, char* argv[]) {
  int pid = -1;
  printf("Normal pour l'instant...\n");
  pid = fork();
  if ( pid > 0 ) {
    printf("Papa. Variable pid = %d\n", pid);
    exit(0);
  }
  else {
    printf("Fiston. Variable pid = %d\n", pid);
    exit(1);
  }
  printf("Bizarre de ne plus voir cette affichage ?\n");
  return 0;
}
// if ./prog2 >/dev/null ; then echo hip ; else echo hop ; fi
