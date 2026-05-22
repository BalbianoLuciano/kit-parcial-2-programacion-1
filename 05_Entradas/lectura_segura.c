/*
 * LECTURA SEGURA — enteros, floats y strings con espacios.
 *
 * Demuestra las 3 formas que mas se usan en el parcial:
 *
 *   1) scanf("%d", &x)          — para enteros
 *   2) scanf(" %49[^\n]", str)  — para strings con espacios (estilo modelo del parcial)
 *   3) fgets() + strcspn()      — alternativa mas robusta
 *
 * Tambien muestra como limpiar el buffer entre lecturas mixtas.
 */

#include <stdio.h>
#include <string.h>
#define TAM 50

int main()
{
  int edad;
  float altura;
  char nombre[TAM];
  char direccion[TAM];

  /* === 1) Entero === */
  printf("Edad: ");
  scanf("%d", &edad);

  /* === 2) Float === */
  printf("Altura: ");
  scanf("%f", &altura);

  /* === 3) String con espacios estilo modelo del parcial ===
     El espacio antes de %... es CLAVE para que ignore el \n que dejo el scanf anterior. */
  printf("Nombre completo: ");
  scanf(" %49[^\n]", nombre);

  /* === 4) String con fgets + strcspn ===
     fgets se come el \n que queda en buffer del scanf anterior si no limpiamos. */
  getchar(); /* limpia el \n que dejo el scanf de nombre */
  printf("Direccion: ");
  fgets(direccion, TAM, stdin);
  direccion[strcspn(direccion, "\n")] = '\0'; /* quita el \n final */

  printf("\n--- Datos cargados ---\n");
  printf("Edad: %d\n", edad);
  printf("Altura: %.2f\n", altura);
  printf("Nombre: %s\n", nombre);
  printf("Direccion: %s\n", direccion);

  return 0;
}
