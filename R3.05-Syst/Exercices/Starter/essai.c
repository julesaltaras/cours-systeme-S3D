#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  Juste pour faire un essai de C sans retaper du code.

  -DNDEBUG
*/

int main (int argc, char* argv[]) {
  int i = 0;
  int j = 5;

  assert(j == 5);
  i = i + j;
  printf("Pour executer sous le debogueur\n"
	 "Recompiler avec\n" 
	 "   gcc -Wall -g3 -o essai essai.c\n"
	 "Puis executer avec\n"
	 "   ddd ./essai\n"
	 "ou bien\n"
	 "   gdb ./essai\n"
	 );

  while ( i ) {
    i = i - 1;
  }

  printf("Fin...\n");
  exit (0);
}

