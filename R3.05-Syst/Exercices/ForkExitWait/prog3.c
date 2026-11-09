#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main (int argc, char* argv[]) {
  int pid = -1;
  printf("Normal pour l'instant...\n");
  pid = fork();
  if ( pid > 0 ) {
    int status = 0;
    waitpid(pid, &status, 0);
    printf("Papa. status = %d\n", WEXITSTATUS(status));
    exit(0);
  }
  else {
    printf("Fiston. Variable pid = %d\n", pid);
    exit(4);
  }
  printf("Bizarre!\n");
  return 0;
}

