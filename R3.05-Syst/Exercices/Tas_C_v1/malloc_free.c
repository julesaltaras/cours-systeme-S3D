#include <stdio.h>
#include <stdlib.h>

int main() {
  char* pc1 = malloc(sizeof(char));
  char* pc2 = malloc(sizeof(char));
  int* pi1 = malloc(sizeof(int));
  int* pi2 = malloc(sizeof(int));
  
  printf("sizeof(char)=%zu, sizeof(int)=%zu, sizeof(double)=%zu\n", sizeof(char), sizeof(int), sizeof(double));
  
  printf("pc1=%p et pc2=%p distance = %zu\n", pc1, pc2, pc2 - pc1);
  
  printf("pi1=%p et pi2=%p distance = %zu\n", pi1, pi2, ((char*)pi2) - ((char*)pi1));
  
  // On redonne pi2:
  free(pi2);
  // On re-malloc pi2 et si le free marche, on retrouve la même adresse mémoire:
  pi2 = malloc(sizeof(int));
  printf("pi1=%p et pi2=%p distance = %zu\n", pi1, pi2, ((char*)pi2) - ((char*)pi1));
  
}
