#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int lance_la_commande (char *commande) {
  int pid = fork();
  if ( pid == 0 ) {
    system(commande);
  } else {
    waitpid(pid, NULL, 0); // Essayer avec ou sans.
    printf("commande %s\n", commande);
    fflush(stdout);
  }
  return pid;
}

int main (int argc, char* argv[]) {
  int pid1 = lance_la_commande("emacs Toto-11111111111.TXT 2>/dev/null"); // 1
  int pid2 = lance_la_commande("emacs Toto-22222222222.TXT 2>/dev/null"); // 2
  int pid3 = lance_la_commande("emacs Toto-33333333333.TXT 2>/dev/null"); // 3
  printf("pid1=%d pid2=%d pid3=%d\n", pid1, pid2, pid3);    
}

