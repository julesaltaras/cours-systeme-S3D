#include <stdio.h>
#include <stdlib.h>

int main(){
  double *mem = NULL;
  long total = 1;

  // Comme l'objectif de ce programme consiste à saturer le tas, la boucle est directe:
  while (1) {
    mem = malloc(sizeof(double));

    total ++; // Pour comptabiliser la mémoire utilisée.

    // Si on affiche à chaque tour, c'est vraiment trop long en général:
    if ( (total % 500) == 0 ) {
      printf("total=%ld \"double\" soit %ldMo (comparez avec top)\n", total, ((total*sizeof(double))/1000)/1000);
    }

    if (mem == NULL ) {
      printf("La fonction malloc n'arrive plus à trouver de mémoire dans le tas (heap).\n");
      exit(1);
    } else {
      *mem = 1.5; // Écriture dans la zone mémoire fraîchement allouée.
      // free(mem); // évidemment, si on active cette ligne, la boucle ne doit pas s'arrêter.
    }
  }
}
