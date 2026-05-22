# 05_Entradas — Lectura segura de datos

Cómo leer enteros y strings sin que se rompa el programa. La mayoría de los problemas raros en parciales vienen de un `scanf` mal usado.

## Reglas que evitan el 90% de los bugs

1. **Para enteros**: `scanf("%d", &x);` y listo, no tiene mucha vuelta.
2. **Para strings con espacios**: usar `scanf(" %49[^\n]", str);` — el espacio inicial come el `\n` del buffer.
3. **Para strings con `fgets`**: `fgets(str, TAM, stdin);` + `str[strcspn(str, "\n")] = '\0';` para quitar el `\n` final.
4. **Después de un `scanf("%d", ...)` y antes de leer un string**: `getchar();` para limpiar el buffer.

## Tabla rápida

| Necesito leer… | Forma más segura |
|---|---|
| Un entero | `scanf("%d", &x);` |
| Un float | `scanf("%f", &x);` |
| Una palabra sin espacios | `scanf("%29s", str);` |
| Frase con espacios (estilo modelo) | `scanf(" %49[^\n]", str);` |
| Frase con espacios (estilo fgets) | `fgets(str, TAM, stdin); str[strcspn(str, "\n")] = '\0';` |

## Archivo

| Archivo | Contenido |
|---|---|
| `lectura_segura.c` | Demuestra las 4 formas con un mismo struct |
