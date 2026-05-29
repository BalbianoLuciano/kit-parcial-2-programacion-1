/*
 * MODELO DE PARCIAL 2 — CRUD completo con menu interactivo
 * --------------------------------------------------------
 * Estilo "modelo del 2do parcial": sistema con menu (do-while + switch) que
 * gestiona registros de una entidad con las 5 operaciones clasicas.
 *
 * Consigna tipo que resuelve:
 *   "Realizar un programa que administre canciones (codigo, titulo, artista,
 *    duracion). El sistema debe permitir listar, buscar, agregar, eliminar y
 *    modificar canciones mediante un menu. Mantener el arreglo ordenado por
 *    codigo y buscar con busqueda binaria."
 *
 * Incluye TODAS las validaciones del checklist (no duplicar, validar existencia,
 * arreglo lleno, arreglo vacio, opcion invalida).
 * A diferencia del modelo original del curso, aca MODIFICAR esta implementado.
 *
 * Compila: gcc -Wall -Wextra modelo_canciones_crud.c -o modelo2 && ./modelo2
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

struct Cancion
{
  int codigo;
  char titulo[40];
  char artista[30];
  int duracion; /* en segundos */
};

/* === Prototipos === */
void ordenarPorCodigo(struct Cancion arr[], int n);
void listar(struct Cancion arr[], int n);
int busquedaBinaria(struct Cancion arr[], int n, int codigoBuscado);
void buscar(struct Cancion arr[], int n);
void agregar(struct Cancion arr[], int *n);
void eliminar(struct Cancion arr[], int *n);
void modificar(struct Cancion arr[], int n);

int main()
{
  struct Cancion lista[MAX] = {
      {305, "Bohemian Rhapsody", "Queen",        354},
      {102, "Imagine",           "Lennon",       183},
      {204, "Hotel California",  "Eagles",       390},
      {101, "De Musica Ligera",  "Soda Stereo",  217},
      {103, "Smells Like...",    "Nirvana",      301}};
  int n = 5;

  ordenarPorCodigo(lista, n); /* arrancamos ordenados para la busqueda binaria */

  int opcion;
  do
  {
    printf("\n=== GESTOR DE CANCIONES ===\n");
    printf("1) Listar\n");
    printf("2) Buscar por codigo\n");
    printf("3) Agregar\n");
    printf("4) Eliminar\n");
    printf("5) Modificar\n");
    printf("6) Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      listar(lista, n);
      break;
    case 2:
      buscar(lista, n);
      break;
    case 3:
      agregar(lista, &n);
      break;
    case 4:
      eliminar(lista, &n);
      break;
    case 5:
      modificar(lista, n);
      break;
    case 6:
      printf("\nSaliendo...\n");
      break;
    default:
      printf("\nOpcion invalida. Intente nuevamente.\n");
    }
  } while (opcion != 6);

  return 0;
}

/* === Implementaciones === */

void ordenarPorCodigo(struct Cancion arr[], int n)
{
  struct Cancion temp;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      if (arr[j].codigo > arr[j + 1].codigo)
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}

void listar(struct Cancion arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay canciones cargadas.\n");
    return;
  }
  printf("\n  CODIGO  TITULO                     ARTISTA         DURACION\n");
  for (int i = 0; i < n; i++)
    printf("  %-7d %-26s %-15s %d:%02d\n",
           arr[i].codigo, arr[i].titulo, arr[i].artista,
           arr[i].duracion / 60, arr[i].duracion % 60);
}

/* Devuelve el indice donde esta el codigo, o -1 si no existe.
   Requiere arreglo ordenado por codigo. */
int busquedaBinaria(struct Cancion arr[], int n, int codigoBuscado)
{
  int inicio = 0, fin = n - 1;
  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;
    if (arr[medio].codigo == codigoBuscado)
      return medio;
    if (arr[medio].codigo < codigoBuscado)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }
  return -1;
}

void buscar(struct Cancion arr[], int n)
{
  int codigo;
  printf("Ingrese codigo a buscar: ");
  scanf("%d", &codigo);

  int pos = busquedaBinaria(arr, n, codigo);
  if (pos == -1)
  {
    printf("\nNo se encontro una cancion con codigo %d.\n", codigo);
    return;
  }
  printf("\nEncontrada:\n");
  printf("  Codigo:   %d\n", arr[pos].codigo);
  printf("  Titulo:   %s\n", arr[pos].titulo);
  printf("  Artista:  %s\n", arr[pos].artista);
  printf("  Duracion: %d:%02d\n", arr[pos].duracion / 60, arr[pos].duracion % 60);
}

void agregar(struct Cancion arr[], int *n)
{
  if (*n >= MAX)
  {
    printf("\nNo se pueden agregar mas canciones (lista llena).\n");
    return;
  }

  struct Cancion nueva;
  printf("Ingrese codigo: ");
  scanf("%d", &nueva.codigo);

  /* Validacion: no permitir codigo duplicado */
  if (busquedaBinaria(arr, *n, nueva.codigo) != -1)
  {
    printf("\nYa existe una cancion con ese codigo.\n");
    return;
  }

  printf("Ingrese titulo: ");
  scanf(" %39[^\n]", nueva.titulo);
  printf("Ingrese artista: ");
  scanf(" %29[^\n]", nueva.artista);
  printf("Ingrese duracion (en segundos): ");
  scanf("%d", &nueva.duracion);

  arr[*n] = nueva;
  (*n)++;

  ordenarPorCodigo(arr, *n); /* mantener orden para la busqueda binaria */
  printf("\nCancion agregada correctamente.\n");
}

void eliminar(struct Cancion arr[], int *n)
{
  int codigo;
  printf("Ingrese codigo a eliminar: ");
  scanf("%d", &codigo);

  int pos = busquedaBinaria(arr, *n, codigo);
  if (pos == -1)
  {
    printf("\nNo existe una cancion con codigo %d.\n", codigo);
    return;
  }

  /* Shift: corro todos los elementos una posicion a la izquierda */
  for (int i = pos; i < *n - 1; i++)
    arr[i] = arr[i + 1];
  (*n)--;

  printf("\nCancion eliminada correctamente.\n");
}

void modificar(struct Cancion arr[], int n)
{
  int codigo;
  printf("Ingrese codigo a modificar: ");
  scanf("%d", &codigo);

  int pos = busquedaBinaria(arr, n, codigo);
  if (pos == -1)
  {
    printf("\nNo existe una cancion con codigo %d.\n", codigo);
    return;
  }

  /* No cambiamos el codigo (es la clave) para no romper el orden. */
  printf("Nuevo titulo: ");
  scanf(" %39[^\n]", arr[pos].titulo);
  printf("Nuevo artista: ");
  scanf(" %29[^\n]", arr[pos].artista);
  printf("Nueva duracion (segundos): ");
  scanf("%d", &arr[pos].duracion);

  printf("\nCancion modificada correctamente.\n");
}
