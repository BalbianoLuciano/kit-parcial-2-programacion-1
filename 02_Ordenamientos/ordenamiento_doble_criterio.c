/*
 * ORDENAMIENTO POR DOBLE CRITERIO (criterio primario + desempate)
 * ---------------------------------------------------------------
 * Ordena por un criterio PRIMARIO y, cuando dos elementos empatan en ese
 * criterio, los desempata por un criterio SECUNDARIO.
 *
 * Ejemplo de salida (ordenar por apellido y, a igual apellido, por nombre):
 *
 *     Acosta   Ana
 *     Acosta   Bruno
 *     Acosta   Carla
 *     Balbiano Luciano
 *     Balbiano Marcos
 *
 * Es lo que piden cuando dicen:
 *   - "ordenar por apellido y nombre"
 *   - "ordenar por apellido y, a igual apellido, por legajo"
 *   - "alfabetico y si se repite, por numero"
 *
 * CLAVE DEL DOBLE CRITERIO (en el if del comparador):
 *   1) Comparo el criterio primario.
 *   2) Si el primario es MAYOR -> intercambio.
 *   3) Si el primario es IGUAL (empate) -> recien ahi comparo el secundario.
 *
 * Compila: gcc -Wall -Wextra ordenamiento_doble_criterio.c -o doble && ./doble
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

struct Persona
{
  char apellido[30];
  char nombre[30];
  int legajo;
};

/* === Variante 1: por APELLIDO (string) y desempate por NOMBRE (string) ===
 *
 * strcmp(a, b)  devuelve:
 *    < 0  si a va ANTES que b alfabeticamente
 *      0  si a y b son iguales   <-- empate, paso al segundo criterio
 *    > 0  si a va DESPUES que b
 */
void ordenarPorApellidoYNombre(struct Persona arr[], int n)
{
  struct Persona temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      int cmpApellido = strcmp(arr[j].apellido, arr[j + 1].apellido);

      /* Intercambio si:
       *   - el apellido de j va despues (cmpApellido > 0), O
       *   - los apellidos son iguales Y el nombre de j va despues */
      if (cmpApellido > 0 ||
          (cmpApellido == 0 && strcmp(arr[j].nombre, arr[j + 1].nombre) > 0))
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

/* === Variante 2: por APELLIDO (string) y desempate por LEGAJO (entero) ===
 *
 * Mismo patron, pero el segundo criterio es numerico:
 * a igual apellido, gana el legajo mas chico (ascendente). */
void ordenarPorApellidoYLegajo(struct Persona arr[], int n)
{
  struct Persona temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      int cmpApellido = strcmp(arr[j].apellido, arr[j + 1].apellido);

      if (cmpApellido > 0 ||
          (cmpApellido == 0 && arr[j].legajo > arr[j + 1].legajo))
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void imprimir(struct Persona arr[], int n, const char *etiqueta)
{
  printf("\n--- %s ---\n", etiqueta);
  for (int i = 0; i < n; i++)
    printf("  %-10s %-10s legajo %d\n", arr[i].apellido, arr[i].nombre, arr[i].legajo);
}

int main()
{
  struct Persona personas[MAX] = {
      {"Balbiano", "Marcos",  204},
      {"Acosta",   "Carla",   101},
      {"Balbiano", "Luciano", 102},
      {"Acosta",   "Ana",     305},
      {"Acosta",   "Bruno",   103}};
  int n = 5;

  imprimir(personas, n, "Original (desordenado)");

  ordenarPorApellidoYNombre(personas, n);
  imprimir(personas, n, "Por apellido y, a igual apellido, por nombre");

  ordenarPorApellidoYLegajo(personas, n);
  imprimir(personas, n, "Por apellido y, a igual apellido, por legajo");

  return 0;
}
