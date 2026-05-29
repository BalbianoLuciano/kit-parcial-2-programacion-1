/*
 * MODELO DE PARCIAL 1 — Ordenamiento + Busqueda binaria + doble criterio
 * ----------------------------------------------------------------------
 * Estilo "modelo del 2do parcial": arreglo de structs ya cargado, se ordena
 * con burbuja, se busca con busqueda binaria, y se lista el resultado.
 *
 * Consigna tipo que resuelve:
 *   "Dado un arreglo de empleados, ordenarlos por legajo, buscar un empleado
 *    por su legajo (busqueda binaria) y listar todos. Ademas, mostrar el
 *    listado ordenado por apellido y, a igual apellido, por nombre."
 *
 * Entidad: Empleado (legajo + apellido + nombre + sueldo).
 *
 * Compila: gcc -Wall -Wextra modelo_empleados_orden_busqueda.c -o modelo1 && ./modelo1
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

struct Empleado
{
  int legajo;
  char apellido[30];
  char nombre[30];
  float sueldo;
};

/* === Ordenamiento burbuja por legajo (ascendente) ===
 * IMPRESCINDIBLE para poder usar busqueda binaria despues. */
void ordenarPorLegajo(struct Empleado arr[], int n)
{
  struct Empleado temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j].legajo > arr[j + 1].legajo)
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

/* === Ordenamiento por DOBLE CRITERIO: apellido y desempate por nombre ===
 * A igual apellido, ordena por nombre alfabetico. */
void ordenarPorApellidoYNombre(struct Empleado arr[], int n)
{
  struct Empleado temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      int cmp = strcmp(arr[j].apellido, arr[j + 1].apellido);
      if (cmp > 0 || (cmp == 0 && strcmp(arr[j].nombre, arr[j + 1].nombre) > 0))
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

/* === Busqueda binaria por legajo ===
 * Requiere que el arreglo este ordenado por legajo.
 * Devuelve el indice donde esta, o -1 si no lo encuentra. */
int busquedaBinariaPorLegajo(struct Empleado arr[], int n, int legajoBuscado)
{
  int inicio = 0, fin = n - 1;
  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;
    if (arr[medio].legajo == legajoBuscado)
      return medio;
    if (arr[medio].legajo < legajoBuscado)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }
  return -1;
}

void listar(struct Empleado arr[], int n, const char *titulo)
{
  printf("\n%s\n", titulo);
  printf("  LEGAJO  APELLIDO    NOMBRE      SUELDO\n");
  for (int i = 0; i < n; i++)
    printf("  %-7d %-11s %-11s %.2f\n",
           arr[i].legajo, arr[i].apellido, arr[i].nombre, arr[i].sueldo);
}

int main()
{
  struct Empleado empleados[MAX] = {
      {305, "Acosta",   "Ana",     480000.0},
      {102, "Balbiano", "Luciano", 510000.0},
      {204, "Balbiano", "Marcos",  495000.0},
      {101, "Acosta",   "Carla",   460000.0},
      {103, "Acosta",   "Bruno",   470000.0},
      {250, "Diaz",     "Sofia",   530000.0}};
  int n = 6;

  /* 1) Ordenar por legajo (necesario para la busqueda binaria) */
  ordenarPorLegajo(empleados, n);
  listar(empleados, n, "Empleados ordenados por LEGAJO:");

  /* 2) Buscar un empleado por legajo con busqueda binaria */
  int legajoBuscado = 204;
  int pos = busquedaBinariaPorLegajo(empleados, n, legajoBuscado);
  printf("\nBuscando legajo %d...\n", legajoBuscado);
  if (pos != -1)
    printf("  Encontrado: %s %s (sueldo %.2f)\n",
           empleados[pos].apellido, empleados[pos].nombre, empleados[pos].sueldo);
  else
    printf("  No se encontro el legajo %d.\n", legajoBuscado);

  /* 3) Listado por doble criterio: apellido y, a igual apellido, nombre */
  ordenarPorApellidoYNombre(empleados, n);
  listar(empleados, n, "Empleados ordenados por APELLIDO y NOMBRE:");

  return 0;
}
