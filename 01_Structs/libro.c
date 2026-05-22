/*
 * STRUCT — Libro
 * Campos: codigo + titulo + autor + precio + stock
 * Caso de uso: librerias, bibliotecas (= consigna del final 29/07/2025).
 */

#include <stdio.h>
#define MAX 100

struct Libro
{
  int codigo;
  char titulo[50];
  char autor[30];
  float precio;
  int stock;
};

int main()
{
  struct Libro biblioteca[MAX] = {
      {1001, "El Aleph", "Borges", 5500.00, 12},
      {1002, "Rayuela", "Cortazar", 6200.00, 8},
      {1003, "Ficciones", "Borges", 5300.00, 5},
      {1004, "El Tunel", "Sabato", 4800.00, 10},
      {1005, "Sobre Heroes y Tumbas", "Sabato", 7800.00, 3}};
  int n = 5;

  printf("COD    TITULO                    AUTOR        PRECIO    STOCK\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-6d %-25s %-12s %-9.2f %d\n",
           biblioteca[i].codigo,
           biblioteca[i].titulo,
           biblioteca[i].autor,
           biblioteca[i].precio,
           biblioteca[i].stock);
  }
  return 0;
}
