*This project has been created as part of the 42 curriculum by kcarrero.*

# 🎓 42 Madrid — Student Projects

Bienvenido a mi repositorio de proyectos realizados durante mi formación en **42 Madrid**.

Este repositorio reúne ejercicios y proyectos desarrollados principalmente en **C**, organizados en carpetas independientes. Cada proyecto se centra en conceptos concretos de programación, desde la reimplementación de funciones básicas hasta algoritmos, procesos, gráficos y concurrencia.

> [!IMPORTANT]
> Este archivo funciona como una introducción general y un índice del repositorio. Para consultar la explicación técnica, las instrucciones de compilación, los ejemplos, las pruebas y los recursos de un proyecto, entra en su carpeta y revisa su propio `README.md`.

---

## 🧭 Navegación rápida

Los proyectos están agrupados por etapa para que el índice pueda crecer sin perder claridad.

### ✅ Proyectos disponibles

| Proyecto | Descripción | Estado |
|---|---|---|
| [📚 Libft](./libft/) | Biblioteca personal con funciones de C y utilidades adicionales. | Completado |
| [🖨️ ft_printf](./libftprintf/) | Reimplementación parcial de `printf`. | Completado |
| [📄 Get Next Line](./get_next_line/) | Lectura de un descriptor de archivo línea por línea. | Completado |
| [🧪 Exam02](./exam02/) | Ejercicios de práctica organizados por niveles. | Completado |
| [🔗 Pipex](./pipex/) | Reproducción de una tubería sencilla de Unix. | Completado |
| [🔄 Push Swap](./push_swap/) | Ordenación mediante dos pilas y operaciones limitadas. | Completado |
| [🎮 so_long](./so_long/) | Videojuego 2D desarrollado con MiniLibX. | Completado |
| [🍝 Philosophers](./philosophers/philo/) | Simulación concurrente con hilos y mutexes. | Completado |

### 🚧 Próximos proyectos del Common Core

Esta sección está preparada para añadir los siguientes proyectos sin modificar la estructura general del README.

| Proyecto | Descripción | Estado |
|---|---|---|
| Próximo proyecto | Pendiente de añadir. | Próximamente |
| Próximo proyecto | Pendiente de añadir. | Próximamente |
| Próximo proyecto | Pendiente de añadir. | Próximamente |
| Próximo proyecto | Pendiente de añadir. | Próximamente |

> [!TIP]
> Para añadir un proyecto nuevo, sustituye una fila de la tabla por un enlace relativo:
>
> ```md
> | [📦 Nombre del proyecto](./carpeta_del_proyecto/) | Breve descripción. | Completado |
> ```

### 🧩 Plantilla para nuevos proyectos

Cada proyecto nuevo puede añadirse siguiendo este formato:

```md
| [EMOJI Nombre](./nombre_de_la_carpeta/) | Descripción breve del proyecto. | Estado |
```

Ejemplo:

```md
| [🌐 Nuevo proyecto](./nuevo_proyecto/) | Descripción breve. | En progreso |
```

Los enlaces deben ser relativos a la raíz del repositorio para que funcionen tanto en GitHub como después de clonar el proyecto.

---

## 📂 Estructura general

```text
42Madrid_Student/
├── exam02/
├── get_next_line/
├── libft/
├── libftprintf/
├── philosophers/
│   └── philo/
├── pipex/
├── push_swap/
├── so_long/
├── futuro_proyecto_01/
├── futuro_proyecto_02/
└── README.md
```

Cada carpeta se mantiene como un proyecto independiente y puede incluir:

```text
proyecto/
├── includes/
├── srcs/
├── Makefile
└── README.md
```

La estructura exacta depende de las necesidades de cada proyecto.

---

## 🚀 Cómo utilizar este repositorio

### Clonar el repositorio

```bash
git clone https://github.com/Kentliel/42Madrid_Student.git
cd 42Madrid_Student
```

Si también se necesitan los submódulos configurados en el repositorio:

```bash
git clone --recurse-submodules \
    https://github.com/Kentliel/42Madrid_Student.git
```

### Entrar en un proyecto

Ejemplo:

```bash
cd push_swap
```

### Consultar su documentación

Desde la terminal:

```bash
cat README.md
```

O abre el archivo `README.md` directamente desde GitHub.

### Compilar

La mayoría de los proyectos utilizan un `Makefile`:

```bash
make
```

Los objetivos más habituales son:

| Comando | Acción |
|---|---|
| `make` | Compila el proyecto. |
| `make clean` | Elimina los archivos objeto. |
| `make fclean` | Elimina objetos y ejecutables o bibliotecas generadas. |
| `make re` | Realiza una recompilación completa. |

