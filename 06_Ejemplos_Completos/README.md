# 06_Ejemplos_Completos — Programas armados de punta a punta

Tres CRUDs completos, **listos para compilar y entregar**. Si la consigna es muy parecida a una de éstas, podés tomar el archivo entero, cambiar nombres del struct y campos, y ya está.

## Archivos

| Archivo | Pensado para… | Características distintivas |
|---|---|---|
| `crud_productos.c` | Gestión de productos / inventarios | Réplica de la lógica del **modelo del 2° parcial**. Burbuja inicial + binaria + agregar reordenando |
| `crud_libros.c` | Gestión de libros / biblioteca | Réplica de la consigna del **final 29/07/2025**. Struct con 5 campos. |
| `crud_alumnos_notas.c` | Gestión de alumnos con notas | Incluye **cálculo de promedio** sobre array de notas. |

## Cuál tomar según la consigna

| Si la consigna se parece a… | Empezá con |
|---|---|
| "Gestionar productos / artículos / inventario con código, nombre y precio" | `crud_productos.c` |
| "Librería con código, título, autor, precio y stock" | `crud_libros.c` |
| "Alumnos con legajo, nombre y notas. Calcular promedio." | `crud_alumnos_notas.c` |
| Otra entidad cualquiera | El más parecido + cambiar nombres |

## Qué funciones tiene cada uno

Los 3 incluyen las 6 operaciones estándar:

1. Listar
2. Buscar (binaria por id donde tiene sentido, lineal en alumnos)
3. Agregar (con validación de duplicado)
4. Eliminar (con shift)
5. Modificar (validando existencia)
6. Salir

En `crud_alumnos_notas.c` además hay una opción extra para listar ordenado por promedio.
