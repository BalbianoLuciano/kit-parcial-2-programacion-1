/*
 * BUSQUEDA LINEAL — arreglo de enteros
 * Recorre uno por uno hasta encontrar (o llegar al final).
 * Devuelve la POSICION (indice) del elemento, o -1 si no esta.
 * Complejidad: O(n)
 */

#include <stdio.h>
#define N 10

int buscarLineal(int arr[], int n, int buscado)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == buscado)
      return i;
  }
  return -1;
}

int main()
{
  int numeros[N] = {64, 25, 12, 22, 11, 90, 45, 33, 17, 8};
  int buscado;

  printf("Ingrese numero a buscar: ");
  scanf("%d", &buscado);

  int pos = buscarLineal(numeros, N, buscado);

  if (pos != -1)
    printf("Encontrado en la posicion %d.\n", pos);
  else
    printf("No se encontro.\n");

  return 0;
}
