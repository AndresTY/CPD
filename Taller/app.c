/*
 * =====================================================================================
 *
 *       Filename:  app.c
 *
 *    	  Subject:
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/04/22 00:45:59
 *  Github/Gitlab:  AndresTY/
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (),
 * andres.ducuara01@usa.edu.co Organization:
 *
 * =====================================================================================
 */

#include "taller1.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("SALIDA DEL PROGRAMA\n\n\n");
  printf("\n1. %d * %d = %f\n", 15, 5, product(15, 5));

  struct DATE x = to_date(1329);
  printf("\n2.\n n_days:%d\n\n days:%d\nweek:%d\nyear:%d\n", 1329, x.days,
         x.week, x.year);

  printf("\n3. d_e(%d,%d,%d,%d) = %f\n", 25, 15, 35, 10,
         euclidiana(25, 15, 35, 10));

  printf("\n4. ");
  get_numbers(0, 10);

  printf("\n5. right-angled triangle 15 lines\n");
  tri_rec(15);

  printf("\n5. right-angled triangle inv 15 lines\n");
  tri_rec_inv(15);

  printf("\n5. triangle 15 lines\n");
  combinao(15);

  printf("\n6.matrix of ones\n");
  Matrix_one(7);

  printf("\n7. random value matrix\n");
  Matrix_rand(6);

  printf("\n8. matrix sum\n");
  operated_matrix_rand(5, 's');
  printf("\n9. matrix sub\n");
  operated_matrix_rand(5, 'r');
  printf("\n10. matrix multiplication\n");
  operated_matrix_rand(5, 'm');
  return 0;
}
