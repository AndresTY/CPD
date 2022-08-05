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


