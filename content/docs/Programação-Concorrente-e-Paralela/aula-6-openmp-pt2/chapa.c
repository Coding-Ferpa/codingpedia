#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define cols 200
#define totrows 200
#define maxtime 180000

int main(int argc, char* argv[ ]) {
  double red[totrows+2][cols+2], black[totrows+2][cols+2];
  int r, c, tick;
  int thread_count;

  // Define quantos threads trabalharão em paralelo
  if (argv[1])
    thread_count = strtol(argv[1], NULL, 10);
  else
    thread_count = 8;

  int chunk_size = totrows/thread_count;

  for (tick = 1; tick <= maxtime; tick++) {
    // Inicializa valores das fontes constantes de calor
    black[totrows/3][cols/3] = 10.0;
    black[2*totrows/3][cols/3] = 20.0;
    black[totrows/3][2*cols/3] = -20.0;
    black[2*totrows/3][2*cols/3] = 20.0;


    #pragma omp parallel shared (black,red,thread_count) \
    private(r,c)
    { // Dispara threads, com totrows/thread_count linhas cada
      #pragma omp for schedule (dynamic, chunk_size)
      for (r=1; r <= totrows; r++)
        for (c=1; c <= cols; c++)
          red[r][c] = ( black[r][c] + black[r][c-1] + black[r-1][c] +
            black[r+1][c] + black[r][c+1] ) / 5.0;

      // Red part of the algorithm (repete, mudando matrizes)
      red[totrows/3][cols/3] = 10.0;
      red[2*totrows/3][cols/3] = 20.0;
      red[totrows/3][2*cols/3] = -20.0;
      red[2*totrows/3][2*cols/3] = 20.0;

    }

    /* Calcula-se as temperaturas nessa iteração */
    #pragma omp parallel shared (black,red,thread_count) \
    private(r,c)
    {
      #pragma omp for schedule (dynamic, totrows/thread_count)
      for (r=1; r < totrows; r++)
        for (c=1; c < cols; c++)
          black[r][c] = ( red[r][c] + red[r][c-1] + red[r-1][c] +
            red[r+1][c] + red[r][c+1] ) / 5.0;
    }
  }
  // Reatribuindo valores constantes antes de terminar
  black[totrows/3][cols/3] = 10.0;
  black[2*totrows/3][cols/3] = 20.0;
  black[totrows/3][2*cols/3] = -20.0;
  black[2*totrows/3][2*cols/3] = 20.0;

  // Imprimindo parte do resultado
  for (r=62; r <= 72; r++) {
    for (c=62; c <= 70; c++)
      printf("%lf ",black[r][c]);
    puts(" "); }
  return 0;
} /* main */
