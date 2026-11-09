#include <stdio.h>
#include <stdlib.h>
/* Essai de commentaires dans le programme lui même... */
// Simple
/* Sur deux 
   lignes
*/
/* Souvent on ferme avec: **/
// /* c'est possible.


int main (int argc, char*argv[]) {
  int state; char caractereCourant = 'a'; FILE* file;
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <fichier C (ou java)>\n", argv[0]);
    exit(1);
  }
  file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "%s: Cannot read \"%s\" file.\n", argv[0], argv[1]);
    exit(2);
  }
  
  /* Liste des états: */
  // A compléter par vos soins:
#define S_DEPART 			0
#define S_APRES_SLASH	 		1
#define S_APRES_SLASH_ETOILE	 	2
#define S_APRES_SLASH_ETOILE_ETOILE	3
#define S_APRES_2_SLASH		 	4
  // ...
  // ...
  // ...
  // Celui de fin :
#define S_FINI	 		        1000
#define S_ERREUR 	       	        1001
  
  state = S_DEPART;
  // La seule boucle de l'automate:
  while ( state < S_FINI ) {
    /*
      La seule instruction de lecture est ici:
    */
    caractereCourant = getc(file);
    switch (state) {
    case S_DEPART: // ------------------------------------------------
      switch ( caractereCourant ) {
      case '/':
	state = S_APRES_SLASH;
	break;
      case EOF:
	state = S_FINI;
	break;
      default:
	;
      }
      break;
    }
  // ...
  // ...
  // ...
  // ...
  // ...
  // ...

  }

  fclose(file);

  if ( state == S_ERREUR ) {
    fprintf(stderr, "%s: Error while searching comments in \"%s\" file.\n", argv[0], argv[1]);
    return 1;
  }
  else {
    return 0;
  }
}
