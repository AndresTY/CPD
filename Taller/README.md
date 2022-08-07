# TALLER 1 - PRACTICA DE C

El objetivo del taller es practicar y recordar la herramientas y la sintaxis del lenguaje de programcion *C* para posteriormente adentrarnos en la computacion paralela y distribuida. 

## Ejercicios

Los ejecrcicios dispuestos en [PDF Taller](/Taller_C_01.pf).

1- Escribe un programa en C que acepte dos enteros del usuario y calcule el producto de losdos enteros

```c
double product(int a, double b) { return a * b; }
```

Se puede observar la declaracion de una funcion con un un retorno de tipo double.

---

2- Escribe un programa en C para convertir los días especificados en años, semanas y días. Nota: Ignore el año bisiesto.

```c
struct DATE to_date(int n_days) {
  struct DATE date;
  date.year = n_days / 365;
  date.week = (n_days % 365) / 7;
  date.days = (n_days % 365) % 7;
  return date;
}
```

Para esta solucion se implementa el concepto de estructura, retorinando un objeto con los datos requeridos.

---
3.- Escribe un programa en C para calcular la distancia entre los dos puntos.

```c
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
```
De igual manera que el ejercicio anterior se implementan las estructuras y adicionalmente se utiliza la biblioteca de Math.h para la raiz cuadrada.

---

4.- Escribe un programa en C para mostrar los 10 primeros números naturales

```c

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
```
---

5.- Hacer una triangulo rectangulo con asteriscos

```c

void tri_rec(int lines) {
  int i, j;
  for (i = 0; i < lines; ++i) {
    for (j = 0; j < i; ++j) {
      printf("*");
    }
    printf("\n");
  }
}

```
---

6.- creacion de matriz NxN con dimesiones no mayores a 8 con valores 1

```c
void Matrix_Init_col(int SZ, double *a, double (*f)()) {
  int j, k;
  for (k = 0; k < SZ; k++)
    for (j = 0; j < SZ; j++) {
      a[j + k * SZ] = (*f)();
    }
}
```
```c
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
```

Se exploran los punteros para la asignacion de arreglos y de funciones "anonimas"

---

7.- creacion de matriz NxN con dimesiones no mayores a 8 con valores aleatorios

```c
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

```
---

8.- suma de matrices
```c
void add_matrix(int SZ, double *a, double *b, double *c) {
  int i, j;
  for (i = 0; i < SZ; i++) {
    for (j = 0; j < SZ; j++) {
      c[i + j * SZ] = a[i + j * SZ] + b[i + j * SZ];
    }
  }
}

```
---

9.- resta de matrices
```c
void sub_matrix(int SZ, double *a, double *b, double *c) {
  int i, j;
  for (i = 0; i < SZ; i++) {
    for (j = 0; j < SZ; j++) {
      c[i + j * SZ] = a[i + j * SZ] - b[i + j * SZ];
    }
  }
}
```
---

10.- multiplicacion de matrices
```c
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
```

# USO

### Construccion del aplicativo

```
Make app
```

### Limpieza \*.o

```
Make clean
```

### Limpieza total

```
Make clear
```

### Ejecuciones

|Command|Description|
|---|---|
|```Make test```| Ejecuta una simulacion que muestra todas las funciones|
|```Make product```| ejecucion del $1^{re}$ punto|
|```Make day\_to\_date```| ejecucion del $2^{do}$ punto|
|```Make distnacia```| ejecucion del $3^{er}$ punto|
|```Make sequence```| ejecucion del $4^{to}$ punto|
|```Make triangle```| ejecucion del $5^{to}$ punto|
|```Make identity```| ejecucion del $6^{to}$ punto|
|```Make rand```| ejecucion del $7^{mo}$ punto|
|```Make sum\_NxN```| ejecucion del $8^{vo}$ punto|
|```Make sub\_NxN```| ejecucion del $9^{no}$ punto|
|```Make mutl\_NxN```| ejecucion del $10^{mo}$ punto|
