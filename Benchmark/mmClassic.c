/*
 * =====================================================================================
 *
 *       Filename:  mmClassic.c
 *
 *    Description: app matmult
 *
 *        Version:  1.0
 *        Created:  06/28/21 09:45:19
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (),
 * andres.ducuara01@correo.usa.edu.co Organization:
 *
 * =====================================================================================
 */

#include "modulo.h"
#define MEM_SIZE (1024 * 1024 * 64 * 2)

static double MEM_CHUNK[MEM_SIZE];

int main(int argc, char **argv) {
  int N;
  double *a, *b, *c;
  struct timeval start, end;

  if (argc < 1) {
    printf("mmClassic matrixSize\n");
    return -1;
  }

  N = (int)atof(argv[1]);
  a = MEM_CHUNK;
  b = a + (N * N);
  c = b + (N * N);
  inicializacion(N, a, b, c);
  /*
  printf("--------a--------\n");
  printMat(N, a);
  printf("--------b--------\n");
  printMat(N, b);
  printf("--------CF--------\n");
  */
  gettimeofday(&start, NULL);
  multMatriz(N, a, b, c);
  gettimeofday(&end, NULL);
  printf("%f\n", (((end.tv_sec * 1000000 + end.tv_usec) -
                   (start.tv_sec * 1000000 + start.tv_usec)) *
                  1e-6));

  /*printf("--------Result--------\n");
  printMat(N,c);
  */
  return 0;
}
