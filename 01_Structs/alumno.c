/*
 * STRUCT — Alumno
 * Campos: legajo + nombre + notas[3] + promedio
 * Caso de uso: gestion academica, cuando piden CALCULAR PROMEDIO de notas.
 *
 * Truco: el promedio se puede calcular al cargar o al listar.
 * Aca se calcula en main para mostrar el patron.
 */

#include <stdio.h>
#define MAX 100
#define CANT_NOTAS 3

struct Alumno
{
  int legajo;
  char nombre[40];
  float notas[CANT_NOTAS];
  float promedio;
};

int main()
{
  struct Alumno curso[MAX] = {
      {2001, "Lopez Juan",    {7.5, 8.0, 6.5}, 0},
      {2002, "Perez Maria",   {9.0, 9.5, 8.5}, 0},
      {2003, "Garcia Carlos", {6.0, 5.5, 7.0}, 0},
      {2004, "Sanchez Ana",   {10.0, 9.0, 9.5}, 0},
      {2005, "Diaz Pedro",    {4.0, 6.0, 5.0}, 0}};
  int n = 5;

  /* Calcular promedio para cada alumno */
  for (int i = 0; i < n; i++)
  {
    float suma = 0;
    for (int j = 0; j < CANT_NOTAS; j++)
      suma += curso[i].notas[j];
    curso[i].promedio = suma / CANT_NOTAS;
  }

  printf("LEG    NOMBRE              N1   N2   N3   PROM\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-6d %-19s %.1f  %.1f  %.1f  %.2f\n",
           curso[i].legajo,
           curso[i].nombre,
           curso[i].notas[0],
           curso[i].notas[1],
           curso[i].notas[2],
           curso[i].promedio);
  }
  return 0;
}
