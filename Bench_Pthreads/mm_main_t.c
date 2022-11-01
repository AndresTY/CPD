/*************************************************
 *Fecha: 09-agosto-2022
 *Autor: Juan Pablo Barrios Suarez
 *Materia: Parallel and Distribuited Computing
 *Tema: Construcción Benchmark Multiplicación de matrices
 *Tópico: Uso Pthreads para paralelismo
 **************************************************/
#include "mm_lib.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  double *matA, *matB, *matC;
  int N, Num_Hilos;
  // arg1.size = (int) atof(argv[1]);
  // arg1.Num_Hilos = (int) atof(argv[2]);
  N = (int)atof(argv[1]);
  Num_Hilos = (int)atof(argv[2]);
  // N = (int) atof(argv[1]); //Cantidad Filas/Columnas
  // Num_Hilos = (int) atof(argv[2]); // Cantidad de hilos
  int MAX_NUM_HILOS = omp_get_max_threads();
  if (!(Num_Hilos > 0 && Num_Hilos <= MAX_NUM_HILOS) || N % Num_Hilos != 0) {
    printf("\t¡Revise los datos de entrada!\n");
    exit(-1);
  }
  /****
   * Declaración de matrices con apuntadores a memoria
   ****/

  matA = (double *)malloc(N * N * sizeof(double));
  matB = (double *)malloc(N * N * sizeof(double));
  matC = (double *)malloc(N * N * sizeof(double));

  inicializacion_mm_double(matA, matB, matC, N);
  punto_prueba_inicial();
  mm_C(matA, matB, matC, N, Num_Hilos);
  punto_prueba_final();

  // impresion_mm_double(matC, N);
  // printf("\t-------------------------------------\n");

  free(matA);
  free(matB);
  free(matC);

  return 0;
}
