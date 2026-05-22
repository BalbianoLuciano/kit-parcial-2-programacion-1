/*
 * BUSQUEDA LINEAL — arreglo de structs
 *
 * 3 variantes:
 *   1) Buscar por codigo (entero) — devuelve el struct, o uno vacio si no esta.
 *   2) Buscar por nombre (string)  — usa strcmp().
 *   3) Listar TODOS los que cumplen una condicion (precio > X).
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

/* === 1) Por codigo entero === */
struct Producto buscarPorCodigo(struct Producto arr[], int n, int buscado)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i].codigo == buscado)
      return arr[i];
  }
  struct Producto vacio = {0, "", 0.0};
  return vacio;
}

/* === 2) Por nombre (string) === */
struct Producto buscarPorNombre(struct Producto arr[], int n, const char *buscado)
{
  for (int i = 0; i < n; i++)
  {
    if (strcmp(arr[i].nombre, buscado) == 0)
      return arr[i];
  }
  struct Producto vacio = {0, "", 0.0};
  return vacio;
}

/* === 3) Listar todos los que cumplen condicion (precio > X) === */
void listarPorPrecioMayor(struct Producto arr[], int n, float minimo)
{
  int encontrados = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].precio > minimo)
    {
      printf("  %d  %-15s  %.2f\n", arr[i].codigo, arr[i].nombre, arr[i].precio);
      encontrados++;
    }
  }
  if (encontrados == 0)
    printf("  (Ninguno cumple la condicion)\n");
}

int main()
{
  struct Producto inventario[MAX] = {
      {101, "Monitor",    120.00},
      {102, "Teclado",     25.50},
      {103, "Mouse",       15.75},
      {104, "Webcam",      55.00},
      {105, "Auriculares", 65.50}};
  int n = 5;

  /* 1) Buscar por codigo */
  struct Producto r1 = buscarPorCodigo(inventario, n, 103);
  if (r1.codigo != 0)
    printf("Por codigo 103: %s ($%.2f)\n", r1.nombre, r1.precio);
  else
    printf("Codigo 103 no encontrado.\n");

  /* 2) Buscar por nombre */
  struct Producto r2 = buscarPorNombre(inventario, n, "Webcam");
  if (r2.codigo != 0)
    printf("Por nombre Webcam: codigo %d, $%.2f\n", r2.codigo, r2.precio);
  else
    printf("Nombre Webcam no encontrado.\n");

  /* 3) Listar los que cumplen condicion */
  printf("\nProductos con precio > 50:\n");
  listarPorPrecioMayor(inventario, n, 50.00);

  return 0;
}
