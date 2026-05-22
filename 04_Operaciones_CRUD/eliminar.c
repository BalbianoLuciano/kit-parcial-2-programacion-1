/*
 * OPERACION CRUD — ELIMINAR
 *
 * 1) Pide el ID a eliminar.
 * 2) Busca la posicion. Si no esta, avisa y vuelve.
 * 3) Hace SHIFT: copia cada elemento desde la posicion al final una casilla a la izquierda.
 * 4) Decrementa n.
 *
 * Trampa: el shift va hasta n-1 (no n), porque arr[i+1] no debe leer fuera del arreglo.
 */

#include <stdio.h>
#define MAX 100

struct Producto
{
  int codigo;
  char nombre[30];
  float precio;
};

void eliminar(struct Producto arr[], int *n);
void listar(struct Producto arr[], int n);

int main()
{
  struct Producto inventario[MAX] = {
      {101, "Monitor",    120.00},
      {102, "Teclado",     25.50},
      {103, "Mouse",       15.75},
      {104, "Webcam",      55.00},
      {105, "Auriculares", 65.50}};
  int n = 5;

  listar(inventario, n);
  eliminar(inventario, &n);
  listar(inventario, n);

  return 0;
}

void eliminar(struct Producto arr[], int *n)
{
  int idEliminar;
  printf("\nIngrese codigo a eliminar: ");
  scanf("%d", &idEliminar);

  int pos = -1;
  for (int i = 0; i < *n; i++)
  {
    if (arr[i].codigo == idEliminar)
    {
      pos = i;
      break;
    }
  }

  if (pos == -1)
  {
    printf("No existe producto con ese codigo.\n");
    return;
  }

  /* Shift: cada elemento desde pos se reemplaza por el siguiente */
  for (int i = pos; i < *n - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  (*n)--;

  printf("Producto eliminado correctamente.\n");
}

void listar(struct Producto arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay productos.\n");
    return;
  }
  printf("\nCOD   NOMBRE         PRECIO\n");
  for (int i = 0; i < n; i++)
    printf("%-5d %-14s %.2f\n", arr[i].codigo, arr[i].nombre, arr[i].precio);
}
