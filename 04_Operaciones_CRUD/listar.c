/*
 * OPERACION CRUD — LISTAR
 *
 * Avisa si el arreglo esta vacio (importante: si imprimis nada el corrector piensa que no funciona).
 *
 * Se incluyen 2 variantes:
 *   1) listar todos
 *   2) listar con filtro (solo los que cumplen condicion)
 */

#include <stdio.h>
#define MAX 100

struct Producto
{
  int codigo;
  char nombre[30];
  float precio;
};

void listar(struct Producto arr[], int n);
void listarConFiltro(struct Producto arr[], int n, float precioMinimo);

int main()
{
  struct Producto inventario[MAX] = {
      {101, "Monitor",    120.00},
      {102, "Teclado",     25.50},
      {103, "Mouse",       15.75},
      {104, "Webcam",      55.00},
      {105, "Auriculares", 65.50}};
  int n = 5;

  printf("=== Todos los productos ===");
  listar(inventario, n);

  printf("\n=== Productos con precio > 50 ===");
  listarConFiltro(inventario, n, 50.00);

  return 0;
}

void listar(struct Producto arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay productos cargados.\n");
    return;
  }
  printf("\nCOD   NOMBRE              PRECIO\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-5d %-19s %.2f\n", arr[i].codigo, arr[i].nombre, arr[i].precio);
  }
}

void listarConFiltro(struct Producto arr[], int n, float precioMinimo)
{
  int encontrados = 0;
  printf("\nCOD   NOMBRE              PRECIO\n");
  for (int i = 0; i < n; i++)
  {
    if (arr[i].precio > precioMinimo)
    {
      printf("%-5d %-19s %.2f\n", arr[i].codigo, arr[i].nombre, arr[i].precio);
      encontrados++;
    }
  }
  if (encontrados == 0)
    printf("(Ninguno cumple la condicion)\n");
}