> [!NOTE]
> Los requisitos, dependencias y comandos de ejecución pueden variar. Consulta siempre el README específico antes de compilar un proyecto.

---

## 🧠 Áreas de aprendizaje

A lo largo del repositorio se trabajan progresivamente distintas áreas:

### 🔤 Fundamentos de C

- Punteros y arrays.
- Strings y bloques de memoria.
- Asignación dinámica.
- Listas enlazadas.
- Bibliotecas estáticas.
- Modularización y archivos de cabecera.

### 🐧 Programación de sistemas Unix

- Descriptores de archivo.
- Lectura y escritura.
- Procesos e hilos.
- Tuberías y redirecciones.
- Ejecución de programas.
- Sincronización y exclusión mutua.

### 🧩 Algoritmos y estructuras de datos

- Pilas.
- Búsqueda en anchura.
- Ordenación.
- Normalización de valores.
- Manipulación de bits.
- Análisis y reducción de operaciones.

### 🖼️ Programación gráfica

- Ventanas y eventos.
- Renderizado mediante tiles.
- Imágenes XPM.
- Gestión de teclado.
- Representación gráfica de mapas.

---

## 🛤️ Ruta de aprendizaje

La ruta actual puede ampliarse conforme avance el Common Core:

```text
Fundamentos de C
    ├── Libft
    ├── ft_printf
    └── Get Next Line
          ↓
Algoritmos y práctica
    ├── Exam02
    └── Push Swap
          ↓
Sistemas Unix
    └── Pipex
          ↓
Programación gráfica
    └── so_long
          ↓
Concurrencia
    └── Philosophers
          ↓
Próximos proyectos del Common Core
    ├── Proyecto futuro
    ├── Proyecto futuro
    └── Proyecto futuro
```

Esta organización no depende de un número fijo de proyectos. Para ampliar la ruta basta con añadir una nueva línea dentro del bloque correspondiente.

---

## 📘 Documentación de cada proyecto

Dentro de cada proyecto, su `README.md` puede incluir:

- Una descripción del objetivo.
- Los conceptos técnicos utilizados.
- La estructura de archivos.
- Instrucciones de compilación y ejecución.
- Ejemplos de uso.
- Casos de prueba.
- Decisiones técnicas.
- Recursos de consulta.
- Una explicación transparente del uso de inteligencia artificial cuando corresponda.

La documentación específica tiene prioridad sobre la información resumida en este índice.

---

## ⚠️ Aviso académico

Este repositorio tiene una finalidad educativa y representa mi proceso de aprendizaje dentro de 42 Madrid.

El código puede utilizarse como referencia para estudiar conceptos, comparar enfoques o comprender la estructura de los proyectos. Sin embargo, copiar una solución sin comprenderla contradice el objetivo pedagógico de 42.

La mejor forma de utilizar este repositorio es:

1. Leer primero el enunciado oficial.
2. Intentar diseñar una solución propia.
3. Consultar documentación técnica.
4. Utilizar este código únicamente como referencia.
5. Probar, depurar y comprender cada decisión.

---

## 🛠️ Tecnologías y herramientas

Las tecnologías principales utilizadas en el repositorio son:

- **C**
- **Make**
- **Git y GitHub**
- **Unix / Linux**
- **POSIX**
- **MiniLibX**
- **GDB**
- **Valgrind**
- **Norminette**

Las herramientas concretas dependen de cada proyecto.

---

## ➕ Cómo añadir un proyecto nuevo

1. Crea la carpeta del proyecto en la raíz del repositorio.
2. Añade su propio archivo `README.md`.
3. Incorpora una fila en la sección **Proyectos disponibles**.
4. Utiliza un enlace relativo con este formato:

```md
[Nombre del proyecto](./nombre_de_la_carpeta/)
```

5. Actualiza el árbol de carpetas y la ruta de aprendizaje si es necesario.

### Ejemplo completo

```md
| [🧵 Nuevo proyecto](./nuevo_proyecto/) | Descripción breve del proyecto. | En progreso |
```

Gracias a los enlaces relativos, no es necesario modificar la URL completa del repositorio.

---

## 👤 Autor

**kcarrero** — Estudiante de 42 Madrid

- GitHub: [Kentliel](https://github.com/Kentliel)
- Repositorio: [42Madrid_Student](https://github.com/Kentliel/42Madrid_Student)

---

## 📌 Nota final

Este repositorio continuará evolucionando a medida que se añadan nuevos proyectos, mejoras, pruebas y documentación.

Para obtener información detallada sobre un proyecto concreto, selecciona su carpeta en la sección [Navegación rápida](#-navegación-rápida) y consulta el `README.md` correspondiente.
