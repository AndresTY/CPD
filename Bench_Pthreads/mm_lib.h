/*************************************************
*Fecha: 09-agosto-2022
*Autor: Juan Pablo Barrios Suarez
*Materia: Parallel and Distribuited Computing
*Tema: Biblioteca de funciones para  Multiplicación de matrices
**************************************************/

#ifndef MM_LIB_H_INCLUDED
#define MM_LIB_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


void punto_prueba_inicial();
void punto_prueba_final();
void inicializacion_mm_double_rnd(double *a, double *b, double *c, int N);
double random_double();
void multiplicacion_mm_double(double *a, double *b, double *c, int N);
void impresion_mm_double(double *matriz, int N);
void inicializacion_mm_double(double *a, double *b, double *c, int N);
void *mm_clasica(void *argHILO_mm);

#endif