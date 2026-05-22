# GUIA RAPIDA — "Si te piden X → usá Y"

> **Tu mapa de batalla durante el parcial.** Encontrá la fila más parecida a la consigna, copiá el archivo base, sumale lo del extra.

---

## 1) Mapa de consignas típicas

### Estructura del programa

| Consigna probable | Archivo base | Sumale |
|---|---|---|
| "Gestionar / administrar / registrar [productos / libros / alumnos / empleados / cualquier entidad]" | `plantilla_base.c` | Un struct de `01_Structs/` |
| "Sistema con menú interactivo" | `04_Operaciones_CRUD/menu_interactivo.c` | Las operaciones que pida |
| "Programa modular con funciones separadas" | `plantilla_base.c` (ya está modularizado) | — |

### Elección del struct

| La entidad es… | Usá como base | Campos típicos |
|---|---|---|
| Producto / artículo / item de inventario | `01_Structs/producto.c` | código + nombre + precio |
| Libro / publicación | `01_Structs/libro.c` | código + título + autor + precio + stock |
| Alumno / estudiante con notas | `01_Structs/alumno.c` | legajo + nombre + notas[3] + promedio |
| Empleado / trabajador | `01_Structs/empleado.c` | dni + nombre + sueldo + antigüedad |
| Vehículo / auto / moto | `01_Structs/vehiculo.c` | patente + marca + modelo + año + precio |
| Persona / contacto / cliente | `01_Structs/persona.c` | dni + nombre + edad |
| Película / canción / contenido multimedia | `01_Structs/pelicula.c` | código + título + director + año + duración |

> **Truco**: si la entidad no encaja perfecto, agarrá la más parecida y **sólo cambiá nombres de campos**. La lógica del programa no cambia.

### Ordenamiento

| Consigna probable | Archivo base | Detalle |
|---|---|---|
| "Ordenar por código / número / id" | `02_Ordenamientos/burbuja_struct.c` | Comparación `>` entre campos enteros |
| "Ordenar alfabéticamente / por nombre" | `02_Ordenamientos/burbuja_struct.c` (variante `strcmp`) | Cambiar la comparación por `strcmp(a, b) > 0` |
| "Ordenar de menor a mayor precio / sueldo" | `02_Ordenamientos/burbuja_struct.c` (variante `float`) | Comparación `>` entre `float` |
| "Ordenar de mayor a menor" | Cualquiera de los anteriores | Invertir el signo de la comparación: `<` en vez de `>` |
| "Ordenar usando método de selección" | `02_Ordenamientos/seleccion_struct.c` | — |
| "Ordenar usando método de inserción" | `02_Ordenamientos/insercion_struct.c` | — |
| Te dicen "el más simple" o no especifican | Usá **burbuja** | Más fácil de recordar y explicar |

### Búsqueda

| Consigna probable | Archivo base | Requisito |
|---|---|---|
| "Buscar por código / id / dni / legajo" en arreglo **ordenado** | `03_Busquedas/binaria_struct.c` | Ordenar antes (sumá burbuja) |
| "Buscar por código / id" sin garantía de orden | `03_Busquedas/lineal_struct.c` | Ninguno |
| "Buscar por nombre / título / apellido" | `03_Busquedas/lineal_struct.c` (variante `strcmp`) | Usar `strcmp(a, b) == 0` |
| "Buscar todos los que…" / "los que cumplen…" | `03_Busquedas/lineal_struct.c` (variante múltiple) | Sin `return` adentro del `if`, imprimir cada match |
| "Contar cuántos…" | `03_Busquedas/contar_ocurrencias.c` | — |
| "Listar los que tienen precio > X" / filtro | `04_Operaciones_CRUD/listar.c` + un `if` adentro | — |

### Operaciones CRUD

