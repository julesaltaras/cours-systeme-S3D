#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LOOP 500000

void auBoulotMonBonCPU (void) {
  int tempo = MAX_LOOP ;
  double d = 3.14;
  while (tempo > 0) {
    tempo = tempo - 1;
    d = d * 2.34;
  }
}

int main (int argc, char* argv[]) {
  int pid = -1;
  int loop_counter = 80;
  printf("Normal...\n");
  if ( (pid = fork()) ) {
    while ( loop_counter > 0 ) {
      loop_counter --;
      fputc('P', stdout); // P comme Papa
      fflush(stdout);
      auBoulotMonBonCPU();
    }
  }
  else {
    while ( loop_counter > 0 ) {
      loop_counter --;
      fputc('F', stdout); // F comme Fiston
      fflush(stdout);      
      auBoulotMonBonCPU();
    }
  }
  if (pid) {
    printf("\nBizarre PPPP...");
  }
  else {
    printf("\nEtrange FFFF...");
  }
  return 0;
}
