#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include<locale.h>
#include<stdlib.h>
#define M 3
#define K 3
#define N 3
#define NUM_THREADS (M * N)

int A[M][K];
int B[K][N];
int C[M][N]; // Matriz resultante

struct ThreadArgs {
  int row;
  int col;
};

void *multiplyElement(void *arg) {
  struct ThreadArgs *args = (struct ThreadArgs *)arg;
  int row = args->row;
  int col = args->col;

  int sum = 0;
  for (int k = 0; k < K; k++) {
    sum += A[row][k] * B[k][col];
  }
  C[row][col] = sum;

  pthread_exit(NULL);
}

int main() {
   srand(time(NULL));
   setlocale(LC_ALL, "Portuguese");
  // Gerar valores aleatórios nas matrizes
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      A[i][j] = rand() % 100;
    }
  }

  for (int i = 0; i < K; i++) {
    for (int j = 0; j < N; j++) {
      B[i][j] = rand() % 100;
    }
  }

  // print matriz A
  printf("Matriz A:\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  // print matriz B
  printf("Matriz B:\n");
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }

  clock_t starttime = clock(); //Inicialização do relógio

  // Declarando threads e argumentos
  pthread_t threads[NUM_THREADS];
  struct ThreadArgs threadArgs[NUM_THREADS];

  // Criando threads
  int threadIndex = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      threadArgs[threadIndex].row = i;
      threadArgs[threadIndex].col = j;
      pthread_create(&threads[threadIndex], NULL, multiplyElement, &threadArgs[threadIndex]);
      threadIndex++;
    }
  }

  // Juntando threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  clock_t endtime = clock(); //Finaliza o relógio
  double totaltime = (double)(endtime-starttime) / CLOCKS_PER_SEC;
  printf("\nTempo: %f segundos\n\n", totaltime);

  // Mostrando a matriz resultante
  printf("Produto de A e B:\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  return 0;
}
