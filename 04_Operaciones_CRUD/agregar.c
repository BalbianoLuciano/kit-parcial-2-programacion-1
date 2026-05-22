/*
 * OPERACION CRUD — AGREGAR
 *
 * Valida:
 *   1) No supera MAX (arreglo lleno).
 *   2) No permite ID duplicado.
 *
 * Despues de agregar, mantiene el arreglo ordenado por codigo (importante
 * si despues se va a usar busqueda binaria).
 */

#include <stdio.h>
#define MAX 100

struct Producto
{
  int codigo;
  char nombre[30];
  float precio;
};

void agregar(struct Producto arr[], int *n);
void listar(struct Producto arr[], int n);
void ordenarPorCodigo(struct Producto arr[], int n);

int main()
{
  struct Producto inventario[MAX] = {
      {101, "Monitor",  120.00},
      {102, "Teclado",   25.50},
      {103, "Mouse",     15.75}};
  int n = 3;

  listar(inventario, n);
  agregar(inventario, &n);
  listar(inventario, n);

  return 0;
}

void agregar(struct Producto arr[], int *n)
{
  if (*n >= MAX)
  {
    printf("\nNo se pueden agregar mas productos. Inventario lleno.\n");
    return;
  }

  struct Producto nuevo;
  printf("\nIngrese codigo: ");
  scanf("%d", &nuevo.codigo);

  /* Validar duplicado */
  for (int i = 0; i < *n; i++)
  {
    if (arr[i].codigo == nuevo.codigo)
    {
      printf("Ya existe un producto con ese codigo.\n");
      return;
    }
  }

  printf("Ingrese nombre: ");
  scanf(" %29[^\n]", nuevo.nombre);
  printf("Ingrese precio: ");
  scanf("%f", &nuevo.precio);

  arr[*n] = nuevo;
  (*n)++;

  /* Mantener orden */
  ordenarPorCodigo(arr, *n);

  printf("Producto agregado correctamente.\n");
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

void ordenarPorCodigo(struct Producto arr[], int n)
{
  struct Producto temp;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      if (arr[j].codigo > arr[j + 1].codigo)
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}
