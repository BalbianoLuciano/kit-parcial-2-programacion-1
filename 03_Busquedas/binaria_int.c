/*
 * BUSQUEDA BINARIA — arreglo de enteros
 *
 * REQUISITO: el arreglo TIENE QUE ESTAR ORDENADO (si no, no funciona).
 *
 * Idea: comparar con el del medio. Si es igual, encontre. Si es menor,
 *       seguir en la mitad izquierda; si es mayor, en la mitad derecha.
 * Complejidad: O(log n)
 */

#include <stdio.h>
#define N 10

int buscarBinaria(int arr[], int n, int buscado)
{
  int inicio = 0;
  int fin = n - 1;

  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2; /* evita overflow */

    if (arr[medio] == buscado)
      return medio;

    if (arr[medio] < buscado)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }
  return -1;
}

int main()
{
  /* Arreglo YA ORDENADO */
  int numeros[N] = {8, 11, 12, 17, 22, 25, 33, 45, 64, 90};
  int buscado;

  printf("Arreglo (ordenado): ");
  for (int i = 0; i < N; i++)
    printf("%d ", numeros[i]);
  printf("\n");

  printf("Ingrese numero a buscar: ");
  scanf("%d", &buscado);

  int pos = buscarBinaria(numeros, N, buscado);

  if (pos != -1)
    printf("Encontrado en la posicion %d.\n", pos);
  else
    printf("No se encontro.\n");

  return 0;
}
