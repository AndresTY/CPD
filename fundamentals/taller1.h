/*
 * =====================================================================================
 *
 *       Filename:  taller1.h
 *
 *    	  Subject:  Parallel and distributed computing
 *
 *    Description:  Given the knowledge acquired in the class, elaborate the
 * workshop provided by the teacher.
 *
 *        Version:  1.0
 *        Created:  08/03/22 19:26:03
 *  Github/Gitlab:  AndresTY/@Andres_TY
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (),
 * andres.ducuara01@usa.edu.co Organization:  Universidad Sergio Arboleda (USA)
 *
 * =====================================================================================
 */
#ifndef TALLER1_H_INCLUDED
#define TALLER1_H_INCLUDED
double product(int a, double b);
struct DATE {
  int days;
  int week;
  int year;
};
struct DATE to_date(int n_days);
float euclidiana(double x1, double y1, double x2, double y2);
void get_numbers(int a, int b);
void tri_rec(int lines);
void tri_rec_inv(int lines);
void combinao(int lines);
void Matrix_Init_col(int SZ, double *a, double (*f)());
double rand_rand();
void arrPrintMatrix(double *matrix, int m, int n);
double get_one();
void Matrix_one(int size);
void Matrix_rand(int size);
void two_matrix(int SZ, double *a, double *b, double *c, double (*f)());
void add_matrix(int SZ, double *a, double *b, double *c);
void sub_matrix(int SZ, double *a, double *b, double *c);
void mult_matriz(int N, double *a, double *b, double *c);
void operated_matrix_rand(int size, char type);
#endif
