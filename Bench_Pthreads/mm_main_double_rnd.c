/*************************************************
*Fecha: 09-agosto-2022
*Autor: Juan Pablo Barrios Suarez
*Materia: Parallel and Distribuited Computing
*Tema: Construcción Benchmark Multiplicación de matrices
*Tópico: Uso Pthreads para paralelismo
**************************************************/
#include "mm_lib.h"
#include <stdio.h>
#include <stdlib.h>

/****
 * Se requiere reservar un espacio de memporia 
****/
#define DATA_SIZE (1024 * 1024 * 64 * 3)
static double MEM_CHUNK[DATA_SIZE];

/*
*Se declaran las variables globales
*/
double *a, *b, *c; //Matrices
int Num_Hilos;  //Numero de hilos
int N; //Dimensiones de la matriz

/****
 * Función principal de la aplicación 
****/
int main(int argc, char **argv){

    N = (int) atof(argv[1]);
    

    /****
     * Declaración de matrices con apuntadores a memoria
    ****/
    a = MEM_CHUNK;
    b =  a + N*N;
    c =  b + N*N;

    printf("\t-> Inicializacion con double aleatorio:\n");
    inicializacion_mm_double_rnd(a, b, c, N);
    impresion_mm_double(a, N);
    impresion_mm_double(b, N);
    

    /****
     * Inicio de toma de tiempo
     * Mulplticación de matrices
     * Fin de toma de tiempo 
    ****/
    punto_prueba_inicial();
    multiplicacion_mm_double(a, b, c, N);
    punto_prueba_final();

    
    
    impresion_mm_double(c, N);
    printf("\t-------------------------------------\n");
    

    return 0;
}
