#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#ifndef MIN
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#endif

#define DATA_SZ (1024 * 1024 * 64 * 3)

static double *MEM_CHUNK;
int N;
int num_threads;

long get_cpu() {
  long cpus = sysconf(_SC_NPROCESSORS_ONLN);
  return cpus;
}

typedef struct arguments_threads {
  double *Arg_matA;
  double *Arg_matB;
  double *Arg_matC;
  int Num_hilos;
  int Dimension;
  int ID_thread;
} arg_hilos;

void Matrix_Init_col(int SZ, double *a, double *b, double *c) {
  int j, k;

  for (k = 0; k < SZ; k++)
    for (j = 0; j < SZ; j++) {
      a[j + k * SZ] = 2.2 * (j - k);
      b[j + k * SZ] = 3.7 * (j + k);
      c[j + k * SZ] = 0;
    }
}

void printMat(int N, double *x) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("\t%f\t", x[i * N + j]);
    }
    printf("\n");
  }
}
/*
 * La idea del thread es que se divida la MatrizA en tantas
 * partes como hilos se dispongan, y se envia esa porción
 * junto con la MatrizB completa. La idea es que el hilo
 * calcule la porción que corresponda a la multiplicación
 * de Matrices
 */

void *matrixMultiThread(void *arg) {
  double *a = ((arg_hilos *)arg)->Arg_matA;
  double *b = ((arg_hilos *)arg)->Arg_matB;
  double *c = ((arg_hilos *)arg)->Arg_matC;
  int ID = ((arg_hilos *)arg)->ID_thread;
  int size_Mat = ((arg_hilos *)arg)->Dimension;
  int partition_threads = ((arg_hilos *)arg)->Num_hilos;

  int i, j, k;
  int porcion;
  int start_row, end_row;

  porcion = size_Mat / partition_threads;
  start_row = ID * porcion;
  end_row = (ID + 1) * porcion;

  for (i = start_row; i < end_row; i++)
    for (j = 0; j < size_Mat; j++) {
      double *pA, *pB, S;
      S = 0.0;
      pA = a + (i * size_Mat);
      pB = b + j;
      for (k = size_Mat; k > 0; k--, pA++, pB += size_Mat)
        S += (*pA * *pB);
      c[i * size_Mat + j] = S;
    }
  return 0;
}

int main(int argc, char **argv) {
  int i;
  double *matA, *matB, *matC;
  /* MEM_CHUNK = (double *)malloc(sizeof(double) * DATA_SZ);*/
  pthread_t *threads;
  struct timeval t_start, t_end;
  double totalTime;

  if (argc < 2) {
    printf("MM1c <MatrixSize> <Num_Threads> \n");
    return -1;
  }

  argc--;
  argv++;
  num_threads = (int)atof(argv[1]);
  argc--;
  argv++;

  long max_cores = get_cpu();
  if (max_cores < 0 || num_threads > max_cores) {
    fprintf(stderr, "pop Segmentation Faut: %d\n", errno);
    return -1;
  }

  if (N % num_threads != 0) {
    fprintf(stderr, "dont cumputable: %d\n", errno);
    return -1;
  }
  arg_hilos arg_threads[num_threads];

  matA = (double *)malloc(N * N * sizeof(double));
  matB = (double *)malloc(N * N * sizeof(double));
  matC = (double *)malloc(N * N * sizeof(double));

  /*
  a = MEM_CHUNK;
  b = a + N * N;
  c = b + N * N;*/

  Matrix_Init_col(N, matA, matB, matC);
  printMat(N, matA);
  printMat(N, matB);

  gettimeofday(&t_start, NULL);
  threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));

  /* int *tid;
   tid = (int *)malloc(sizeof(int));*/
  for (i = 0; i < num_threads; i++) {
    /*tid = i;*/
    arg_threads[i].Arg_matA = matA;
    arg_threads[i].Arg_matB = matB;
    arg_threads[i].Arg_matC = matC;
    arg_threads[i].Num_hilos = num_threads;
    arg_threads[i].Dimension = N;
    arg_threads[i].ID_thread = i;
    pthread_create(&threads[i], NULL, matrixMultiThread, &arg_threads[i]);
  }

  for (i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }
  gettimeofday(&t_end, NULL);

  totalTime = (t_end.tv_sec * 1000000 + t_end.tv_usec) -
              (t_start.tv_sec * 1000000 + t_start.tv_usec);

  printMat(N, matC);
  printf("%f \n", totalTime / 1000000);

  free(threads);
  /* free(tid);*/
  free(MEM_CHUNK);
  return 0;
}
