# 🧠 TIPS de C — funciones copadas y trampas que te hacen perder puntos

> Chuleta para el 2° parcial de Programación I. Acá está lo que **realmente usás** en los ejercicios: qué función trae cada librería (lo que va entre `<...>`), cómo se usa, y los detalles del lenguaje que te hacen renegar (comillas simples vs dobles, `=` vs `==`, el `\n` que deja `scanf`, etc.).

---

## 📚 Librerías: qué `#include` te trae cada cosa

En C, `#include <algo.h>` "importa" funciones. Si usás una función sin incluir su librería, el compilador tira warning o error.

| `#include` | Qué te da | Funciones que vas a usar |
|---|---|---|
| `<stdio.h>` | Entrada/salida estándar | `printf`, `scanf`, `fgets`, `getchar`, `puts` |
| `<string.h>` | Manejo de strings (cadenas) | `strcmp`, `strcpy`, `strlen`, `strcat`, `strchr`, `strcspn` |
| `<stdlib.h>` | Utilidades generales | `atoi`, `atof`, `abs`, `rand`, `qsort`, `malloc` |
| `<math.h>` | Matemática | `sqrt`, `pow`, `ceil`, `floor`, `round`, `fabs` |
| `<ctype.h>` | Clasificar/convertir caracteres | `toupper`, `tolower`, `isdigit`, `isalpha`, `isspace` |
| `<stdbool.h>` | Tipo `bool` con `true` / `false` | (sin él, usá `int` con `0` y `1`) |

> ⚠️ **`<math.h>` necesita el flag `-lm` al compilar** en algunos sistemas: `gcc archivo.c -o prog -lm`.

---

## ⭐ Funciones más usadas en el parcial

### Strings (`<string.h>`)

```c
strcmp(a, b)     // compara dos strings. Devuelve: <0, 0 (iguales), >0
strcpy(dest, o)  // copia el string 'o' dentro de 'dest'.  ¡NO se usa '=' para copiar strings!
strlen(s)        // largo del string (sin contar el '\0' final)
strcat(dest, o)  // pega 'o' al final de 'dest'
```

```c
// Comparar nombres (ordenar / buscar alfabéticamente):
if (strcmp(arr[j].nombre, arr[j + 1].nombre) > 0) { /* arr[j] va DESPUÉS */ }

// Buscar por nombre exacto:
if (strcmp(arr[i].nombre, "Acosta") == 0) { /* lo encontré */ }

// Copiar (NUNCA con =):
strcpy(persona.nombre, "Luciano");   // ✅
// persona.nombre = "Luciano";       // ❌ NO compila
```

### Caracteres (`<ctype.h>`)

```c
toupper('a')   // -> 'A'      pasar a mayúscula
tolower('A')   // -> 'a'      pasar a minúscula
isdigit('5')   // -> distinto de 0 si es un dígito '0'..'9'
isalpha('x')   // -> distinto de 0 si es una letra
isspace(' ')   // -> distinto de 0 si es espacio, tab o salto de línea
```

### Conversión y matemática (`<stdlib.h>` y `<math.h>`)

```c
atoi("123")    // string -> int   (stdlib.h)
atof("3.14")   // string -> float (stdlib.h)
abs(-7)        // -> 7  valor absoluto de un int (stdlib.h)
fabs(-7.5)     // -> 7.5  valor absoluto de un float/double (math.h)
sqrt(25.0)     // -> 5.0  raíz cuadrada (math.h)
pow(2.0, 3.0)  // -> 8.0  potencia 2³  (math.h)
round(3.6)     // -> 4.0  redondear   (math.h)
```

---

## 🖨️ `printf` / `scanf`: los formatos (`%`)

| Especificador | Tipo | Ejemplo |
|---|---|---|
| `%d` | entero (`int`) | `printf("%d", 42);` |
| `%f` | flotante (`float`/`double`) | `printf("%f", 3.14);` |
| `%.2f` | flotante con 2 decimales | `printf("%.2f", 3.14159);` → `3.14` |
| `%c` | un carácter (`char`) | `printf("%c", 'A');` |
| `%s` | string (cadena) | `printf("%s", nombre);` |
| `%-10s` | string alineado a izquierda en 10 espacios | tablas prolijas |
| `%03d` | entero con ceros a la izquierda | `5` → `005` |

```c
// Tabla alineada (lo que se ve "profesional" en el parcial):
printf("%-7d %-20s %.2f\n", id, nombre, precio);
```

> 🔑 **En `scanf`, las variables comunes van con `&`** (porque pasás su dirección):
> ```c
> scanf("%d", &edad);      // ✅ con &
> scanf("%f", &precio);    // ✅ con &
> scanf("%s", nombre);     // ⚠️ string SIN & (un array YA es una dirección)
> ```

---

## 🪤 Las trampas clásicas de C (acá se pierden puntos)

### 1. Comillas simples `' '` ≠ comillas dobles `" "`

Esta es **la** confusión más común:

```c
'a'    // CARÁCTER. Es un solo char. En realidad es el número 97 (código ASCII).
"a"    // STRING. Son DOS bytes: 'a' y el terminador '\0'. Es un char[].
```

```c
char letra = 'A';        // ✅ un char lleva comillas SIMPLES
char letra = "A";        // ❌ error: "A" es un string, no un char

char nombre[] = "Ana";   // ✅ un string lleva comillas DOBLES
if (resp == 's')         // ✅ comparar un char -> comillas simples
if (resp == "s")         // ❌ no compila / no hace lo que creés
```

