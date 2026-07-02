/*
 * =====================================================================================
 *
 *       Filename:  taller1.c
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE
 * ######################### */

#define DATA_SZ (1024 * 1024 * 64 * 3)

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE
 * ################################ */

static double MEM_CHUNK[DATA_SZ];
int N;
double *a, *b, *c;

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * product Description:  multiply two numbers
 * =====================================================================================
 */

double product(int a, double b) { return a * b; }

struct DATE {
  int days;
  int week;
  int year;
};

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * to_date Description:  calculates the number of days, weeks and days elapsed
 * in the number of days entered
 * =====================================================================================
 */
struct DATE to_date(int n_days) {
  struct DATE date;
  date.year = n_days / 365;
  date.week = (n_days % 365) / 7;
  date.days = (n_days % 365) % 7;
  return date;
}

struct POINT {
  float x;
  float y;
};

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * euclidiana Description:  use euclidean method to find the distance between
 * two points
 * =====================================================================================
 */
float euclidiana(double x1, double y1, double x2, double y2) {
  struct POINT start, end;

  start.x = x1;
  start.y = y1;

  end.x = x2;
  end.y = y2;

  float aux;
  aux = sqrt((pow((start.x - end.x), 2) + pow((start.y - end.y), 2)));

  return aux;
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * get_numbers Description:  prints the numbers according to the specified range
 * =====================================================================================
 */
void get_numbers(int a, int b) {
  int i;
  int MAX;
  MAX = b - a;
  int aux[MAX];
  int *numbers;
  numbers = aux;

  for (i = 0; i <= MAX; ++i) {
    aux[i] = a + i;
  }

  for (i = 0; i < MAX; ++i) {
    printf("%d\n", *numbers);
    numbers++;
  }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * tri_rec Description:  prints an ascending pyramid of asterisks
 * =====================================================================================
 */
void tri_rec(int lines) {
  int i, j;
  for (i = 0; i < lines; ++i) {
    for (j = 0; j < i; ++j) {
      printf("*");
    }
    printf("\n");
  }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * tri_rec_inv Description:  prints a pyramid of asterisks in a decentralized
 * form
 * =====================================================================================
 */

void tri_rec_inv(int lines) {
  int i, j;
  for (i = lines; i > 0; --i) {
    for (j = 0; j < i; ++j) {
      printf("*");
    }
    printf("\n");
  }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * combinao Description: prints a pyramid of asterisks
 * =====================================================================================
 */
void combinao(int lines) {
  tri_rec(lines);
  tri_rec_inv(lines);
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * Matriz_Init_col Description:  initializes and populates the matrix with the
 * specified function
 * =====================================================================================
 */
void Matrix_Init_col(int SZ, double *a, double (*f)()) {
  int j, k;

  for (k = 0; k < SZ; k++)
    for (j = 0; j < SZ; j++) {
      a[j + k * SZ] = (*f)();
    }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * rand_rand Description:  returns a random value (in this case the instruction
 * was burned so that it is only for integer values between 0-10)
 * =====================================================================================
 */
double rand_rand() { return (double)(rand() % 10); }

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * arrPrintMatrix Description:  Print Matrix
 * =====================================================================================
 */
void arrPrintMatrix(double *matrix, int m, int n) {
  int i, j;

  for (i = 0; i < m; i++) {
    printf("\n");
    for (j = 0; j < n; j++) {
      printf("%f\t", matrix[i * n + j]);
    }
  }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * get_one Description:  function returning a one (option decided by the lack of
 * lambda function and the intention to keep a single function for the creation
 * of the matrix)
 * =====================================================================================
 */
double get_one() { return (double)1; }

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * Matrix_one Description:  function dedicated to the generation and printing of
 * a square matrix of ones with dimensions not greater than 8
 * =====================================================================================
 */
void Matrix_one(int size) {
  if (size < 8 && size > 0) {

    N = size;

    a = MEM_CHUNK;

    Matrix_Init_col(N, a, get_one);
    arrPrintMatrix(a, N, N);

  } else {
    printf("PAILA");
  }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * Matrix_rand Description:  function dedicated to the generation and printing
 * of a square matrix with random values of dimensions not exceeding 8
 * =====================================================================================
 */

void Matrix_rand(int size) {
  if (size < 8 && size > 0) {

    N = size;

    a = MEM_CHUNK;

    Matrix_Init_col(N, a, rand_rand);
    arrPrintMatrix(a, N, N);

  } else {
    printf("PAILA");
  }
}

/*
 * ===  FUNCTION
 * ======================================================================
 * Name:two_matrix
 * Description:  function dedicated to the generation of two matrices
 * which will be operated
 * =====================================================================================
 */
void two_matrix(int SZ, double *a, double *b, double *c, double (*f)()) {
  int j, k;

  for (k = 0; k < SZ; k++)
    for (j = 0; j < SZ; j++) {
      a[j + k * SZ] = (*f)();
      b[j + k * SZ] = (*f)();
      c[j + k * SZ] = 0;
    }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * add_mattrix Description:  matrix sum
 * =====================================================================================
 */
void add_matrix(int SZ, double *a, double *b, double *c) {
  int i, j;
  for (i = 0; i < SZ; i++) {
    for (j = 0; j < SZ; j++) {
      c[i + j * SZ] = a[i + j * SZ] + b[i + j * SZ];
    }
  }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * sub_mattrix Description: matrix sub
 * =====================================================================================
 */
void sub_matrix(int SZ, double *a, double *b, double *c) {
  int i, j;
  for (i = 0; i < SZ; i++) {
    for (j = 0; j < SZ; j++) {
      c[i + j * SZ] = a[i + j * SZ] - b[i + j * SZ];
    }
  }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * mult_matrix Description: matrix multiplication
 * =====================================================================================
 */
void mult_matriz(int N, double *a, double *b, double *c) {
  int i, j, k;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      double *pA, *pB, S = 0;
      pA = a + (i * N);
      pB = b + j;
      for (k = 0; k < N; k++) {
        S = S + (*pA * *pB);
        pA++;
        pB += N;
      }
      c[i * N + j] = S;
    }
  }
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * operated_matrix_rand Description:  creates and operates matrices
 * =====================================================================================
 */
void operated_matrix_rand(int size, char type) {
  if (size < 8 && size > 0) {

    N = size;

    a = MEM_CHUNK;
    b = a + N * N;
    c = b + N * N;
    two_matrix(N, a, b, c, rand_rand);
    (type == 's')   ? add_matrix(N, a, b, c)
    : (type == 'r') ? sub_matrix(N, a, b, c)
                    : mult_matriz(N, a, b, c);
    arrPrintMatrix(a, N, N);
    printf("\n-------\n");
    arrPrintMatrix(b, N, N);
    printf("\n-------\n");
    arrPrintMatrix(c, N, N);

  } else {
    printf("PAILA");
  }
}
