/*
 * OPERACION CRUD — MODIFICAR
 *
 * 1) Pide el ID a modificar.
 * 2) Busca la posicion. Si no esta, avisa y vuelve.
 * 3) Pide los nuevos valores y reemplaza el struct en esa posicion.
 *
 * NOTA: n NO cambia, asi que se pasa por valor (int n, no int *n).
 *
 * Si se permite modificar el codigo, hay que volver a validar duplicados y reordenar.
 * Esta version conserva el codigo (lo mas comun en parciales) y solo cambia nombre y precio.
 */

#include <stdio.h>
#define MAX 100

struct Producto
{
  int codigo;
  char nombre[30];
  float precio;
};

void modificar(struct Producto arr[], int n);
void listar(struct Producto arr[], int n);

int main()
{
  struct Producto inventario[MAX] = {
      {101, "Monitor",    120.00},
      {102, "Teclado",     25.50},
      {103, "Mouse",       15.75}};
  int n = 3;

  listar(inventario, n);
  modificar(inventario, n);
  listar(inventario, n);

  return 0;
}

void modificar(struct Producto arr[], int n)
{
  int idModificar;
  printf("\nIngrese codigo a modificar: ");
  scanf("%d", &idModificar);

  int pos = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].codigo == idModificar)
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

  printf("Nuevo nombre: ");
  scanf(" %29[^\n]", arr[pos].nombre);
  printf("Nuevo precio: ");
  scanf("%f", &arr[pos].precio);

  printf("Producto modificado correctamente.\n");
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
