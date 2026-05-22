/*
 * ORDENAMIENTO POR INSERCION — arreglo de enteros
 * Idea: tomar cada elemento y "insertarlo" en su posicion en la parte ya ordenada.
 * Como cuando ordenas cartas en la mano.
 * Complejidad: O(n^2) peor caso, O(n) si ya esta casi ordenado.
 */

#include <stdio.h>
#define N 10

void insercion(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int actual = arr[i];
    int j = i - 1;
    /* Correr a la derecha mientras encontremos elementos mayores que "actual" */
    while (j >= 0 && arr[j] > actual)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = actual;
  }
}

int main()
{
  int numeros[N] = {64, 25, 12, 22, 11, 90, 45, 33, 17, 8};

  printf("Original: ");
  for (int i = 0; i < N; i++)
    printf("%d ", numeros[i]);
  printf("\n");

  insercion(numeros, N);

  printf("Ordenado: ");
  for (int i = 0; i < N; i++)
    printf("%d ", numeros[i]);
  printf("\n");

  return 0;
}
