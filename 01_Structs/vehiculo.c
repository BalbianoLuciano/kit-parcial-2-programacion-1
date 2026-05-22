/*
 * STRUCT — Vehiculo
 * Campos: patente (STRING) + marca + modelo + anio + precio
 * Caso de uso: concesionarias, agencias, parking.
 *
 * OJO: la patente es STRING. Si buscas por patente, usar strcmp() (no ==).
 * Si lo prefieres, podes usar la patente como "ID" string en vez de codigo entero.
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

struct Vehiculo
{
  char patente[10];
  char marca[20];
  char modelo[20];
  int anio;
  float precio;
};

int main()
{
  struct Vehiculo flota[MAX] = {
      {"AB123CD", "Toyota",     "Corolla",   2020, 15000000.00},
      {"AC456EF", "Ford",       "Focus",     2018, 11500000.00},
      {"AD789GH", "Volkswagen", "Gol",       2022, 12800000.00},
      {"AE012IJ", "Chevrolet",  "Onix",      2021, 13500000.00},
      {"AF345KL", "Fiat",       "Cronos",    2023, 14200000.00}};
  int n = 5;

  printf("PATENTE   MARCA        MODELO      ANIO   PRECIO\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-9s %-12s %-11s %-6d %.2f\n",
           flota[i].patente,
           flota[i].marca,
           flota[i].modelo,
           flota[i].anio,
           flota[i].precio);
  }
  return 0;
}
