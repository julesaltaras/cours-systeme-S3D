#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIGNE 1024 // Taille maxi pour une ligne de commande
#define MAX_COMMANDES 50 // Nombre maxi de commandes

int main (int argc, char*argv[]) {
  int nb_processus_max;
  int nb_commandes = 0;
  char **tableau_commandes = calloc(MAX_COMMANDES, sizeof(char*));

  if ( argc != 3 ) {
    fprintf(stderr, "Usage: %s nb_processus_max <fichier.make>\n", argv[0]);
    exit(2);
  }
  
  {
    // ---- BLOC 1 ----
    // Le but de ce bloc consiste a preparer "nb_commandes" et "tableau_commandes".
    // Il n'est necessaire de lire tous les details de ce bloc.
    // Aller directement au BLOC 2

    FILE* file = fopen(argv[2], "r");
    if (file == NULL) {
      fprintf(stderr, "%s: Cannot read \"%s\" file.\n", argv[0], argv[2]);
      exit(2);
    }
    { 
      char* ligne = malloc(MAX_LIGNE);
      int ligne_idx = 0;
      char c = getc(file);
      while ( c != EOF ) {
	if (c == '\n') {
	  ligne[ligne_idx] = '\0'; 
	  tableau_commandes[nb_commandes++] = ligne;
	  ligne = malloc(MAX_LIGNE);
	  ligne_idx = 0;
	}
	else {
	  ligne[ligne_idx++] = c; 
	}
	c = getc(file);
      }
    }
    fclose(file);
  }
  printf("%d commandes dans \"%s\".\n", nb_commandes, argv[2]);

  nb_processus_max = atoi(argv[1]);
  if ( nb_processus_max > (nb_commandes - 1) ) {
    // Reduction automatique du nombre de processus:
    nb_processus_max = nb_commandes - 1;
  }

  {
    // ---- BLOC 2 ----
    // Ici commence la partie vraiment interessante:
    int commande_index = 0;
    char* commande = NULL;
    int nb_processus_fils = 0;
    
    printf("Phase 1: on fait monter la charge (pas de wait):\n");
    while ( nb_processus_fils < nb_processus_max ) {
      commande = tableau_commandes[commande_index++];
      if ( fork() == 0 ) {
	printf("Lancement de \"%s\"\n", commande);
	system(commande);
	printf("Fini \"%s\"\n", commande);	
	exit(0);
      }
      nb_processus_fils++;
    }
    
    printf("Phase 2: on remplace avec des processus frais:\n");
    while ( commande_index < (nb_commandes - 1) ) {
      wait(NULL);
      commande = tableau_commandes[commande_index++];
      if ( fork() == 0 ) {
	printf("Lancement de \"%s\"\n", commande);
	system(commande);
	printf("Fini \"%s\"\n", commande);	
	exit(0);
      }
    }

    // A vous de continuer le travail à partir d'ici !
    // Il faut environ 8 a 10 lignes de C.
    // ...
    // ...
    // ...
    // ...
    // ...
  
  }
  printf("Script \"%s\" fait.\n", argv[2]);
  exit(1);
}
