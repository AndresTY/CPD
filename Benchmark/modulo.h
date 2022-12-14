/*
 * =====================================================================================
 *
 *       Filename:  modulo.h
 *
 *    Description: interfaz del modulo
 *
 *        Version:  1.0
 *        Created:  06/28/21 09:43:20
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (),
 * andres.ducuara01@correo.usa.edu.co Organization:
 *
 * =====================================================================================
 */
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

long get_cpu();
void inicializacion(int N, double *a, double *b, double *c);
void inicializacion_int(int N, int *a, int *b, int *c);
void fill(int N, double *a, double (*f)());
void multMatriz(int N, double *a, double *b, double *c);
void multMatriz_int(int N, int *a, int *b, int *c);
void FeamultMatriz(int N, double *a, double *b, double *c);
void printMat(int N, double *x);
double rnd_values();
#endif
