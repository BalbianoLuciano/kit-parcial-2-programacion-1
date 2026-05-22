/*
 * ORDENAMIENTO BURBUJA — arreglo de enteros
 * Idea: comparar pares adyacentes, intercambiar si estan desordenados,
 *       repetir hasta que no haya cambios. Los mayores "burbujean" al final.
 * Complejidad: O(n^2)
 */

#include <stdio.h>
#define N 10

void burbuja(int arr[], int n)
{
  int temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int numeros[N] = {64, 25, 12, 22, 11, 90, 45, 33, 17, 8};

  printf("Original: ");
  for (int i = 0; i < N; i++)
    printf("%d ", numeros[i]);
  printf("\n");

  burbuja(numeros, N);

  printf("Ordenado: ");
  for (int i = 0; i < N; i++)
    printf("%d ", numeros[i]);
  printf("\n");

  return 0;
}
