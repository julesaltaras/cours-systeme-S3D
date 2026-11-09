#include <stdio.h>

void stack_max (int compteur, int *baseDeLaPile) {
  int distance;

  distance = &distance - baseDeLaPile;
  
  if (distance < 0) {
    distance = baseDeLaPile - &distance;
  } 

  printf("compteur = %d\tdistance = %d\n", compteur, distance);
  stack_max(compteur + 1, baseDeLaPile);
}


int main (int argc, char* argv[]) {
  int baseDeLaPile;
  stack_max(1, &baseDeLaPile);
  return 0;
}
