/*
 * BUSQUEDA BINARIA — arreglo de structs por campo entero
 *
 * REQUISITO: el arreglo TIENE QUE ESTAR ORDENADO por el campo "codigo".
 *
 * Devuelve el struct encontrado, o uno vacio (codigo=0) si no esta.
 * Patron identico al modelo del 2do parcial.
 */

#include <stdio.h>
#define MAX 100

struct Producto
{
  int codigo;
  char nombre[30];
  float precio;
};

struct Producto buscarBinariaPorCodigo(struct Producto arr[], int n, int buscado)
{
  int inicio = 0;
  int fin = n - 1;

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

int main()
{
  /* Arreglo YA ORDENADO por codigo */
  struct Producto inventario[MAX] = {
      {101, "Monitor",    120.00},
      {102, "Teclado",     25.50},
      {103, "Mouse",       15.75},
      {104, "Webcam",      55.00},
      {105, "Auriculares", 65.50}};
  int n = 5;

  int buscado;
  printf("Ingrese codigo a buscar: ");
  scanf("%d", &buscado);

  struct Producto r = buscarBinariaPorCodigo(inventario, n, buscado);

  if (r.codigo != 0)
  {
    printf("Encontrado:\n");
    printf("  Codigo: %d\n", r.codigo);
    printf("  Nombre: %s\n", r.nombre);
    printf("  Precio: %.2f\n", r.precio);
  }
  else
  {
    printf("No se encontro el producto.\n");
  }

  return 0;
}
