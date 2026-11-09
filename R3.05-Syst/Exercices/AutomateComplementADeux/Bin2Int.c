#include <stdio.h>
#include <stdlib.h>
int main (int argc, char*argv[]) {
  char *input=NULL;
  int state;
  int caractereCourant;
  int iCourant = 0;
  int valeur = 0;
  if (argc <= 1) {
    fprintf(stderr, "Usage: %s <ChaineBinaire>\n", argv[0]);
    exit(2);
  }
  input = argv[1];
#define S_DEPART  0
#define S_BIT_1   1
#define S_BIT_0   2
#define S_FINI    3
#define S_ERREUR  4
  state = S_DEPART;
  while ( state < S_FINI ) {
    caractereCourant = input[iCourant];
    iCourant++;
    switch (state) {
    case S_DEPART: // ----------------------------
      switch ( caractereCourant ) {
      case '0':
        state = S_BIT_0;
        break;
      case '1':
        state = S_BIT_1;
        break;
      default:
        state = S_ERREUR;
      }
      break;
    case S_BIT_1: // -----------------------
      switch ( caractereCourant ) {
      case '0':
        state = S_BIT_0;
        break;
      case '1':
        break;
      case '\0': // Fin de chaîne
        state = S_FINI;
        break;
      default:
        state = S_ERREUR;
        break;
      }
      break; 
    case S_BIT_0: // -----------------------
      switch ( caractereCourant ) {
      case '0':
        break;
      case '1':
        state = S_BIT_1;
        break;
      case '\0': // Fin de chaîne
        state = S_FINI;
        break;
      default:
        state = S_ERREUR;
      }
      break; 
    }
  }
  if ( state == S_ERREUR) {
    fprintf(stderr, "%s: Pas du binaire: \"%s\".\n", argv[0], argv[1]);
    exit(2);
  }
  if ( state == S_FINI) {
    fprintf(stdout, "Valeur = %d\n", valeur);
  }
  return 0;
}
