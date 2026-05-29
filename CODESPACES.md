# 💻 Cómo abrir este repo para programar C (GitHub Codespaces)

> Guía rápida para el día del parcial. **Leé primero el ⚠️ de abajo: tocar `.` NO sirve.**

---

## ⚠️ Tocar `.` (punto) NO te sirve para C

Hay **dos** "VSCode de GitHub" y son distintos:

| | Tocar `.` → `github.dev` | **Codespaces** ✅ |
|---|---|---|
| Qué es | Editor web liviano | Contenedor completo en la nube |
| Terminal | ❌ No tiene | ✅ Sí |
| Compilador `gcc` / `gdb` | ❌ No | ✅ Sí (lo instala solo) |
| Botón ▶ / F5 para correr C | ❌ No anda | ✅ Sí |
| Usa la config de este repo | ❌ La ignora | ✅ La usa |

Si tocás `.` solo podés **editar y leer** archivos: **no podés compilar ni ejecutar**. Para el parcial necesitás **Codespaces**.

---

## ✅ Pasos para abrir el Codespace

1. En la página del repo en GitHub: botón verde **`<> Code`**.
2. Pestaña **`Codespaces`**.
3. **`Create codespace on main`**.
4. Esperá ~1-2 min a que levante (instala `gcc`, `gdb` y las extensiones solo, gracias a `.devcontainer/`).
5. Abrí cualquier `.c` y:
   - botón **▶** (arriba a la derecha) → **compila y ejecuta** en la terminal, o
   - tecla **F5** → **debug** paso a paso con breakpoints.

La terminal integrada queda lista para que `scanf` lea lo que escribís.

---

## 🛠️ Si preferís la terminal (siempre funciona)

```bash
gcc -Wall -Wextra archivo.c -o programa
./programa
```

Con `<math.h>` (sqrt, pow…), agregá `-lm`:

```bash
gcc -Wall -Wextra archivo.c -o programa -lm
```

---

## 💡 Consejos para no perder tiempo en el examen

- **Probá el Codespace ANTES del parcial.** La primera vez tarda en construir el contenedor; si lo creás antes, el día del examen arranca al toque.
- **Codespaces gratis** tiene un límite de horas/mes (suele sobrar). Al terminar, apagalo: `<> Code → Codespaces → Stop codespace`.
- Si el botón ▶ no aparece, esperá a que termine de instalarse la extensión **Code Runner** (unos segundos la primera vez).
- ¿Dudas de C? Mirá `TIPS_C.md` y `GUIA_RAPIDA.md`.
