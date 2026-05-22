/*
 * ORDENAMIENTO POR INSERCION — arreglo de structs
 * Ordena por campo "codigo" ascendente.
 *
 * El "actual" es un struct entero, no un solo campo. La comparacion se hace
 * con el campo elegido, pero el desplazamiento es del struct completo.
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

void insercionPorCodigo(struct Producto arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    struct Producto actual = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j].codigo > actual.codigo)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = actual;
  }
}

/* Variante: por nombre alfabeticamente */
void insercionPorNombre(struct Producto arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    struct Producto actual = arr[i];
    int j = i - 1;
    while (j >= 0 && strcmp(arr[j].nombre, actual.nombre) > 0)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = actual;
  }
}

int main()
{
  struct Producto inventario[MAX] = {
      {103, "Mouse",       15.75},
      {101, "Monitor",    120.00},
      {105, "Auriculares", 65.50},
      {102, "Teclado",     25.50},
      {104, "Webcam",      55.00}};
  int n = 5;

  insercionPorCodigo(inventario, n);
  printf("Ordenado por codigo:\n");
  for (int i = 0; i < n; i++)
    printf("  %d  %-15s  %.2f\n", inventario[i].codigo, inventario[i].nombre, inventario[i].precio);

  insercionPorNombre(inventario, n);
  printf("\nOrdenado por nombre:\n");
  for (int i = 0; i < n; i++)
    printf("  %d  %-15s  %.2f\n", inventario[i].codigo, inventario[i].nombre, inventario[i].precio);

  return 0;
}
