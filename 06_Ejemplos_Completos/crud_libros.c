/*
 * CRUD LIBROS — replica de la consigna del FINAL del 29/07/2025.
 *
 * Struct:  codigo + titulo + autor + precio + stock
 * Menu:    agregar, buscar, listar, eliminar, salir (los 5 requisitos del final)
 *
 * Validaciones del final:
 *   - No permitir codigo duplicado al agregar.
 *   - Validar existencia antes de eliminar.
 *   - Opcion invalida en menu.
 *   - Listar arreglo vacio.
 *
 * Compila:  gcc -Wall crud_libros.c -o crud && ./crud
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

struct Libro
{
  int codigo;
  char titulo[50];
  char autor[30];
  float precio;
  int stock;
};

/* Prototipos */
void listarLibros(struct Libro arr[], int n);
void buscarLibro(struct Libro arr[], int n);
void agregarLibro(struct Libro arr[], int *n);
void eliminarLibro(struct Libro arr[], int *n);

int main()
{
  struct Libro biblioteca[MAX] = {
      {1001, "El Aleph",              "Borges",    5500.00, 12},
      {1002, "Rayuela",                "Cortazar",  6200.00,  8},
      {1003, "Ficciones",              "Borges",    5300.00,  5},
      {1004, "El Tunel",               "Sabato",    4800.00, 10},
      {1005, "Sobre Heroes y Tumbas",  "Sabato",    7800.00,  3}};
  int n = 5;

  int opcion;
  do
  {
    printf("\n=== MENU LIBRERIA ===\n");
    printf("1) Agregar libro\n");
    printf("2) Buscar libro por codigo\n");
    printf("3) Listar libros\n");
    printf("4) Eliminar libro\n");
    printf("5) Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      agregarLibro(biblioteca, &n);
      break;
    case 2:
      buscarLibro(biblioteca, n);
      break;
    case 3:
      listarLibros(biblioteca, n);
      break;
    case 4:
      eliminarLibro(biblioteca, &n);
      break;
    case 5:
      printf("\nSaliendo del sistema...\n");
      break;
    default:
      printf("\nOpcion invalida. Intente nuevamente.\n");
    }
  } while (opcion != 5);

  return 0;
}

void listarLibros(struct Libro arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay libros cargados.\n");
    return;
  }
  printf("\nCOD    TITULO                    AUTOR        PRECIO     STOCK\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-6d %-25s %-12s %-10.2f %d\n",
           arr[i].codigo, arr[i].titulo, arr[i].autor, arr[i].precio, arr[i].stock);
  }
}

void buscarLibro(struct Libro arr[], int n)
{
  int buscado;
  printf("Ingrese codigo del libro: ");
  scanf("%d", &buscado);

  for (int i = 0; i < n; i++)
  {
    if (arr[i].codigo == buscado)
    {
      printf("\nLibro encontrado:\n");
      printf("  Codigo: %d\n", arr[i].codigo);
      printf("  Titulo: %s\n", arr[i].titulo);
      printf("  Autor:  %s\n", arr[i].autor);
      printf("  Precio: %.2f\n", arr[i].precio);
      printf("  Stock:  %d\n", arr[i].stock);
      return;
    }
  }
  printf("No se encontro un libro con ese codigo.\n");
}

void agregarLibro(struct Libro arr[], int *n)
{
  if (*n >= MAX)
  {
    printf("\nNo se pueden agregar mas libros. Limite alcanzado.\n");
    return;
  }

  struct Libro nuevo;
  printf("Codigo: ");
  scanf("%d", &nuevo.codigo);

  /* Validar duplicado */
  for (int i = 0; i < *n; i++)
  {
    if (arr[i].codigo == nuevo.codigo)
    {
      printf("Ya existe un libro con ese codigo.\n");
      return;
    }
  }

  printf("Titulo: ");
  scanf(" %49[^\n]", nuevo.titulo);
  printf("Autor: ");
  scanf(" %29[^\n]", nuevo.autor);
  printf("Precio: ");
  scanf("%f", &nuevo.precio);
  printf("Stock: ");
  scanf("%d", &nuevo.stock);

  arr[*n] = nuevo;
  (*n)++;

  printf("Libro agregado correctamente.\n");
}

void eliminarLibro(struct Libro arr[], int *n)
{
  int codigoEliminar;
  printf("Codigo del libro a eliminar: ");
  scanf("%d", &codigoEliminar);

  int pos = -1;
  for (int i = 0; i < *n; i++)
  {
    if (arr[i].codigo == codigoEliminar)
    {
      pos = i;
      break;
    }
  }

  if (pos == -1)
  {
    printf("No existe un libro con ese codigo.\n");
    return;
  }

  for (int i = pos; i < *n - 1; i++)
    arr[i] = arr[i + 1];
  (*n)--;

  printf("Libro eliminado correctamente.\n");
}
