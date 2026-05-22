# 01_Structs — Modelos de struct listos para copiar

Cada archivo tiene un struct ya definido, un arreglo inicializado con datos de prueba y un `main` que lo imprime. **Compilan y corren tal cual.**

## Cómo elegir cuál usar

| La consigna habla de… | Usá |
|---|---|
| Productos / artículos / inventario | `producto.c` |
| Libros / publicaciones / biblioteca | `libro.c` |
| Alumnos / estudiantes con notas | `alumno.c` |
| Empleados / trabajadores con sueldo | `empleado.c` |
| Vehículos / autos / motos | `vehiculo.c` |
| Personas / clientes / contactos | `persona.c` |
| Películas / canciones / contenido | `pelicula.c` |

> Si no encaja perfecto, agarrá el más parecido y **sólo renombrá campos**. Por ejemplo: `pelicula.c` → cambias `titulo` por `nombreCancion`, `director` por `artista`, `duracion` por `minutos` y listo.

## Tabla de campos por archivo

| Archivo | ID entero | Campo string | Campo float | Campo entero extra |
|---|---|---|---|---|
| `producto.c` | `codigo` | `nombre` | `precio` | — |
| `libro.c` | `codigo` | `titulo` + `autor` | `precio` | `stock` |
| `alumno.c` | `legajo` | `nombre` | `promedio` + `notas[3]` | — |
| `empleado.c` | `dni` | `nombre` | `sueldo` | `antiguedad` |
| `vehiculo.c` | — (patente es string) | `patente` + `marca` + `modelo` | `precio` | `anio` |
| `persona.c` | `dni` | `nombre` | — | `edad` |
| `pelicula.c` | `codigo` | `titulo` + `director` | — | `anio` + `duracion` |

## Cómo combinarlos con el resto del kit

1. Copiá el `struct ...` de acá al archivo donde estás armando tu programa.
2. Copiá el prototipo del struct **arriba de los prototipos de funciones**.
3. Ajustá `plantilla_base.c` reemplazando los nombres de campos.
4. En `02_Ordenamientos/` y `03_Busquedas/` adaptá la comparación al campo que necesites.
