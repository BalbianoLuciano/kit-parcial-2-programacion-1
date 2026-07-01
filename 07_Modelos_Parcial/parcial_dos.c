#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pieza
{
  int posicion[2]; // posicion[0] = fila, posicion[1] = columna
  char tipo[20];   // peon, torre, caballo, alfil, reina, rey
  char color;      // 'b' para blanco, 'n' para negro
  int valor;
  int activa; // 1 si esta en juego, 0 si fue capturada
};

// Prototipos
void ordenarPiezas(struct Pieza piezas[], int cantidad);
void restaurarPieza(struct Pieza piezas[], int cantidad, int fila, int columna);
void mostrarEstadisticas(struct Pieza piezas[], int cantidad);
void agregarPieza(struct Pieza piezas[], int *cantidad, struct Pieza nuevaPieza);
char *seleccionarTipoDePieza(int numeroPieza);
int obtenerValorDePieza(int numeroPieza);
void mostrarMenu();

// HELPERS HELPERS HELPERS HELPERS
// HELPERS HELPERS HELPERS HELPERS

void burbujaHelper(struct Pieza piezas[], int cantidad)
{
  struct Pieza temp;
  for (int i = 0; i < cantidad - 1; i++)
  {
    for (int j = 0; j < cantidad - 1 - i; j++)
    {
      if (piezas[j].valor < piezas[j + 1].valor)
      {
        temp = piezas[j];
        piezas[j] = piezas[j + 1];
        piezas[j + 1] = temp;
      }
    }
  }
}

void mostrarPiezaCompleta(struct Pieza pieza)
{
  printf("Posicion: [%d, %d] Tipo: %s, Color: %c, Valor: %d",
         pieza.posicion[0], pieza.posicion[1], pieza.tipo, pieza.color, pieza.valor);
}

// HELPERS HELPERS HELPERS HELPERS
// HELPERS HELPERS HELPERS HELPERS

// En base al programa publicado en el repositorio https://github.com/facundouferer/cursodec/blob/main/Parciales/Parcial02/segundoParcialAjedrez.c desarrolle la función Listar Piezas por Valor.
// La función debe ordenar las piezas de mayor a menor valor y luego mostrarlas por pantalla.
// Para que el programa funcione perfectamente debe existir ésta función y no alterar el código fuera de la función.
void listarPiezasPorValor(struct Pieza piezas[], int cantidad)
{

  burbujaHelper(piezas, cantidad);
  for (int i = 0; i < cantidad; i++)
  {
    mostrarPiezaCompleta(piezas[i]);
  }
}

// En base al programa publicado en el repositorio https://github.com/facundouferer/cursodec/blob/main/Parciales/Parcial02/segundoParcialAjedrez.c desarrolle la función Listar Piezas Por Posición.
// La función debe listar las piezas ordenadas primero por fila y luego por columna.
// Para que el programa funcione perfectamente debe existir ésta función y no alterar el código fuera de la función.

void listarPiezasPorPosicion(struct Pieza piezas[], int cantidad)
{
  struct Pieza temp;
  for (int i = 0; i < cantidad - 1; i++)
  {
    for (int j = 0; j < cantidad - 1 - i; j++)
    {
      int cmp = strcmp(piezas[j].tipo, piezas[j + 1].tipo);
      if (cmp > 0 || (cmp == 0 && piezas[j].posicion[0] > piezas[j + 1].posicion[0]))
      {
        temp = piezas[j];
        piezas[j] = piezas[j + 1];
        piezas[j + 1] = temp;
      }
    }
  }
}

// En base al programa publicado en el repositorio https://github.com/facundouferer/cursodec/blob/main/Parciales/Parcial02/segundoParcialAjedrez.c desarrolle la función Listar Piezas Activas.
// La función debe mostrar solamente las piezas que continúan activas en el tablero.
// Para que el programa funcione perfectamente debe existir ésta función y no alterar el código fuera de la función.

void listarPiezasActivas(struct Pieza piezas[], int cantidad)
{
  for (int i = 0; i < cantidad; i++)
  {
    if (piezas[i].activa == 1)
    {
      mostrarPiezaCompleta(piezas[i]);
    }
  }
}

