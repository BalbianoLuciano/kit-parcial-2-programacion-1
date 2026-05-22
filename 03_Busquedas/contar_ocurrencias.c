/*
 * CONTAR OCURRENCIAS — cuantas veces aparece / cuantos cumplen condicion
 *
 * 3 variantes utiles para el parcial:
 *   1) Cuantas veces aparece un numero en un arreglo de int.
 *   2) Cuantos structs cumplen una condicion (ej: precio > X).
 *   3) Cuantos structs tienen un campo string igual a otro (ej: misma marca).
 */

#include <stdio.h>
#include <string.h>
#define MAX 100
#define N 10

struct Producto
{
  int codigo;
  char nombre[30];
  char marca[20];
  float precio;
};

/* === 1) En arreglo de int === */
int contarApariciones(int arr[], int n, int valor)
{
  int contador = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == valor)
      contador++;
  }
  return contador;
}

/* === 2) Por condicion numerica (precio mayor que X) === */
int contarPorPrecioMayor(struct Producto arr[], int n, float minimo)
{
  int contador = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].precio > minimo)
      contador++;
  }
  return contador;
}

/* === 3) Por igualdad de string (misma marca) === */
int contarPorMarca(struct Producto arr[], int n, const char *marca)
{
  int contador = 0;
  for (int i = 0; i < n; i++)
  {
    if (strcmp(arr[i].marca, marca) == 0)
      contador++;
  }
  return contador;
}

int main()
{
  /* 1) Enteros */
  int numeros[N] = {5, 3, 7, 5, 2, 5, 8, 3, 5, 1};
  printf("Cantidad de veces que aparece el 5: %d\n", contarApariciones(numeros, N, 5));

  /* 2) y 3) Structs */
  struct Producto inventario[MAX] = {
      {101, "Monitor",    "LG",       120.00},
      {102, "Teclado",    "Logitech",  25.50},
      {103, "Mouse",      "Logitech",  15.75},
      {104, "Webcam",     "Logitech",  55.00},
      {105, "Auriculares","Sony",      65.50}};
  int n = 5;

  printf("Productos con precio > 30: %d\n", contarPorPrecioMayor(inventario, n, 30.00));
  printf("Productos marca Logitech: %d\n", contarPorMarca(inventario, n, "Logitech"));

  return 0;
}
