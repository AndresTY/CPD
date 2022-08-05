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

typedef void (*f)();

void all_examples();

void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eigth();
void nine();
void ten();
void error();

f func[12] = {&all_examples, &one,   &two,   &three, &four, &five,
              &six,          &seven, &eigth, &nine,  &ten,  &error};

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "I/O Error\n");
    return 1;
  }
  int N = (int)atof(argv[1]);
  argc--;
  argv++;

  (N >= 11) ? func[11] : func[N]();
  return 0;
}

void one() {
  int x, y;
  printf("digit 1> ");
  scanf("%d", &x);
  printf("digit 2> ");
  scanf("%d", &y);
  printf("%d * %d = %f\n", x, y, product(x, y));
}

void two() {
  int x;
  printf("digit 1> ");
  scanf("%d", &x);
  struct DATE y = to_date(x);
  printf("\n2.\n n_days:%d\n\n days:%d\nweek:%d\nyear:%d\n", x, y.days, y.week,
         y.year);
}

void three() {
  int x1, y1, x2, y2;
  printf("point 1 (x,y) > ");
  scanf("%d %d", &x1, &y1);
  printf("point 2 (x,y) > ");
  scanf("%d %d", &x2, &y2);

  printf("\n3. d_e(%d,%d,%d,%d) = %f\n", x1, y1, x2, y2,
         euclidiana(x1, y1, x2, y2));
}

void four() {
  int x, y;
  printf("digit 1> ");
  scanf("%d", &x);
  printf("digit 2> ");
  scanf("%d", &y);
  get_numbers(x, y);
}

void five() {
  int x;
  char t;

  printf("n -> normal\ni -> inverse\nf -> full\n");
  scanf("%c", &t);
  printf("lines> ");
  scanf("%d", &x);
  (t == 'n')   ? tri_rec(x)
  : (t == 'i') ? tri_rec_inv(x)
  : (t == 'f') ? combinao(x)
               : printf("Error");
}

void six() {
  int x;
  printf("size (no more than 8 dimensions) > ");
  scanf("%d", &x);

  Matrix_one(x);
}

void seven() {
  int x;
  printf("size (no more than 8 dimensions) > ");
  scanf("%d", &x);

  Matrix_rand(x);
}
void eigth() {
  int x;
  printf("size (no more than 8 dimensions) > ");
  scanf("%d", &x);

  operated_matrix_rand(x, 's');
}
void nine() {
  int x;
  printf("size (no more than 8 dimensions) > ");
  scanf("%d", &x);

  operated_matrix_rand(x, 'r');
}
void ten() {
  int x;
  printf("size (no more than 8 dimensions) > ");
  scanf("%d", &x);

  operated_matrix_rand(x, 'm');
}
void all_examples() {

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
}