| Consigna probable | Archivo base | Validación obligatoria |
|---|---|---|
| "Agregar / registrar / cargar un nuevo X" | `04_Operaciones_CRUD/agregar.c` | No permitir id duplicado, no superar `MAX` |
| "Eliminar / dar de baja un X" | `04_Operaciones_CRUD/eliminar.c` | Validar que exista antes |
| "Modificar / actualizar / editar un X" | `04_Operaciones_CRUD/modificar.c` | Validar que exista antes |
| "Listar / mostrar todos los X" | `04_Operaciones_CRUD/listar.c` | Avisar si el arreglo está vacío |

### Casos especiales

| Consigna probable | Archivo base |
|---|---|
| "Calcular promedio de notas / valores" | `06_Ejemplos_Completos/crud_alumnos_notas.c` |
| "Mostrar el más caro / más alto / mayor" | `02_Ordenamientos/seleccion_struct.c` (lógica de `max`) |
| "Mostrar el más barato / menor" | Igual pero con `min` |
| "Validar entrada del usuario" | `05_Entradas/lectura_segura.c` |

---

## 2) CHECKLIST de validaciones que SIEMPRE hay que poner

Sacado directo de los criterios de evaluación del final 29/07/2025. **Si te falta alguna, perdés puntos garantizado.**

- [ ] **No permitir agregar con id duplicado** (revisar con búsqueda lineal antes de agregar).
- [ ] **No permitir eliminar un id que no existe** (avisar y volver al menú).
- [ ] **No permitir modificar un id que no existe** (avisar y volver al menú).
- [ ] **No superar `MAX_REGISTROS`** al agregar (avisar "inventario lleno").
- [ ] **Opción inválida en menú** → mensaje "opción inválida" y reintentar.
- [ ] **Listar arreglo vacío** → avisar "no hay registros" en vez de imprimir nada.
- [ ] **Buscar y no encontrar** → avisar "no se encontró".
- [ ] **Salir limpio** del programa con opción 6 (o la que sea).

---

## 3) Estructura mental del programa típico

```
#include + #define
↓
struct definicion
↓
prototipos de funciones (todas)
↓
main()
  ├── arreglo inicializado (a veces) + int n
  ├── ordenamiento inicial (a veces)
  └── do-while
        switch (opcion)
          case 1: listar
          case 2: buscar
          case 3: eliminar
          case 4: agregar
          case 5: modificar
          case 6: salir
          default: opcion invalida
↓
definicion de cada funcion debajo
```

---

## 4) Tabla de algoritmos: cuándo usar cuál

| Algoritmo | Cuándo conviene | Complejidad |
|---|---|---|
| **Burbuja** | Siempre que no te aclaren — es el más fácil de escribir y explicar | O(n²) |
| **Selección** | Si te piden encontrar también el "mínimo" o "máximo" como subproducto | O(n²) |
| **Inserción** | Si el arreglo está casi ordenado o vas insertando uno por uno | O(n²) peor / O(n) mejor |
| **Búsqueda lineal** | Arreglo desordenado, búsqueda por string, búsquedas múltiples | O(n) |
| **Búsqueda binaria** | Arreglo ordenado, búsqueda por entero, una sola búsqueda | O(log n) |

---

## 5) Trampas frecuentes (mirar antes de entregar)

1. **`scanf("%d", &x)` deja un `\n` en el buffer**: si después leés un string con `fgets`, se come ese newline. Solución: `getchar();` antes del `fgets`, o usar `scanf(" %[^\n]", ...)` con el espacio inicial.
2. **`strcmp` devuelve 0 si son iguales**, no 1. `if (strcmp(a, b) == 0)`.
3. **Al eliminar, recorré desde `i` hasta `n-1`**, no hasta `n` (causás un acceso fuera del arreglo).
4. **Al agregar y reordenar**, hacelo DESPUÉS de incrementar `n`.
5. **Pasar `n` por referencia con `int *n`** cuando agregás o eliminás. Si lo pasás por valor, los cambios se pierden.
6. **Los prototipos arriba** o el compilador no encuentra las funciones.
7. **`return 0;` al final de `main`**, siempre.
