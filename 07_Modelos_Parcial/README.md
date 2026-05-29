# 07_Modelos_Parcial — Modelos resueltos estilo 2° parcial

Programas **completos y resueltos** con la misma forma que los modelos reales del 2° parcial (estructura + ordenamiento + búsqueda binaria + menú CRUD). Sirven para ver una consigna entera resuelta de punta a punta y como esqueleto para copiar.

## Archivos

| Archivo | Qué muestra | Entidad |
|---|---|---|
| `modelo_empleados_orden_busqueda.c` | Ordenar por clave + **búsqueda binaria** + listado por **doble criterio** (apellido y nombre). Sin menú: corre solo. | Empleado (legajo, apellido, nombre, sueldo) |
| `modelo_canciones_crud.c` | **CRUD completo** con menú: listar, buscar, agregar, eliminar, **modificar** (implementado) + todas las validaciones. | Canción (código, título, artista, duración) |
| `modelo_temperaturas_int.c` | Mismo esquema pero con un **arreglo de enteros** (sin struct) + estadísticas (promedio, máx, mín). | Temperaturas (`int[]`) |

## Cómo compilar y correr

```bash
gcc -Wall -Wextra 07_Modelos_Parcial/modelo_canciones_crud.c -o modelo2
./modelo2
```

En Codespaces / VSCode: abrí el `.c` y apretá el botón ▶ (Code Runner) o `F5` para debuggear. Ver `.devcontainer/` y `TIPS_C.md`.

## Relación con los modelos del curso

Están inspirados en los [modelos de Facundo Uferer](https://github.com/facundouferer/cursodec/tree/main/Parciales/modelos) pero:

- Son **entidades nuevas** (empleados, canciones, temperaturas) para que practiques adaptando, no copiando.
- Usan **búsqueda binaria que devuelve índice** (más reutilizable que devolver una copia del struct).
- El ordenamiento por nombre/apellido compara el **string completo con `strcmp`**, no solo la primera letra (el modelo original compara `apellido[0]`, que falla con apellidos que empiezan igual: "Gomez" vs "Garcia").
- En el CRUD, **modificar está implementado** (en el modelo original quedaba como "no implementado").

> Para el ordenamiento por dos criterios a la vez (ej: apellido y, a igual apellido, nombre o legajo), mirá también `02_Ordenamientos/ordenamiento_doble_criterio.c`.
