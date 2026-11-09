#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Exemple de programme C capable de lancer une commande. */

int main(int argc, char **argv) {
  int status;
  char *commande;

  if (argc != 2) {
    printf("Usage: %s \"commandeEnUnSeulArgument\"\n", argv[0]);
    exit(1);
  }
  commande = argv[1];
  
  //status = system(commande);
  // Mettre un commentaire sur la ligne d'avant et enlever le commentaire
  // sur la ligne suivante (ou vice-versa):
  status = execlp("bash", "/bin/bash",  "-c", commande, NULL) ;

  printf("status = %d\n", WEXITSTATUS(status));
  printf("FIN.\n");
  return status;
}
