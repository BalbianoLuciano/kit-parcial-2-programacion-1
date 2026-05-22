/*
 * STRUCT — Producto
 * Campos: codigo (int) + nombre (string) + precio (float)
 * Caso de uso: inventarios, listas de artículos, tiendas.
 * (Es la misma forma del modelo del 2° parcial.)
 */

#include <stdio.h>
#define MAX 100

struct Producto
{
  int codigo;
  char nombre[30];
  float precio;
};

int main()
{
  struct Producto inventario[MAX] = {
      {101, "Monitor", 120.00},
      {102, "Teclado", 25.50},
      {103, "Mouse", 15.75},
      {104, "Webcam", 55.00},
      {105, "Auriculares", 65.50}};
  int n = 5;

  printf("CODIGO   NOMBRE              PRECIO\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-8d %-19s %.2f\n", inventario[i].codigo, inventario[i].nombre, inventario[i].precio);
  }
  return 0;
}
