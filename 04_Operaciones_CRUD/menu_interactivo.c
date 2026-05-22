/*
 * MENU INTERACTIVO — esqueleto do-while + switch
 *
 * Es la estructura de control que envuelve a TODO el programa CRUD del parcial.
 * Validaciones incluidas:
 *   - opcion invalida (default del switch)
 *   - salida limpia con opcion 6
 */

#include <stdio.h>

int main()
{
  int opcion;

  do
  {
    printf("\n=== MENU ===\n");
    printf("1) Listar\n");
    printf("2) Buscar\n");
    printf("3) Agregar\n");
    printf("4) Eliminar\n");
    printf("5) Modificar\n");
    printf("6) Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      printf("\n>> Listar (llamar a listar())\n");
      break;
    case 2:
      printf("\n>> Buscar (llamar a buscar())\n");
      break;
    case 3:
      printf("\n>> Agregar (llamar a agregar())\n");
      break;
    case 4:
      printf("\n>> Eliminar (llamar a eliminar())\n");
      break;
    case 5:
      printf("\n>> Modificar (llamar a modificar())\n");
      break;
    case 6:
      printf("\nSaliendo del programa...\n");
      break;
    default:
      printf("\nOpcion invalida. Intente nuevamente.\n");
    }
  } while (opcion != 6);

  return 0;
}
