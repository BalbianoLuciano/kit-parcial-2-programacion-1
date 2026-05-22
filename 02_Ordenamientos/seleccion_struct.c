/*
 * ORDENAMIENTO POR SELECCION — arreglo de structs
 * Ordena por campo "codigo" ascendente. Para otro campo, cambiar el comparador.
 * Para ordenar por nombre: usar strcmp() en el if del minimo.
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

void seleccionPorCodigo(struct Producto arr[], int n)
{
  struct Producto temp;
  for (int i = 0; i < n - 1; i++)
  {
    int posMin = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j].codigo < arr[posMin].codigo)
        posMin = j;
    }
    if (posMin != i)
    {
      temp = arr[i];
      arr[i] = arr[posMin];
      arr[posMin] = temp;
    }
  }
}

/* Variante: por nombre alfabeticamente */
void seleccionPorNombre(struct Producto arr[], int n)
{
  struct Producto temp;
  for (int i = 0; i < n - 1; i++)
  {
    int posMin = i;
    for (int j = i + 1; j < n; j++)
    {
      if (strcmp(arr[j].nombre, arr[posMin].nombre) < 0)
        posMin = j;
    }
    if (posMin != i)
    {
      temp = arr[i];
      arr[i] = arr[posMin];
      arr[posMin] = temp;
    }
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

  seleccionPorCodigo(inventario, n);
  printf("Ordenado por codigo:\n");
  for (int i = 0; i < n; i++)
    printf("  %d  %-15s  %.2f\n", inventario[i].codigo, inventario[i].nombre, inventario[i].precio);

  seleccionPorNombre(inventario, n);
  printf("\nOrdenado por nombre:\n");
  for (int i = 0; i < n; i++)
    printf("  %d  %-15s  %.2f\n", inventario[i].codigo, inventario[i].nombre, inventario[i].precio);

  return 0;
}
