#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char* argv[]) {
  int pid = -1;

  printf("Normal pour l'instant...\n");
  pid = fork();
  if ( pid > 0 ) {
    printf("Papa. Variable pid = %d\n", pid);
  }
  else {
    printf("Fiston. Variable pid = %d\n", pid);
  }
  printf("Bizarre!\n");
  return 0;
}

