/*
 * STRUCT — Persona
 * Campos: dni + nombre + edad
 * Caso de uso: contactos, clientes, agendas, padron.
 * Es el struct mas chico y simple — usar cuando la consigna es minimalista.
 */

#include <stdio.h>
#define MAX 100

struct Persona
{
  int dni;
  char nombre[40];
  int edad;
};

int main()
{
  struct Persona contactos[MAX] = {
      {30111222, "Juan Lopez",     28},
      {25333444, "Maria Perez",    35},
      {40555666, "Carlos Garcia",  19},
      {28777888, "Ana Sanchez",    32},
      {35999000, "Pedro Diaz",     24}};
  int n = 5;

  printf("DNI         NOMBRE             EDAD\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-11d %-18s %d\n",
           contactos[i].dni,
           contactos[i].nombre,
           contactos[i].edad);
  }
  return 0;
}
