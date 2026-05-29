/*
 * MODELO DE PARCIAL 3 — Arreglo de enteros + menu + estadisticas
 * --------------------------------------------------------------
 * Estilo "modelo del 2do parcial" pero con un arreglo de ENTEROS (sin struct).
 * Util cuando la consigna trabaja con numeros sueltos (temperaturas, edades,
 * cantidades, puntajes, etc.) en vez de registros con varios campos.
 *
 * Consigna tipo que resuelve:
 *   "Cargar un arreglo de temperaturas. Mediante un menu permitir: listar
 *    ordenadas, buscar una temperatura (binaria), agregar, eliminar, y mostrar
 *    estadisticas (promedio, maxima y minima)."
 *
 * Compila: gcc -Wall -Wextra modelo_temperaturas_int.c -o modelo3 && ./modelo3
 */

#include <stdio.h>
#define MAX 100

/* === Prototipos === */
void ordenar(int arr[], int n);
void listar(int arr[], int n);
void buscar(int arr[], int n);
void agregar(int arr[], int *n);
void eliminar(int arr[], int *n);
void estadisticas(int arr[], int n);

int main()
{
  int temperaturas[MAX] = {22, 18, 30, 15, 27, 21, 33, 19};
  int n = 8;

  ordenar(temperaturas, n); /* ordenado de entrada para la busqueda binaria */

  int opcion;
  do
  {
    printf("\n=== REGISTRO DE TEMPERATURAS ===\n");
    printf("1) Listar (ordenadas)\n");
    printf("2) Buscar\n");
    printf("3) Agregar\n");
    printf("4) Eliminar\n");
    printf("5) Estadisticas (promedio / max / min)\n");
    printf("6) Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      listar(temperaturas, n);
      break;
    case 2:
      buscar(temperaturas, n);
      break;
    case 3:
      agregar(temperaturas, &n);
      break;
    case 4:
      eliminar(temperaturas, &n);
      break;
    case 5:
      estadisticas(temperaturas, n);
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

/* === Implementaciones === */

void ordenar(int arr[], int n)
{
  int temp;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}

void listar(int arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay temperaturas cargadas.\n");
    return;
  }
  printf("\nTemperaturas: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void buscar(int arr[], int n)
{
  int buscado;
  printf("Ingrese temperatura a buscar: ");
  scanf("%d", &buscado);

  int inicio = 0, fin = n - 1, pos = -1;
  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;
    if (arr[medio] == buscado)
    {
      pos = medio;
      break;
    }
    if (arr[medio] < buscado)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }

  if (pos != -1)
    printf("\nEncontrada en la posicion %d.\n", pos + 1);
  else
    printf("\nNo se encontro la temperatura %d.\n", buscado);
}

void agregar(int arr[], int *n)
{
  if (*n >= MAX)
  {
    printf("\nNo se pueden agregar mas valores (lleno).\n");
    return;
  }
  printf("Ingrese una temperatura: ");
  scanf("%d", &arr[*n]);
  (*n)++;
  ordenar(arr, *n); /* mantener orden */
  printf("\nTemperatura agregada y ordenada.\n");
}

void eliminar(int arr[], int *n)
{
  int valor;
  printf("Ingrese temperatura a eliminar: ");
  scanf("%d", &valor);

  int pos = -1;
  for (int i = 0; i < *n; i++)
    if (arr[i] == valor)
    {
      pos = i;
      break;
    }

  if (pos == -1)
  {
    printf("\nNo se encontro esa temperatura.\n");
    return;
  }

  for (int i = pos; i < *n - 1; i++)
    arr[i] = arr[i + 1];
  (*n)--;
  printf("\nTemperatura eliminada.\n");
}

void estadisticas(int arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay datos para calcular estadisticas.\n");
    return;
  }

  int suma = 0, max = arr[0], min = arr[0];
  for (int i = 0; i < n; i++)
  {
    suma += arr[i];
    if (arr[i] > max)
      max = arr[i];
    if (arr[i] < min)
      min = arr[i];
  }

  printf("\nPromedio: %.2f\n", (float)suma / n);
  printf("Maxima:   %d\n", max);
  printf("Minima:   %d\n", min);
}
