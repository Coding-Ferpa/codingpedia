#include "omp.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
  int nthreads, tid;

  omp_set_num_threads(8);
  /* Dispara threads com suas cópias das variáveis */
  #pragma omp parallel private (nthreads, tid)
  { /* Descobre seu ID */
    tid = omp_get_thread_num();
    printf("Hello World from thread = %d\n", tid);
    /* Só o thread principal (mestre) faz isso */
    #pragma omp master 
    {
      nthreads = omp_get_num_threads();
      printf("Number of threads = %d\n", nthreads);
    }
  } /* Todos os threads se juntam ao thread principal e “somem” */
}
