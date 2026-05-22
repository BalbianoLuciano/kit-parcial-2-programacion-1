# 03_Busquedas — Lineal, Binaria y Contar

## Cuál usar y cuándo

| Algoritmo | Cuándo conviene | Requiere | Complejidad |
|---|---|---|---|
| **Lineal** | Default. Arreglo desordenado, búsqueda por string, búsquedas múltiples | Nada | O(n) |
| **Binaria** | Búsqueda rápida por campo entero | Arreglo **ordenado** por ese campo | O(log n) |
| **Contar** | "¿Cuántas veces aparece X?" | Nada | O(n) |

## Archivos

| Archivo | Contenido |
|---|---|
| `lineal_int.c` | Búsqueda lineal en arreglo de enteros. |
| `lineal_struct.c` | 3 variantes: por id entero, por nombre (`strcmp`), todas las que cumplen un rango. |
| `binaria_int.c` | Búsqueda binaria en arreglo de enteros (ordenado). |
| `binaria_struct.c` | Búsqueda binaria por campo entero del struct. |
| `contar_ocurrencias.c` | Cuenta cuántos elementos cumplen una condición. |

## Trampas frecuentes

- **Binaria sin ordenar = búsqueda rota.** Si tenés dudas si está ordenado, ordená primero (sumá un burbuja).
- **`strcmp` devuelve 0 cuando son iguales**, no 1. La comparación correcta es `if (strcmp(a, b) == 0)`.
- **Devolver "no encontrado"** desde una función que devuelve `struct`: devolver un struct con `id = 0` y en el `main` verificar `if (r.id != 0)`.

## Patrón "encontré / no encontré"

```c
int encontrado = 0;
for (int i = 0; i < n; i++) {
    if (arr[i].codigo == buscado) {
        // imprimir / hacer algo
        encontrado = 1;
        break;
    }
}
if (!encontrado) {
    printf("No se encontro.\n");
}
```
