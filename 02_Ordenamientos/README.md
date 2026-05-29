# 02_Ordenamientos — Burbuja, Selección e Inserción

Tres algoritmos clásicos en dos sabores: con `int[]` (para entender la lógica pura) y con arreglo de `struct` (la versión que vas a usar en el parcial).

## Cuál usar y cuándo

| Algoritmo | Cuándo conviene | Complejidad |
|---|---|---|
| **Burbuja** | Default. Más fácil de escribir y recordar. **Si no te aclaran, usá esto.** | O(n²) |
| **Selección** | Si te piden también "el mayor" / "el menor" como subproducto | O(n²) |
| **Inserción** | Si vas agregando uno por uno y querés mantener orden mientras insertás | O(n²) peor, O(n) mejor |

## Archivos

| Archivo | Contenido |
|---|---|
| `burbuja_int.c` | Arreglo de enteros. Base teórica. |
| `burbuja_struct.c` | Arreglo de structs. Con 3 variantes: por id entero, por float, por nombre (`strcmp`). |
| `seleccion_int.c` | Arreglo de enteros. |
| `seleccion_struct.c` | Arreglo de structs. |
| `insercion_int.c` | Arreglo de enteros. |
| `insercion_struct.c` | Arreglo de structs. |
| `ordenamiento_doble_criterio.c` | **Orden por dos criterios**: primario + desempate. Ej: por apellido y, a igual apellido, por nombre (o por legajo). |

## Ordenar por DOS criterios (apellido y, si se repite, otra cosa)

Cuando piden algo como `Acosta 1, Acosta 2, Acosta 3, Balbiano 1, Balbiano 2` (primero por un campo y, **a igual valor**, por un segundo campo), la idea está en el `if` del comparador:

```c
int cmp = strcmp(arr[j].apellido, arr[j + 1].apellido);   // criterio 1
if (cmp > 0 || (cmp == 0 && strcmp(arr[j].nombre, arr[j + 1].nombre) > 0))
//          ▲                  ▲
//   apellido mayor    SOLO si los apellidos empatan (cmp == 0), desempata por nombre
```

> ⚠️ No compares solo `apellido[0]` (la primera letra): "Gomez" y "Garcia" empezarían iguales. Usá `strcmp` sobre el string completo. Ejemplo completo en `ordenamiento_doble_criterio.c`.

## Cómo cambiar el criterio de ordenamiento

Mirá el `if` del comparador. En el código verás:

```c
if (arr[j].codigo > arr[j+1].codigo)    // ASCENDENTE por codigo
```

- **De mayor a menor**: cambiar `>` por `<`.
- **Por otro campo entero**: cambiar `codigo` por `legajo`, `dni`, `anio`, etc.
- **Por campo float**: misma forma, comparando `arr[j].precio > arr[j+1].precio`.
- **Por nombre (string)**: usar `strcmp(arr[j].nombre, arr[j+1].nombre) > 0`. Importa `#include <string.h>`.

## Patrón mental

```
para i = 0 hasta n-1:
    para j = 0 hasta n-1-i:
        si arr[j] > arr[j+1]:
            intercambiar arr[j] con arr[j+1]
```

El intercambio (swap) siempre necesita una variable `temp` del mismo tipo.
