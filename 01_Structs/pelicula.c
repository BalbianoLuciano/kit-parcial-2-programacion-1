/*
 * STRUCT — Pelicula
 * Campos: codigo + titulo + director + anio + duracion
 * Caso de uso: catalogos multimedia (peliculas, canciones, series, libros).
 *
 * Para canciones: titulo -> nombreCancion, director -> artista, duracion -> minutos.
 * Para series: agregar campo temporadas.
 */

#include <stdio.h>
#define MAX 100

struct Pelicula
{
  int codigo;
  char titulo[50];
  char director[40];
  int anio;
  int duracion; /* en minutos */
};

int main()
{
  struct Pelicula catalogo[MAX] = {
      {501, "Pulp Fiction",         "Tarantino",   1994, 154},
      {502, "El Padrino",           "Coppola",     1972, 175},
      {503, "Forrest Gump",         "Zemeckis",    1994, 142},
      {504, "Matrix",               "Wachowski",   1999, 136},
      {505, "El Secreto de sus Ojos","Campanella", 2009, 129}};
  int n = 5;

  printf("COD   TITULO                       DIRECTOR        ANIO  DUR\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-5d %-28s %-15s %-5d %d\n",
           catalogo[i].codigo,
           catalogo[i].titulo,
           catalogo[i].director,
           catalogo[i].anio,
           catalogo[i].duracion);
  }
  return 0;
}
