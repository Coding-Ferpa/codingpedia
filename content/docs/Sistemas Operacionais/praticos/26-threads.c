#include <assert.h>
#include <memory.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static volatile int counter;

void *mythread(void *arg) {
  int *A = malloc(sizeof(int) * 5);
  A = arg;
  for (int i = 0; i < 5; i++) {
    printf("%d ", A[i]);
  }
  for (int i=0; i < 1e6; i++)
    counter++;
  puts("");
  printf("thread: counter %d\n", counter);
  return NULL;
}

int main(int argc, char **argv) {
  pthread_t p1, p2; // unsigned long int
  int G[10] = {1, 2, 4, 10, 4, 5, 0, 5, 6, 6};

  printf("main: begin\n");
  pthread_create(&p1, NULL, mythread, G);
  pthread_create(&p2, NULL, mythread, G);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  printf("main: counter %d\n", counter);
  printf("main: end\n");
  return 0;
}