// En base al programa publicado en el repositorio https://github.com/facundouferer/cursodec/blob/main/Parciales/Parcial02/segundoParcialAjedrez.c desarrolle la función Capturar Pieza.
// La función debe buscar una pieza por su posición (fila, columna) y marcarla como capturada cambiando el campo activa a 0.
// Para que el programa funcione perfectamente debe existir ésta función y no alterar el código fuera de la función.

void capturarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{

  for (int i = 0; i < cantidad; i++)
  {
    if (piezas[i].posicion[0] == fila && piezas[i].posicion[1] == columna && piezas[i].activa == 1)
    {
      piezas[i].activa = 0;
      printf("Pieza encontrada en la posición [%d, %d]", fila, columna);
      return;
    }
  }
  printf("No existe pieza en la posición brindada");
}

struct Pieza buscarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
  int inicio = 0;
  int fin = cantidad - 1;

  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;

    if (piezas[medio].posicion[0] == fila && piezas[medio].posicion[1] == columna)
      return piezas[medio];

    if (piezas[medio].posicion[0] < fila)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }
  struct Pieza vacia = {{-1, -1}, "", '\0', 0, 0};
  return vacia;
}

// En base al programa publicado en el repositorio https://github.com/facundouferer/cursodec/blob/main/Parciales/Parcial02/segundoParcialAjedrez.c desarrolle la función Modificar Pieza, que permita modificar el tipo y el color.
// El tipo de pieza no debe ingresarse manualmente como texto: debe seleccionarse con un número y luego obtenerse usando la función seleccionarTipoDePieza.
// El valor tampoco debe ingresarse manualmente: debe calcularse automáticamente usando la función obtenerValorDePieza.
// El color debe cargarse como un caracter: b para blanco y n para negro.
// Para que el programa funcione perfectamente debe existir ésta función y no alterar el código fuera de la función.
void modificarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
  struct Pieza encontrada = buscarPieza(piezas, cantidad, fila, columna);

  int tipoPieza;
  int valorPieza;

  printf("Ingrese el tipo de pieza");
  scanf("%d", &tipoPieza);

  printf("Ingrese el valor de pieza");
  scanf("%d", &valorPieza);

  encontrada.tipo = seleccionarTipoDePieza(tipoPieza);
  encontrada.valor = obtenerValorDePieza(valorPieza);
}

int main()
{
  struct Pieza piezas[100];
  int cantidad = 0;
  int opcion;

  do
  {
    mostrarMenu();
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
    {
      struct Pieza nueva;
      printf("Fila: ");
      scanf("%d", &nueva.posicion[0]);
      printf("Columna: ");
      scanf("%d", &nueva.posicion[1]);

      int numeroPieza;
      printf("Seleccione el tipo de pieza:\n");
      printf("1. Peon\n");
      printf("2. Torre\n");
      printf("3. Caballo\n");
      printf("4. Alfil\n");
      printf("5. Reina\n");
      printf("6. Rey\n");
      printf("Ingrese una opcion: ");
      scanf("%d", &numeroPieza);

      strcpy(nueva.tipo, seleccionarTipoDePieza(numeroPieza));
      printf("Color ('b' blanco, 'n' negro): ");
      scanf(" %c", &nueva.color);
      nueva.valor = obtenerValorDePieza(numeroPieza);
      nueva.activa = 1;
      agregarPieza(piezas, &cantidad, nueva);
      break;
    }
    case 2:
      listarPiezasPorValor(piezas, cantidad);
      break;
    case 3:
    {
      int fila, columna;
      printf("Fila de la pieza a buscar: ");
      scanf("%d", &fila);
      printf("Columna de la pieza a buscar: ");
      scanf("%d", &columna);

      struct Pieza encontrada = buscarPieza(piezas, cantidad, fila, columna);
      if (encontrada.posicion[0] != -1)
      {
        printf("Posicion: (%d,%d), Tipo: %s, Color: %c, Valor: %d\n",
               encontrada.posicion[0], encontrada.posicion[1], encontrada.tipo, encontrada.color, encontrada.valor);
      }
      else
      {
        printf("Pieza no encontrada.\n");
      }
      break;
    }
    case 4:
      listarPiezasPorPosicion(piezas, cantidad);
      break;
    case 5:
      listarPiezasActivas(piezas, cantidad);
      break;
    case 6:
    {
      int fila, columna;
      printf("Fila de la pieza a capturar: ");
      scanf("%d", &fila);
      printf("Columna de la pieza a capturar: ");
      scanf("%d", &columna);
      capturarPieza(piezas, cantidad, fila, columna);
      break;
    }
    case 7:
    {
      int fila, columna;
      printf("Fila de la pieza a restaurar: ");
      scanf("%d", &fila);
      printf("Columna de la pieza a restaurar: ");
      scanf("%d", &columna);
      restaurarPieza(piezas, cantidad, fila, columna);
      break;
    }
    case 8:
    {
      int fila, columna;
      printf("Fila de la pieza a modificar: ");
      scanf("%d", &fila);
      printf("Columna de la pieza a modificar: ");
      scanf("%d", &columna);
      modificarPieza(piezas, cantidad, fila, columna);
      break;
    }
    case 9:
      mostrarEstadisticas(piezas, cantidad);
      break;
    case 10:
      printf("Saliendo...\n");
      break;
    default:
      printf("Opcion invalida.\n");
    }

  } while (opcion != 10);

  return 0;
}

