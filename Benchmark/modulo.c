/*
 * =====================================================================================
 *
 *       Filename:  modulo.c
 *
 *    Description: Modulo con inicializacion de las matrices y multiplicacion de
 * la matrices
 *
 *        Version:  2.0
 *        Created:  06/28/21 09:18:19
 *         Update:  08/09/22 10:00:00
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (),
 * andres.ducuara01@correo.usa.edu.co Organization:
 *
 * =====================================================================================
 */
#include "modulo.h"

void inicializacion(int N, double *a, double *b, double *c) {
  int i, j, k = 0;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      k++;
      a[j + i * N] = 2.0 * (i + j);
      b[j + i * N] = k;
      /*b[j+i*N] = 3.7*(i+j);*/
      c[j + i * N] = 0;
    }
  }
}

void inicializacion_int(int N, int *a, int *b, int *c) {
  int i, j, k = 0;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      k++;
      a[j + i * N] = 2.0 * (i + j);
      b[j + i * N] = k;
      /*b[j+i*N] = 3.7*(i+j);*/
      c[j + i * N] = 0;
    }
  }
}
void fill(int N, double *a, double (*f)()) {
  int i, j;
  double temp;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      a[j + i * N] = (*f)();
    }
  }
}

double rnd_values() { return (double)(rand() % 10); }

void multMatriz(int N, double *a, double *b, double *c) {
  int i, j, k;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      double *pA, *pB, S = 0;
      pA = a + (i * N);
      pB = b + j;
      for (k = 0; k < N; k++) {
        /*printf("%lf => %lf\n",*pA,*pB);*/
        S = S + (*pA * *pB);
        pA++;
        pB += N;
      }
      /*printf("S= %lf\n\n",S)*/
      c[i * N + j] = S;
    }
  }
}

void multMatriz_int(int N, int *a, int *b, int *c) {
  int i, j, k;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      int *pA, *pB, S = 0;
      pA = a + (i * N);
      pB = b + j;
      for (k = 0; k < N; k++) {
        /*printf("%lf => %lf\n",*pA,*pB);*/
        S = S + (*pA * *pB);
        pA++;
        pB += N;
      }
      /*printf("S= %lf\n\n",S)*/
      c[i * N + j] = S;
    }
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
