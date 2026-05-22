/*
 * ORDENAMIENTO POR SELECCION — arreglo de enteros
 * Idea: encontrar el minimo del subarreglo no ordenado y ponerlo al principio.
 * Conviene cuando ademas te piden mostrar "el menor" o "el mayor" — la logica
 * de encontrar el minimo ya esta adentro.
 * Complejidad: O(n^2)
 */

#include <stdio.h>
#define N 10

void seleccion(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int posMin = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[posMin])
        posMin = j;
    }
    /* Intercambio */
    if (posMin != i)
    {
      int temp = arr[i];
      arr[i] = arr[posMin];
      arr[posMin] = temp;
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

  seleccion(numeros, N);

  printf("Ordenado: ");
  for (int i = 0; i < N; i++)
    printf("%d ", numeros[i]);
  printf("\n");

  return 0;
}