// ordenar piezas con el Metodo de la Burbuja (Bubble Sort)
void ordenarPiezas(struct Pieza piezas[], int cantidad)
{
  struct Pieza aux;
  for (int i = 0; i < cantidad - 1; i++)
  {
    for (int j = 0; j < cantidad - i - 1; j++)
    {
      if (piezas[j].posicion[0] > piezas[j + 1].posicion[0] ||
          (piezas[j].posicion[0] == piezas[j + 1].posicion[0] &&
           piezas[j].posicion[1] > piezas[j + 1].posicion[1]))
      {
        aux = piezas[j];
        piezas[j] = piezas[j + 1];
        piezas[j + 1] = aux;
      }
    }
  }
}

// restaurar una pieza por posicion
void restaurarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
  for (int i = 0; i < cantidad; i++)
  {
    if (piezas[i].posicion[0] == fila && piezas[i].posicion[1] == columna)
    {
      piezas[i].activa = 1;
      printf("Pieza en posicion (%d,%d) restaurada.\n", fila, columna);
      return;
    }
  }
  printf("Pieza en posicion (%d,%d) no encontrada.\n", fila, columna);
}

// mostrar cantidad de piezas activas y capturadas
void mostrarEstadisticas(struct Pieza piezas[], int cantidad)
{
  int activas = 0;
  int capturadas = 0;
  for (int i = 0; i < cantidad; i++)
  {
    if (piezas[i].activa == 1)
      activas++;
    else
      capturadas++;
  }
  printf("Total de piezas: %d\n", cantidad);
  printf("Activas: %d\n", activas);
  printf("Capturadas: %d\n", capturadas);
}

void agregarPieza(struct Pieza piezas[], int *cantidad, struct Pieza nuevaPieza)
{
  if (*cantidad < 100)
  {
    piezas[*cantidad] = nuevaPieza;
    (*cantidad)++;
    printf("Pieza agregada: Posicion (%d,%d), Tipo: %s, Color: %c\n",
           nuevaPieza.posicion[0], nuevaPieza.posicion[1], nuevaPieza.tipo, nuevaPieza.color);
  }
  else
  {
    printf("No se pueden agregar mas piezas. Capacidad maxima alcanzada.\n");
  }
}

char *seleccionarTipoDePieza(int numeroPieza)
{
  switch (numeroPieza)
  {
  case 1:
    return "peon";
  case 2:
    return "torre";
  case 3:
    return "caballo";
  case 4:
    return "alfil";
  case 5:
    return "reina";
  case 6:
    return "rey";
  default:
    return "desconocida";
  }
}

int obtenerValorDePieza(int numeroPieza)
{
  switch (numeroPieza)
  {
  case 1:
    return 1;
  case 2:
    return 5;
  case 3:
    return 3;
  case 4:
    return 3;
  case 5:
    return 9;
  case 6:
    return 100;
  default:
    return 0;
  }
}

void mostrarMenu()
{
  printf("\nMenu de opciones:\n");
  printf("1. Agregar pieza\n");
  printf("2. Listar piezas por valor\n");
  printf("3. Buscar pieza por posicion\n");
  printf("4. Listar piezas por posicion\n");
  printf("5. Mostrar piezas activas\n");
  printf("6. Capturar pieza\n");
  printf("7. Restaurar pieza\n");
  printf("8. Modificar pieza\n");
  printf("9. Mostrar estadisticas (activas/capturadas)\n");
  printf("10. Salir\n");
}