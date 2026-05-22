/*
 * STRUCT — Empleado
 * Campos: dni + nombre + sueldo + antiguedad
 * Caso de uso: nominas, RRHH, cuando piden CALCULOS sobre sueldo (aumentos, totales).
 */

#include <stdio.h>
#define MAX 100

struct Empleado
{
  int dni;
  char nombre[40];
  float sueldo;
  int antiguedad; /* en anios */
};

int main()
{
  struct Empleado plantel[MAX] = {
      {30123456, "Alvarez Lucia",   850000.00, 5},
      {28456789, "Martinez Diego",  920000.00, 8},
      {35987654, "Romero Sofia",    720000.00, 2},
      {26789012, "Fernandez Hugo", 1100000.00, 15},
      {32654321, "Gomez Laura",     890000.00, 7}};
  int n = 5;

  printf("DNI         NOMBRE             SUELDO       ANT\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-11d %-18s %-12.2f %d\n",
           plantel[i].dni,
           plantel[i].nombre,
           plantel[i].sueldo,
           plantel[i].antiguedad);
  }
  return 0;
}
