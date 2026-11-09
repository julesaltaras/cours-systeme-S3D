#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main (int argc, char* argv[]) {
  int p = 0;
  int c = 0;
  while (1) {
    c++;
    p = fork();
    printf("pid=%d counter=%d\n",p,c);
  }
}

