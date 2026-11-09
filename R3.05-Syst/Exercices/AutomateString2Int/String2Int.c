#include <stdio.h>
#include <stdlib.h>

int main (int argc, char*argv[]) {
  char *input=NULL;
  int state;
  int caractereCourant;
  int iCourant = 0;

  int value = 0;
  int signe = 1;

  if (argc <= 1) {
    fprintf(stderr, "Usage: %s <EntierAvecOuSansSigne>\n", argv[0]);
    exit(2);
  }
  
  input = argv[1];

  /* Various state possibilities: */
#define S_DEPART		0
#define S_APRES_SIGNE		1
#define S_DANS_NOMBRE 		2
#define S_APRES_NOMBRE 		3
  // We always need those too:
#define S_FINI	 		4
#define S_ERREUR 	       	5

  state = S_DEPART;
  while ( state < S_FINI ) {

    // Getting the current one:
    caractereCourant = input[iCourant];
    // Moving to the next:
    iCourant++;

    switch (state) {
    case S_DEPART: // ----------------------------
      switch ( caractereCourant ) {
      case ' ':
	break;
      case '+':
      case '-':
	state = S_APRES_SIGNE;
	break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
	state = S_DANS_NOMBRE;
	break;
      default:
	state = S_ERREUR;
      }
      break;
    case S_APRES_SIGNE: // -----------------------
      switch ( caractereCourant ) {
      case ' ':
	break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
	state = S_DANS_NOMBRE;
	break;
      default:
	state = S_ERREUR;
	break;
      }
      break; 
    case S_DANS_NOMBRE: // -----------------------
      switch ( caractereCourant ) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
	break;
      case '\0':
	state = S_FINI;
	break;
      case ' ':
	state = S_APRES_NOMBRE;
	break;
      default:
	state = S_ERREUR;
      }
      break; 
    case S_APRES_NOMBRE: // ----------------------
      switch ( caractereCourant ) {
      case ' ':
	break;
      case '\0':
	state = S_FINI;
	break;
      default:
	state = S_ERREUR;
      }
      break; 
    }
  }

  if ( state == S_ERREUR) {
    fprintf(stderr, "%s: Ecriture incorrecte: \"%s\".\n", argv[0], argv[1]);
    exit(2);
  }

  if ( state == S_FINI) {
    fprintf(stdout, "Ecriture correcte. Value = %d\n", value);
  }
  return 0;
}
