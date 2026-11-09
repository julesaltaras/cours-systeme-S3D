#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define TAILLE 1000000
// double tg[TAILLE] ; // Une grosse variable globale (donc statique)
int main() 
{
  printf("Surveillez ce programme depuis un autre terminal avec :\n\twatch -n 0.1 pmap %d\n\t(ou  watch -n 0,1 pmap %d pour les systèmes en français)\n", (int)getpid(),(int)getpid());
  
  // double tl[TAILLE] ; // Une grosse variable locale dans la pile (donc automatique)
  double *pd = NULL ;
  printf("Allocation de %ld Ko (Kilo octets)\n", TAILLE * sizeof(double) / 1000);
  getchar();
  pd =  malloc(sizeof(double) * TAILLE); // une grosse allocation dynamique (dans le tas)
  printf("Appel de free.\n");
  getchar();
  free(pd);
  printf("Fin\n");
  getchar();
  return 0 ;
}
