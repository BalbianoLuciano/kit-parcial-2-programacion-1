# 04_Operaciones_CRUD — Las 5 operaciones aisladas

Cada archivo es la operación CRUD ya armada como función, con un `main` mínimo que la usa. Tomá la función, pegala en tu programa, ajustá los nombres de los campos del struct.

## Archivos

| Archivo | Operación | Validaciones que incluye |
|---|---|---|
| `agregar.c` | Agregar un struct nuevo al arreglo | No duplicado + no superar `MAX` |
| `eliminar.c` | Eliminar por id (con *shift* del arreglo) | Validar existencia |
| `modificar.c` | Cambiar campos de un registro existente | Validar existencia |
| `listar.c` | Imprimir el arreglo completo en formato tabla | Avisar si vacío |
| `menu_interactivo.c` | Esqueleto del `do-while + switch` | Opción inválida |

## Patrón del CRUD completo

Estas 5 piezas + un `struct` + un arreglo + ordenamiento/búsqueda = programa completo. Es **exactamente** lo que pide la consigna típica.

## Recordatorio sobre el paso de parámetros

- **Listar / Modificar / Buscar**: el tamaño `n` se pasa por valor (`int n`).
- **Agregar / Eliminar**: el tamaño `n` cambia, así que se pasa por referencia (`int *n`) y se usa `(*n)++` / `(*n)--` adentro.

> Si te olvidás del `*`, los cambios a `n` se pierden cuando la función termina, y tu arreglo "olvida" lo que pasó.
