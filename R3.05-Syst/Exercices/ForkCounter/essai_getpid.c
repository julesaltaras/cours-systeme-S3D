#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

  printf("Le pid du pere (bash en principe) = %d\n", getppid());
  printf("Le pid de essai_getpid = %d\n", getpid());
  exit(0);
}
