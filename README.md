# Kit de Plantillas — Parcial 2 de Programación I (C)

> Kit de referencia en **lenguaje C** para el 2° parcial de **Programación I (UTN FRRe)**.
> Pensado para tenerlo a mano durante el examen y resolver consignas adaptando lo mínimo posible.
>
> **¿Estás cursando algo parecido?** Esto es libre. Forkealo (botón 🍴 arriba a la derecha) y modificalo a tu gusto.

---

## ¿Qué resuelve este kit?

El modelo típico del 2° parcial pide **gestionar registros de una entidad** (productos, libros, alumnos, empleados, etc.) usando:

- `struct` con 3 a 5 campos.
- Arreglo de structs.
- Menú interactivo (`do-while` + `switch`).
- Operaciones: **agregar, buscar, listar, eliminar, modificar, salir**.
- Algún algoritmo de **ordenamiento** (burbuja / selección / inserción).
- Alguna **búsqueda** (lineal / binaria).
- **Validaciones** (no duplicados, existencia previa, opción inválida, etc.).

Este repo te da plantillas listas para cada pieza, más 3 programas completos resueltos como referencia.

---

## ⚡ Cómo usarlo durante el parcial

1. **Leé `GUIA_RAPIDA.md`** primero. Es el mapa "te piden X → usá Y → sumale Z".
2. **Elegí un struct base** en `01_Structs/` (el más parecido a la entidad que pide la consigna).
3. **Tomá `plantilla_base.c`** como esqueleto y reemplazá el struct + nombres de campos.
4. Si necesitás ordenar o buscar, **copiá la función** desde `02_Ordenamientos/` o `03_Busquedas/`.
5. **Validá con el checklist** que está al final de `GUIA_RAPIDA.md` antes de entregar.

---

## 📂 Estructura

| Carpeta / Archivo | Contenido |
|---|---|
| **`plantilla_base.c`** | Esqueleto de programa CRUD completo. Punto de partida. |
| **`GUIA_RAPIDA.md`** | ⭐ Tabla "si te piden X → adaptá Y". **Léelo primero.** |
| **`01_Structs/`** | 7 modelos de struct ya armados (producto, libro, alumno, empleado, vehículo, persona, película). |
| **`02_Ordenamientos/`** | Burbuja, selección e inserción — versiones para `int` y para `struct` (por entero, float y string). |
| **`03_Busquedas/`** | Lineal y binaria (int y struct) + contar ocurrencias. |
| **`04_Operaciones_CRUD/`** | Las 5 operaciones aisladas: agregar, eliminar, modificar, listar, menú interactivo. |
| **`05_Entradas/`** | Lectura segura de int y strings, limpieza de buffer (`scanf` vs `fgets`). |
| **`06_Ejemplos_Completos/`** | 3 programas armados de punta a punta: productos, libros, alumnos con notas. |
| **`07_Modelos_Parcial/`** | Modelos resueltos estilo 2° parcial: orden + búsqueda binaria + doble criterio, CRUD con menú, y arreglo de enteros con estadísticas. |
| **`TIPS_C.md`** | 💡 Funciones por librería (`<...>`) + trampas de C (comillas simples vs dobles, `=` vs `==`, el `\n` de `scanf`, etc.). |
| **`.devcontainer/` + `.vscode/`** | Config lista para **GitHub Codespaces**: gcc, debugger y botón ▶ para compilar/correr sin instalar nada. |

---

## 💻 Usarlo en GitHub Codespaces (recomendado para el parcial)

Este repo ya viene configurado para abrirse en **GitHub Codespaces** (el "VSCode de GitHub" en la nube) con todo listo para compilar y ejecutar C — sin instalar nada en tu compu.

1. En la página del repo en GitHub: botón **`<> Code` → pestaña `Codespaces` → `Create codespace`**.
2. Esperá que levante el contenedor (trae `gcc`, `gdb` y las extensiones automáticamente).
3. Abrí cualquier `.c` y:
   - apretá el botón **▶** (Code Runner) para **compilar y ejecutar**, o
   - apretá **F5** para **debuggear** paso a paso con breakpoints.

> La terminal integrada queda lista para que `scanf` lea lo que escribís. Detalle de la config en `.devcontainer/` y `.vscode/`.

## 🔧 Compilar y ejecutar (terminal)

Cada `.c` compila independientemente:

```bash
gcc -Wall archivo.c -o programa
./programa
```

Por ejemplo, para correr el CRUD completo de productos:

```bash
gcc -Wall 06_Ejemplos_Completos/crud_productos.c -o crud
./crud
```

> Probado con `gcc` en macOS y Linux. Todos los `.c` compilan limpios con `-Wall -Wextra`.

---

## 🍴 Cómo forkearlo

1. Click en **Fork** arriba a la derecha de la página de GitHub.
2. Cloná tu fork:
   ```bash
   git clone git@github.com:TU-USUARIO/kit-parcial-2-programacion-1.git
   ```
3. Modificalo todo lo que quieras — agregá tus propias plantillas, casos de tu cátedra, etc.
4. Si te resultó útil y querés contribuir mejoras al original, mandá un PR. Pero no es necesario — forkealo y úsalo libremente.

---

## 📋 Convenciones del kit

Pensadas para mantener el mismo estilo que el resto del curso UTN FRRe:

- Identificadores y comentarios en **español**.
- `#define MAX 100` arriba de cada archivo.
- Arrays como `tipo arr[]`, tamaño como `int n` aparte. Cuando `n` se modifica, se pasa como `int *n`.
- Strings con `scanf(" %19[^\n]", ...)` (estilo modelo del parcial). Alternativa con `fgets+strcspn` documentada en `05_Entradas/`.
- Sin `typedef`, sin `malloc`, sin punteros raros. Mismo nivel del modelo.
- Funciones **prototipadas arriba**, definidas debajo de `main`.

---

## ❓ Lo que NO está acá (y por qué)

- **Listas enlazadas, pilas, colas, archivos** — no entran al estilo del modelo del 2° parcial.
- **Recursividad / POO** — fuera del scope de este parcial.

Si caen en tu cursada, este repo no te va a servir 100% — pero la base modular del CRUD igual te puede ayudar de esqueleto.

---

## 📝 Licencia

[MIT](./LICENSE) — usalo, forkealo, modificalo, redistribuilo libremente. Cero restricciones.

---

> Hecho como apunte personal de cursada. Si encontrás un error o algo que se puede mejorar, abrí un issue o mandá un PR — es bienvenido pero no obligatorio.
