/*************************************************
*Fecha: 09-agosto-2022
*Autor: Juan Pablo Barrios Suarez
*Materia: Parallel and Distribuited Computing
*Tema: Biblioteca de funciones para  Multiplicación de matrices
*Tópico: Módulo para paralelismo
**************************************************/

#include "mm_lib.h"
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

struct timespec inicio_cuenta, fin_cuenta;

typedef struct argumentos_hilos{
    double *matA; //Matrices
    double *matB; //Matrices
    double *matC; //Matrices
    int Num_Hilos;  //Numero de hilos
    int size; //Dimensiones de la matriz
    int ID_hilo;
}arg_threads;


/* Función puntero para envio de PROBLEMA */

/* La idea principal es dividir la matriz A en porciones
* tal que cada porcion vaya con un hilo. Cada hilo se podra
* identificar, pasando como argumento a la funcion. La solcuión
* planteada envia toda la matriz B para cada hilo
*/
void *mm_clasica(void *argHILO_mm){
    /* 
    *Se castea argHILO_mm como arg_threads
    */
   double *a = ((arg_threads *) argHILO_mm) -> matA;
   double *b = ((arg_threads *) argHILO_mm) -> matB;
   double *c = ((arg_threads *) argHILO_mm) -> matC;
   int ID_hilo = ((arg_threads *) argHILO_mm) -> ID_hilo; //Identificación del hilo
   int N_mm = ((arg_threads *) argHILO_mm) -> size;
   int N_threads = ((arg_threads *) argHILO_mm) -> Num_Hilos;


    int i, j, k;
    int porcion = N_mm/N_threads;
    int ini_porcion, fin_porcion;
    ini_porcion = porcion*ID_hilo;
    fin_porcion = porcion*(ID_hilo+1);

    for (i = ini_porcion; i < fin_porcion; i++){
        for(j = 0; j < N_mm; j++){
            double suma = 0.0 ;
            /* Punteros auxiliares */
            double *pA, *pB;
            pA = a + (j*N_mm);
            pB = b + i;
            for (k = 0; k < N_mm; k++, pA++, pB+=N_mm) {
                /* Multiplicación y suma de resultados */ 
                suma += (*pA * *pB);
            }
            c[j+i*N_mm] = suma;
        }
    }
    return 0;
}

/**** 
 * Funcion evaluación inicio de tiempo  
****/
void punto_prueba_inicial(){
    clock_gettime(CLOCK_MONOTONIC, &inicio_cuenta);
}

/**** 
 * Funcion evaluación final de tiempo e impresión de resultado  
****/
void punto_prueba_final(){
    double total_time;
    clock_gettime(CLOCK_MONOTONIC, &fin_cuenta);
    total_time = (fin_cuenta.tv_sec - inicio_cuenta.tv_sec) * 1e9;
    total_time = (total_time + fin_cuenta.tv_nsec - inicio_cuenta.tv_nsec)* 1e-9;
    printf("\t-> Total time ----> |%f| <----\n",total_time);
}


/****
 * Inicialización de matrices (doble)
****/
void inicializacion_mm_double(double *a, double *b, double *c, int N){
    int i, j;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            a[i+j*N] = 2.1 * (i+j);
            b[i+j*N] = 2.2 * i + 3.3 * j;
            c[i+j*N] = 0.0;
        }
    }
}


/****
 * Impresión de matrices (doble)
****/
void impresion_mm_double(double *matriz, int N){
    if(N<5){
        int i, j;
        printf("\n	");
        for (i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                printf("%f  ", matriz[j+i*N]);
            }
            printf("\n	");
        }
        printf("\n\t-----------------\n");
    }
}


/****
 * Función Multiplicación Benchmark 2
****/
void multiplicacion_mm_double(double *a, double *b, double *c, int N){
    int i, j, k;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            double suma = 0.0 ;
            /* Punteros auxiliares */
            double *pA, *pB;
            pA = a + (j*N);
            pB = b + i;

            for (k = 0; k < N; k++, pA++, pB+=N) {
                /* Multiplicación y suma de resultados */ 
                suma += (*pA * *pB);
            }
            c[j+i*N] = suma;
        }
    }
}


/* Funcion para crear dobles aleatorios*/

double random_double(){
    double min = 0.001, max = 9.999;
    static int flag = -1;
    if((flag = (flag<0)))
        srand(time(NULL) + getpid());
    if(min > max) return errno = EDOM, NAN;

    return min + (double) rand()/((double) RAND_MAX/(max-min));
}


/****
 * Inicialización de matrices aleatoria (dobles)
****/
void inicializacion_mm_double_rnd(double *a, double *b, double *c, int N){
    int i, j;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            a[i+j*N] = random_double();
            b[i+j*N] = random_double();
            c[i+j*N] = 0;
        }
    }
}
