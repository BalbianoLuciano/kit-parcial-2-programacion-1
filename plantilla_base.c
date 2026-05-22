/*
 * PLANTILLA BASE — Programa CRUD completo con menu
 * --------------------------------------------------
 * Usar este archivo como punto de partida para cualquier consigna del estilo
 * "gestionar registros de X". Esta es la version generica.
 *
 * Como adaptarlo:
 *   1) Cambiar el nombre del struct y sus campos (ver 01_Structs/ para modelos).
 *   2) Cambiar los datos del arreglo inicial (o vaciarlo y cargar todo por menu).
 *   3) Ajustar listarRegistros() para imprimir los campos correctos.
 *   4) Ajustar buscar/agregar/modificar/eliminar para usar los campos del struct.
 *   5) Si te piden ordenar por nombre, cambiar la comparacion ">" por strcmp().
 *
 * Compila: gcc -Wall plantilla_base.c -o plantilla && ./plantilla
 */

#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 100
#define TAM_NOMBRE 50

/* === STRUCT — CAMBIAR aca segun la entidad que pida la consigna === */
struct Registro
{
  int id;                    // CAMBIAR: codigo / legajo / dni / patente
  char nombre[TAM_NOMBRE];   // CAMBIAR: titulo / apellido / marca
  float valor;               // CAMBIAR: precio / sueldo / nota
  int cantidad;              // OPCIONAL: stock / edad / antiguedad. Eliminar si no aplica.
};

/* === Prototipos === */
void listarRegistros(struct Registro arr[], int n);
struct Registro buscarRegistro(struct Registro arr[], int n);
void agregarRegistro(struct Registro arr[], int *n);
void eliminarRegistro(struct Registro arr[], int *n);
void modificarRegistro(struct Registro arr[], int n);
void ordenarPorId(struct Registro arr[], int n);

int main()
{
  /* Arreglo inicial — opcional. Si la consigna pide cargar todo por menu, dejar vacio con n=0. */
  struct Registro registros[MAX_REGISTROS] = {
      {101, "Ejemplo A", 100.00, 5},
      {102, "Ejemplo B", 200.00, 3},
      {103, "Ejemplo C", 150.00, 8}};
  int n = 3;

  /* Ordenamiento inicial — opcional */
  ordenarPorId(registros, n);

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
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      listarRegistros(registros, n);
      break;
    case 2:
    {
      struct Registro r = buscarRegistro(registros, n);
      if (r.id != 0)
      {
        printf("\nEncontrado:\n");
        printf("  ID: %d\n", r.id);
        printf("  Nombre: %s\n", r.nombre);
        printf("  Valor: %.2f\n", r.valor);
        printf("  Cantidad: %d\n", r.cantidad);
      }
      else
      {
        printf("\nNo se encontro el registro.\n");
      }
      break;
    }
    case 3:
      agregarRegistro(registros, &n);
      break;
    case 4:
      eliminarRegistro(registros, &n);
      break;
    case 5:
      modificarRegistro(registros, n);
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

void listarRegistros(struct Registro arr[], int n)
{
  if (n == 0)
  {
    printf("\nNo hay registros cargados.\n");
    return;
  }
  printf("\n#  ID     NOMBRE                VALOR    CANT\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d  %-6d %-20s %-8.2f %d\n",
           i + 1, arr[i].id, arr[i].nombre, arr[i].valor, arr[i].cantidad);
  }
}

/* Busqueda binaria — requiere arreglo ordenado por id.
   Si el arreglo no esta ordenado, usar busqueda lineal (ver 03_Busquedas/). */
struct Registro buscarRegistro(struct Registro arr[], int n)
{
  int buscado;
  printf("Ingrese ID a buscar: ");
  scanf("%d", &buscado);

  int inicio = 0, fin = n - 1;
  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;
    if (arr[medio].id == buscado)
      return arr[medio];
    if (arr[medio].id < buscado)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }
  /* Devuelve un registro vacio si no encontro */
  struct Registro vacio = {0, "", 0.0, 0};
  return vacio;
}

void agregarRegistro(struct Registro arr[], int *n)
{
  if (*n >= MAX_REGISTROS)
  {
    printf("\nNo se pueden agregar mas registros. Limite alcanzado.\n");
    return;
  }

  struct Registro nuevo;
  printf("Ingrese ID: ");
  scanf("%d", &nuevo.id);

  /* Validacion: no permitir ID duplicado */
  for (int i = 0; i < *n; i++)
  {
    if (arr[i].id == nuevo.id)
    {
      printf("\nYa existe un registro con ese ID.\n");
      return;
    }
  }

  printf("Ingrese nombre: ");
  scanf(" %49[^\n]", nuevo.nombre);
  printf("Ingrese valor: ");
  scanf("%f", &nuevo.valor);
  printf("Ingrese cantidad: ");
  scanf("%d", &nuevo.cantidad);

  arr[*n] = nuevo;
  (*n)++;

  /* Mantener orden tras agregar */
  ordenarPorId(arr, *n);

  printf("\nRegistro agregado correctamente.\n");
}

void eliminarRegistro(struct Registro arr[], int *n)
{
  int idEliminar;
  printf("Ingrese ID a eliminar: ");
  scanf("%d", &idEliminar);

  int pos = -1;
  for (int i = 0; i < *n; i++)
  {
    if (arr[i].id == idEliminar)
    {
      pos = i;
      break;
    }
  }

  if (pos == -1)
  {
    printf("\nNo existe registro con ese ID.\n");
    return;
  }

  /* Shift de elementos */
  for (int i = pos; i < *n - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  (*n)--;

  printf("\nRegistro eliminado correctamente.\n");
}

void modificarRegistro(struct Registro arr[], int n)
{
  int idModificar;
  printf("Ingrese ID a modificar: ");
  scanf("%d", &idModificar);

  int pos = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].id == idModificar)
    {
      pos = i;
      break;
    }
  }

  if (pos == -1)
  {
    printf("\nNo existe registro con ese ID.\n");
    return;
  }

  printf("Nuevo nombre: ");
  scanf(" %49[^\n]", arr[pos].nombre);
  printf("Nuevo valor: ");
  scanf("%f", &arr[pos].valor);
  printf("Nueva cantidad: ");
  scanf("%d", &arr[pos].cantidad);

  printf("\nRegistro modificado correctamente.\n");
}

/* Burbuja por ID ascendente.
   Si te piden ordenar por otro campo: cambiar arr[j].id por el campo deseado.
   Si te piden ordenar por nombre: usar strcmp(arr[j].nombre, arr[j+1].nombre) > 0 */
void ordenarPorId(struct Registro arr[], int n)
{
  struct Registro temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j].id > arr[j + 1].id)
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
