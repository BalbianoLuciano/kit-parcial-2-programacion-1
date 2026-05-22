/*
 * CRUD PRODUCTOS — replica casi literal del modelo del 2do parcial.
 *
 * Struct:  codigo + nombre + precio
 * Menu:    listar, buscar (binaria), agregar, eliminar, modificar, salir
 * Orden:   por codigo ascendente, se mantiene tras agregar.
 *
 * Compila:  gcc -Wall crud_productos.c -o crud && ./crud
 */

#include <stdio.h>
#include <string.h>
#define MAX 1000

struct Producto
{
  int codigo;
  char nombre[30];
  float precio;
};

/* Prototipos */
void listarProductos(struct Producto arr[], int n);
struct Producto buscarProducto(struct Producto arr[], int n);
void agregarProducto(struct Producto arr[], int *n);
void eliminarProducto(struct Producto arr[], int *n);
void modificarProducto(struct Producto arr[], int n);
void ordenarPorCodigo(struct Producto arr[], int n);

int main()
{
  struct Producto inventario[MAX] = {
      {58293012, "Monitor",        120.00},
      {19485726, "Mousepad",        10.00},
      {83746501, "Procesador",     200.00},
      {37482910, "Teclado",         25.50},
      {92837465, "Fuente ATX",      75.00},
      {48291037, "Webcam",          55.00},
      {10293847, "Silla Gamer",    250.00},
      {74659283, "Impresora",       85.00},
      {29384756, "Disco SSD",       95.00},
      {65748392, "Mouse",           15.75}};
  int n = 10;

  /* Ordenamiento inicial para que la binaria funcione */
  ordenarPorCodigo(inventario, n);

  int opcion;
  do
  {
    printf("\n=== MENU DE PRODUCTOS ===\n");
    printf("1) Listar\n");
    printf("2) Buscar\n");
    printf("3) Agregar\n");
    printf("4) Eliminar\n");
    printf("5) Modificar\n");
    printf("6) Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      listarProductos(inventario, n);
      break;
    case 2:
    {
      struct Producto p = buscarProducto(inventario, n);
      if (p.codigo != 0)
      {
        printf("\nEncontrado:\n");
        printf("  Codigo: %d\n", p.codigo);
        printf("  Nombre: %s\n", p.nombre);
        printf("  Precio: %.2f\n", p.precio);
      }
      else
      {
        printf("\nNo se encontro el producto.\n");
      }
      break;
    }
    case 3:
      agregarProducto(inventario, &n);
      break;
    case 4:
      eliminarProducto(inventario, &n);
      break;
    case 5:
      modificarProducto(inventario, n);
      break;
    case 6:
      printf("\nSaliendo...\n");
      break;
    default:
      printf("\nOpcion invalida. Intente nuevamente.\n");
    }
  } while (opcion != 6);

  return 0;
}

void listarProductos(struct Producto arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay productos cargados.\n");
    return;
  }
  printf("\n#   CODIGO     NOMBRE              PRECIO\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-3d %-10d %-19s %.2f\n",
           i + 1, arr[i].codigo, arr[i].nombre, arr[i].precio);
  }
}

/* Busqueda binaria por codigo. Requiere el arreglo ordenado. */
struct Producto buscarProducto(struct Producto arr[], int n)
{
  int buscado;
  printf("Ingrese codigo a buscar: ");
  scanf("%d", &buscado);

  int inicio = 0, fin = n - 1;
  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;
    if (arr[medio].codigo == buscado)
      return arr[medio];
    if (arr[medio].codigo < buscado)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }
  struct Producto vacio = {0, "", 0.0};
  return vacio;
}

void agregarProducto(struct Producto arr[], int *n)
{
  if (*n >= MAX)
  {
    printf("\nInventario lleno.\n");
    return;
  }

  struct Producto nuevo;
  printf("Codigo: ");
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

  printf("Nombre: ");
  scanf(" %29[^\n]", nuevo.nombre);
  printf("Precio: ");
  scanf("%f", &nuevo.precio);

  arr[*n] = nuevo;
  (*n)++;
  ordenarPorCodigo(arr, *n);

  printf("Producto agregado correctamente.\n");
}

void eliminarProducto(struct Producto arr[], int *n)
{
  int idEliminar;
  printf("Codigo a eliminar: ");
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

  for (int i = pos; i < *n - 1; i++)
    arr[i] = arr[i + 1];
  (*n)--;

  printf("Producto eliminado correctamente.\n");
}

void modificarProducto(struct Producto arr[], int n)
{
  int idModificar;
  printf("Codigo a modificar: ");
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
