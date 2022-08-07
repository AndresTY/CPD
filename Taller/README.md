# TALLER 1 - PRÁCTICA DE C

El objetivo del taller es practicar y recordar las herramientas y la sintaxis del lenguaje de programación *C* para posteriormente adentrarnos en la computación paralela y distribuida. 

## Ejercicios

Los ejercicios dispuestos en [PDF Taller](/Taller_C_01.pdf).

1- Escribe un programa en C que acepte dos enteros del usuario y calcule el producto de los dos enteros

```c
double product(int a, double b) { return a * b; }
```

Se puede observar la declaración de una función con un retorno de tipo double.

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

Para esta solución se implementa el concepto de estructura, retornando un objeto con los datos requeridos.

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
De igual manera que el ejercicio anterior se implementan las estructuras y adicionalmente se utiliza la biblioteca de Math.h para la raíz cuadrada.

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

5.- Hacer un triángulo rectángulo con asteriscos

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

6.- creación de matriz NxN con dimensiones no mayores a 8 con valores 1

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

Se exploran los punteros para la asignación de arreglos y de funciones "anónimas"

---

7.- creación de matriz NxN con dimensiones no mayores a 8 con valores aleatorios

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

10.- multiplicación de matrices
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

### Construcción del aplicativo

```
make app
```

### Limpieza \*.o

```
make clean
```

### Limpieza total

```
make clear
```

### Ejecuciones

|Comando|Descripción|
|---|---|
|```make test```| Ejecuta una simulación que muestra todas las funciones|
|```make product```| ejecución del $1^{re}$ punto|
|```make day\_to\_date```| ejecución del $2^{do}$ punto|
|```make distancia```| ejecución del $3^{er}$ punto|
|```make sequence```| ejecución del $4^{to}$ punto|
|```make triangle```| ejecución del $5^{to}$ punto|
|```make identity```| ejecución del $6^{to}$ punto|
|```make rand```| ejecución del $7^{mo}$ punto|
|```make sum\_NxN```| ejecución del $8^{vo}$ punto|
|```make sub\_NxN```| ejecución del $9^{no}$ punto|
|```make mutl\_NxN```| ejecución del $10^{mo}$ punto|

# RECOMENDACIONES

* En caso de no estar totalmente acostumbrado a la visualización en la terminal, recomiendo cargar la información de salida en un .txt para mejor apreciación
	
	`make test > test.txt`

* Especificaciones del entorno de ejecución:
	* > gcc version 12.1.1 20220730 (GCC)
	* > Editor: nvim
	* > standard C libraries (string, stdio, math, etc...) 

