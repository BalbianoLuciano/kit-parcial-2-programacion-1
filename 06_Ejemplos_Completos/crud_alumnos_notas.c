/*
 * CRUD ALUMNOS CON NOTAS — variante con CALCULO DE PROMEDIO.
 *
 * Struct:  legajo + nombre + notas[3] + promedio
 * Menu:    listar, buscar, agregar, eliminar, modificar, listar por promedio, salir
 *
 * Diferencias vs los otros CRUDs:
 *   - Hay un arreglo INTERNO al struct (notas[]).
 *   - El promedio se calcula al cargar / modificar.
 *   - Opcion extra: listar ordenado por promedio descendente.
 *
 * Compila:  gcc -Wall crud_alumnos_notas.c -o crud && ./crud
 */

#include <stdio.h>
#include <string.h>
#define MAX 100
#define CANT_NOTAS 3

struct Alumno
{
  int legajo;
  char nombre[40];
  float notas[CANT_NOTAS];
  float promedio;
};

/* Prototipos */
void listarAlumnos(struct Alumno arr[], int n);
void listarPorPromedio(struct Alumno arr[], int n);
void buscarAlumno(struct Alumno arr[], int n);
void agregarAlumno(struct Alumno arr[], int *n);
void eliminarAlumno(struct Alumno arr[], int *n);
void modificarNotas(struct Alumno arr[], int n);
float calcularPromedio(float notas[]);

int main()
{
  struct Alumno curso[MAX] = {
      {2001, "Lopez Juan",    {7.5, 8.0, 6.5}, 0},
      {2002, "Perez Maria",   {9.0, 9.5, 8.5}, 0},
      {2003, "Garcia Carlos", {6.0, 5.5, 7.0}, 0},
      {2004, "Sanchez Ana",   {10.0, 9.0, 9.5}, 0},
      {2005, "Diaz Pedro",    {4.0, 6.0, 5.0}, 0}};
  int n = 5;

  /* Inicializar promedios al cargar */
  for (int i = 0; i < n; i++)
    curso[i].promedio = calcularPromedio(curso[i].notas);

  int opcion;
  do
  {
    printf("\n=== MENU ALUMNOS ===\n");
    printf("1) Listar\n");
    printf("2) Buscar\n");
    printf("3) Agregar\n");
    printf("4) Eliminar\n");
    printf("5) Modificar notas\n");
    printf("6) Listar por promedio (mayor a menor)\n");
    printf("7) Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      listarAlumnos(curso, n);
      break;
    case 2:
      buscarAlumno(curso, n);
      break;
    case 3:
      agregarAlumno(curso, &n);
      break;
    case 4:
      eliminarAlumno(curso, &n);
      break;
    case 5:
      modificarNotas(curso, n);
      break;
    case 6:
      listarPorPromedio(curso, n);
      break;
    case 7:
      printf("\nSaliendo...\n");
      break;
    default:
      printf("\nOpcion invalida. Intente nuevamente.\n");
    }
  } while (opcion != 7);

  return 0;
}

float calcularPromedio(float notas[])
{
  float suma = 0;
  for (int i = 0; i < CANT_NOTAS; i++)
    suma += notas[i];
  return suma / CANT_NOTAS;
}

void listarAlumnos(struct Alumno arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay alumnos cargados.\n");
    return;
  }
  printf("\nLEG    NOMBRE              N1   N2   N3   PROM\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-6d %-19s %.1f  %.1f  %.1f  %.2f\n",
           arr[i].legajo, arr[i].nombre,
           arr[i].notas[0], arr[i].notas[1], arr[i].notas[2],
           arr[i].promedio);
  }
}

/* Lista ordenada por promedio descendente — sin alterar el arreglo original */
void listarPorPromedio(struct Alumno arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay alumnos cargados.\n");
    return;
  }

  /* Copia local para no romper el orden original */
  struct Alumno copia[MAX];
  for (int i = 0; i < n; i++)
    copia[i] = arr[i];

  /* Burbuja descendente por promedio */
  struct Alumno temp;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      if (copia[j].promedio < copia[j + 1].promedio)
      {
        temp = copia[j];
        copia[j] = copia[j + 1];
        copia[j + 1] = temp;
      }

  printf("\nRANK  LEG    NOMBRE              PROM\n");
  for (int i = 0; i < n; i++)
    printf("%-5d %-6d %-19s %.2f\n", i + 1, copia[i].legajo, copia[i].nombre, copia[i].promedio);
}

void buscarAlumno(struct Alumno arr[], int n)
{
  int buscado;
  printf("Ingrese legajo: ");
  scanf("%d", &buscado);

  for (int i = 0; i < n; i++)
  {
    if (arr[i].legajo == buscado)
    {
      printf("\nAlumno encontrado:\n");
      printf("  Legajo:   %d\n", arr[i].legajo);
      printf("  Nombre:   %s\n", arr[i].nombre);
      printf("  Notas:    %.1f, %.1f, %.1f\n",
             arr[i].notas[0], arr[i].notas[1], arr[i].notas[2]);
      printf("  Promedio: %.2f\n", arr[i].promedio);
      return;
    }
  }
  printf("No se encontro un alumno con ese legajo.\n");
}

void agregarAlumno(struct Alumno arr[], int *n)
{
  if (*n >= MAX)
  {
    printf("\nNo se pueden agregar mas alumnos.\n");
    return;
  }

  struct Alumno nuevo;
  printf("Legajo: ");
  scanf("%d", &nuevo.legajo);

  /* Validar duplicado */
  for (int i = 0; i < *n; i++)
  {
    if (arr[i].legajo == nuevo.legajo)
    {
      printf("Ya existe un alumno con ese legajo.\n");
      return;
    }
  }

  printf("Nombre: ");
  scanf(" %39[^\n]", nuevo.nombre);
  for (int j = 0; j < CANT_NOTAS; j++)
  {
    printf("Nota %d: ", j + 1);
    scanf("%f", &nuevo.notas[j]);
  }
  nuevo.promedio = calcularPromedio(nuevo.notas);

  arr[*n] = nuevo;
  (*n)++;

  printf("Alumno agregado. Promedio: %.2f\n", nuevo.promedio);
}

void eliminarAlumno(struct Alumno arr[], int *n)
{
  int legajoEliminar;
  printf("Legajo a eliminar: ");
  scanf("%d", &legajoEliminar);

  int pos = -1;
  for (int i = 0; i < *n; i++)
  {
    if (arr[i].legajo == legajoEliminar)
    {
      pos = i;
      break;
    }
  }

  if (pos == -1)
  {
    printf("No existe un alumno con ese legajo.\n");
    return;
  }

  for (int i = pos; i < *n - 1; i++)
    arr[i] = arr[i + 1];
  (*n)--;

  printf("Alumno eliminado correctamente.\n");
}

void modificarNotas(struct Alumno arr[], int n)
{
  int legajoModificar;
  printf("Legajo a modificar: ");
  scanf("%d", &legajoModificar);

  int pos = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].legajo == legajoModificar)
    {
      pos = i;
      break;
    }
  }

  if (pos == -1)
  {
    printf("No existe un alumno con ese legajo.\n");
    return;
  }

  for (int j = 0; j < CANT_NOTAS; j++)
  {
    printf("Nueva nota %d: ", j + 1);
    scanf("%f", &arr[pos].notas[j]);
  }
  arr[pos].promedio = calcularPromedio(arr[pos].notas);

  printf("Notas modificadas. Nuevo promedio: %.2f\n", arr[pos].promedio);
}
