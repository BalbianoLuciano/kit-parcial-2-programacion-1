/*
 * ORDENAMIENTO BURBUJA — arreglo de structs
 *
 * Este archivo muestra TRES variantes del mismo algoritmo:
 *   1) Ordenar por campo entero (codigo) — la mas comun
 *   2) Ordenar por campo float (precio)
 *   3) Ordenar por campo string (nombre) — usa strcmp
 *
 * En el parcial, dejá solo la que necesitas. Las otras dos sirven de referencia.
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

struct Producto
{
  int codigo;
  char nombre[30];
  float precio;
};

/* === Variante 1: por codigo (entero) ascendente === */
void burbujaPorCodigo(struct Producto arr[], int n)
{
  struct Producto temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j].codigo > arr[j + 1].codigo)
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

/* === Variante 2: por precio (float) ascendente ===
   Para descendente: invertir el comparador a "<". */
void burbujaPorPrecio(struct Producto arr[], int n)
{
  struct Producto temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j].precio > arr[j + 1].precio)
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

/* === Variante 3: por nombre (string) alfabeticamente ===
   strcmp(a,b) > 0  significa  a viene despues que b alfabeticamente. */
void burbujaPorNombre(struct Producto arr[], int n)
{
  struct Producto temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (strcmp(arr[j].nombre, arr[j + 1].nombre) > 0)
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void imprimir(struct Producto arr[], int n, const char *etiqueta)
{
  printf("\n--- %s ---\n", etiqueta);
  for (int i = 0; i < n; i++)
    printf("  %d  %-15s  %.2f\n", arr[i].codigo, arr[i].nombre, arr[i].precio);
}

int main()
{
  struct Producto inventario[MAX] = {
      {103, "Mouse", 15.75},
      {101, "Monitor", 120.00},
      {105, "Auriculares", 65.50},
      {102, "Teclado", 25.50},
      {104, "Webcam", 55.00}};
  int n = 5;

  imprimir(inventario, n, "Original");

  burbujaPorCodigo(inventario, n);
  imprimir(inventario, n, "Por codigo");

  burbujaPorPrecio(inventario, n);
  imprimir(inventario, n, "Por precio");

  burbujaPorNombre(inventario, n);
  imprimir(inventario, n, "Por nombre");

  return 0;
}