> 💡 Regla: **un solo carácter → `' '`. Texto (uno o más) → `" "`.**

### 2. `=` (asignar) ≠ `==` (comparar)

```c
if (opcion = 6)   // ❌ ASIGNA 6 a opcion y siempre da verdadero
if (opcion == 6)  // ✅ COMPARA si opcion vale 6
```

### 3. `scanf("%d", ...)` deja el `\n` (Enter) en el buffer

Después de leer un número, el Enter queda en el buffer y el próximo `scanf` de string lo "come" vacío.

```c
scanf("%d", &edad);
scanf(" %29[^\n]", nombre);   // ✅ el ESPACIO antes de % se saltea el \n pendiente
```

> El truco `" %[^\n]"` lee "todo hasta el salto de línea" (permite nombres con espacios). El espacio inicial salta blancos/Enter previos. El `29` evita pasarse del tamaño del array `char nombre[30]`.

### 4. `strcmp` devuelve `0` cuando son **iguales** (no `1`)

```c
if (strcmp(a, b) == 0)   // ✅ son iguales
if (strcmp(a, b))        // ⚠️ esto es verdadero cuando son DISTINTOS (¡al revés!)
```

### 5. No se comparan ni se copian strings con operadores

```c
if (nombre == "Ana")     // ❌ compara direcciones, no el contenido
if (strcmp(nombre,"Ana")==0)  // ✅

nombre = otroNombre;     // ❌ no se copian arrays así
strcpy(nombre, otroNombre);   // ✅
```

### 6. Los arrays empiezan en `0`

Un `arr[5]` tiene índices válidos `0,1,2,3,4`. El `arr[5]` **no existe** (acceso fuera de rango).

```c
for (int i = 0; i < n; i++)   // ✅ de 0 a n-1
for (int i = 0; i <= n; i++)  // ❌ se pasa uno (lee basura / rompe)
```

### 7. Al **eliminar** de un array, corré hasta `n-1`

```c
for (int i = pos; i < n - 1; i++)   // ✅ corre elementos a la izquierda
    arr[i] = arr[i + 1];
n--;
```

### 8. Pasá `n` por referencia (`int *n`) cuando lo cambiás

Si una función **agrega o elimina**, tiene que modificar la cantidad real:

```c
void agregar(struct X arr[], int *n) { ...; (*n)++; }  // ✅ cambia el n del main
void agregar(struct X arr[], int n)  { ...; n++; }     // ❌ el ++ se pierde al volver
```

### 9. División entera: `5 / 2` da `2`, no `2.5`

```c
int suma = 5, cant = 2;
float prom = suma / cant;          // ❌ da 2.0 (divide enteros y DESPUÉS convierte)
float prom = (float)suma / cant;   // ✅ da 2.5 (castea a float antes de dividir)
```

### 10. La búsqueda binaria exige el array **ordenado**

Si el array no está ordenado por la clave que buscás, la búsqueda binaria da resultados incorrectos. Ordená **antes** (ver `02_Ordenamientos/`).

---

## 🧩 Ordenar por DOS criterios (apellido y, si se repite, otra cosa)

Lo que pedían: `Acosta 1, Acosta 2, Acosta 3, Balbiano 1, Balbiano 2` → primero por apellido y, **a igual apellido**, por el segundo campo.

```c
int cmp = strcmp(arr[j].apellido, arr[j + 1].apellido);
if (cmp > 0 || (cmp == 0 && arr[j].nombre > arr[j + 1].nombre ...)) { swap }
//        ▲                  ▲
//   criterio 1         desempate SOLO si el criterio 1 empató (cmp == 0)
```

Código completo y explicado en **`02_Ordenamientos/ordenamiento_doble_criterio.c`**.

> ⚠️ No compares solo la **primera letra** (`apellido[0]`): "Gomez" y "Garcia" empiezan con `'G'` y quedarían como iguales. Usá `strcmp` sobre el string completo.

---

## ⚙️ Compilar (terminal de Codespaces / VSCode)

```bash
gcc -Wall -Wextra archivo.c -o programa   # compila con todos los warnings
./programa                                 # lo ejecuta
gcc -Wall -Wextra archivo.c -o prog -lm    # si usás <math.h> (sqrt, pow...)
```

- `-Wall -Wextra` → muestra **todos los warnings**. Si compila limpio acá, vas bien.
- `-g` → agrega info para **debuggear** con breakpoints (F5 en VSCode).
- En VSCode: botón **▶** (Code Runner) para correr, o **F5** para debuggear.

> ✅ Checklist anti-warnings: variables sin usar, `return 0;` al final de `main`, prototipos de funciones arriba, no mezclar `%d` con `float`.

---

## 🔤 Caracteres especiales dentro de strings (escapes)

| Escape | Qué hace |
|---|---|
| `\n` | salto de línea (Enter) |
| `\t` | tabulación (alinea columnas) |
| `\\` | una barra `\` literal |
| `\"` | una comilla doble `"` dentro del string |
| `%%` | un signo `%` literal dentro de `printf` |

```c
printf("Precio: 50%%\n");      // imprime: Precio: 50%
printf("Col1\tCol2\tCol3\n");  // columnas separadas por tabs
```

---

> 📎 Ver también: `GUIA_RAPIDA.md` (mapa "si te piden X → usá Y") y `07_Modelos_Parcial/` (modelos resueltos completos).
