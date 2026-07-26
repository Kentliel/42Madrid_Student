*This project has been created as part of the 42 curriculum by kcarrero.*

# 🔗 Pipex

## 📖 Descripción

**Pipex** es un proyecto de programación en C cuyo objetivo es reproducir el comportamiento de una tubería sencilla de Unix.

El programa recibe un archivo de entrada, dos comandos y un archivo de salida. Después, crea dos procesos conectados mediante un `pipe`, de forma que la salida del primer comando se convierte en la entrada del segundo.

La ejecución:

```bash
./pipex file1 "cmd1" "cmd2" file2
```

reproduce el flujo de datos de la siguiente instrucción de shell:

```bash
< file1 cmd1 | cmd2 > file2
```

Este proyecto permite profundizar en conceptos fundamentales de los sistemas Unix:

- 🔄 Creación y comunicación entre procesos.
- 🚰 Uso de tuberías mediante `pipe`.
- 🧬 Creación de procesos hijos con `fork`.
- 🔀 Redirección de entrada y salida con `dup2`.
- ⚙️ Sustitución de procesos mediante `execve`.
- 🔍 Búsqueda de ejecutables utilizando la variable `PATH`.
- ⏳ Sincronización y recogida de estados con `waitpid`.
- 📁 Gestión de archivos y descriptores.
- 🧹 Gestión de memoria y tratamiento de errores.

> [!NOTE]
> La versión incluida en este repositorio corresponde a la parte obligatoria del proyecto y conecta exactamente dos comandos.

## 🎯 Objetivo

El objetivo principal es comprender cómo una shell conecta procesos y redirige sus entradas y salidas.

Para ello, el programa debe:

1. Abrir el archivo de entrada.
2. Crear una tubería.
3. Ejecutar el primer comando leyendo desde el archivo de entrada.
4. Enviar su salida al extremo de escritura de la tubería.
5. Ejecutar el segundo comando leyendo desde el extremo de lectura.
6. Redirigir el resultado al archivo de salida.
7. Cerrar los descriptores que ya no sean necesarios.
8. Esperar a que terminen los procesos hijos.

## 🧠 Funcionamiento

```text
                    pipe_fd[0]       pipe_fd[1]
                        ▲                 │
                        │                 ▼
┌─────────┐       ┌───────────┐     ┌───────────┐       ┌──────────┐
│  file1  │ ───▶  │   cmd1    │ ──▶ │   cmd2    │ ───▶  │  file2   │
└─────────┘       └───────────┘     └───────────┘       └──────────┘
   entrada           proceso 1        proceso 2             salida
```

### Primer proceso hijo

```text
file1 → STDIN → cmd1 → STDOUT → pipe
```

El primer proceso redirige:

- El archivo de entrada hacia `STDIN_FILENO`.
- El extremo de escritura de la tubería hacia `STDOUT_FILENO`.

### Segundo proceso hijo

```text
pipe → STDIN → cmd2 → STDOUT → file2
```

El segundo proceso redirige:

- El extremo de lectura de la tubería hacia `STDIN_FILENO`.
- El archivo de salida hacia `STDOUT_FILENO`.

### Proceso padre

El proceso padre cierra los descriptores que no necesita y espera la finalización de ambos hijos mediante `waitpid`.

## ✨ Características

- Ejecución de dos comandos enlazados mediante una tubería.
- Búsqueda de comandos en las rutas incluidas en `PATH`.
- Compatibilidad con rutas directas a ejecutables.
- Redirección de entrada y salida.
- Creación del archivo de salida si no existe.
- Sobrescritura del archivo de salida mediante `O_TRUNC`.
- Gestión de comandos inexistentes.
- Gestión de errores de apertura, `pipe`, `fork`, `dup2` y `execve`.
- Uso de `/dev/null` cuando el archivo de entrada no puede abrirse.
- Propagación del código de salida de los procesos ejecutados.
- Integración de la biblioteca personal `libft`.

## 📂 Estructura del proyecto

```text
pipex/
├── includes/
│   └── pipex.h
├── libft/
│   ├── includes/
│   ├── srcs/
│   └── Makefile
├── srcs/
│   ├── child_process.c
│   ├── find_executable.c
│   ├── main.c
│   └── utils.c
└── Makefile
```

| Archivo | Responsabilidad |
|---|---|
| `srcs/main.c` | Valida los argumentos, abre los archivos, crea la tubería, lanza los procesos y recoge sus estados. |
| `srcs/child_process.c` | Crea los procesos hijos, configura las redirecciones y ejecuta los comandos. |
| `srcs/find_executable.c` | Localiza un ejecutable directamente o recorriendo las rutas de `PATH`. |
| `srcs/utils.c` | Separa los comandos en argumentos y libera matrices de cadenas. |
| `includes/pipex.h` | Contiene la estructura principal, las cabeceras y los prototipos. |
| `libft/` | Biblioteca personal utilizada por el proyecto. |
| `Makefile` | Automatiza la compilación y la limpieza de archivos generados. |

## 🛠️ Instrucciones

### Requisitos

Para compilar y ejecutar el proyecto se necesita:

- Un sistema compatible con Unix, como Linux o macOS.
- Un compilador de C, como `cc`, `gcc` o `clang`.
- La herramienta `make`.
- Los comandos de Unix utilizados en las pruebas, como `grep`, `wc`, `cat` o `tr`.

### Clonar el repositorio

```bash
git clone https://github.com/Kentliel/42Madrid_Student.git
cd 42Madrid_Student/pipex
```

### Compilar

```bash
make
```

El proyecto se compila con las opciones:

```text
-Wall -Wextra -Werror
```

La compilación genera el ejecutable:

```text
pipex
```

### Objetivos del Makefile

```bash
make
```

Compila `libft` y genera el ejecutable `pipex`.

```bash
make clean
```

Elimina los archivos objeto.

```bash
make fclean
```

Elimina los archivos objeto, el ejecutable y los archivos generados por `libft`.

```bash
make re
```

Realiza una recompilación completa.

## 🚀 Uso

La sintaxis del programa es:

```bash
./pipex file1 "cmd1" "cmd2" file2
```

| Argumento | Descripción |
|---|---|
| `file1` | Archivo utilizado como entrada estándar del primer comando. |
| `cmd1` | Primer comando, junto con sus argumentos. |
| `cmd2` | Segundo comando, junto con sus argumentos. |
| `file2` | Archivo en el que se guarda la salida del segundo comando. |

Los comandos deben escribirse entre comillas cuando contienen argumentos:

```bash
./pipex infile "grep hola" "wc -l" outfile
```

## 🧪 Ejemplos

### Contar líneas que contienen una palabra

Crear un archivo de prueba:

```bash
printf "hola\nmundo\nhola 42\n" > infile
```

Ejecutar Pipex:

```bash
./pipex infile "grep hola" "wc -l" outfile
cat outfile
```

Resultado esperado:

```text
2
```

Comando equivalente en la shell:

```bash
< infile grep hola | wc -l > outfile_shell
```

Comparar ambos resultados:

```bash
diff outfile outfile_shell
```

Si no se muestra ninguna diferencia, ambos archivos contienen el mismo resultado.

### Contar palabras

```bash
printf "uno dos tres\ncuatro cinco\n" > infile
./pipex infile "cat" "wc -w" outfile
cat outfile
```

Resultado esperado:

```text
5
```

### Usar una ruta absoluta

```bash
./pipex infile "/bin/cat" "wc -l" outfile
```

### Transformar texto

```bash
printf "pipex\nes genial\n" > infile
./pipex infile "grep pipex" "tr a-z A-Z" outfile
cat outfile
```

Resultado esperado:

```text
PIPEX
```

## ⚠️ Consideraciones

- El programa necesita exactamente cuatro argumentos además del nombre del ejecutable.
- El archivo de salida se crea con permisos `0644` si no existe.
- Si ya existe, su contenido se sobrescribe.
- La implementación ejecuta directamente los programas con `execve`; no lanza una shell.
- Los operadores de shell como `|`, `>`, `<`, `&&`, las expansiones de variables y los comodines no se interpretan dentro de los comandos.
- Los comandos se dividen utilizando espacios, por lo que no se procesan comillas internas ni argumentos complejos que contengan espacios.
- Es importante cerrar correctamente todos los descriptores para evitar bloqueos o fugas de recursos.

## 🧪 Pruebas recomendadas

Se recomienda comprobar:

- Un archivo de entrada válido.
- Un archivo de entrada inexistente.
- Un comando inexistente.
- Una ruta absoluta válida.
- Un archivo de salida sin permisos.
- Comandos sin argumentos.
- Comandos con varios argumentos simples.
- Archivos vacíos.
- Entradas de gran tamaño.
- El código de salida del programa.
- Posibles fugas de memoria y descriptores abiertos.

### Comparación automática con la shell

```bash
printf "alpha\nbeta\nalpha 42\n" > infile

./pipex infile "grep alpha" "wc -l" pipex_output
< infile grep alpha | wc -l > shell_output

diff pipex_output shell_output
```

### Comprobar fugas de memoria en Linux

```bash
valgrind --leak-check=full --show-leak-kinds=all \
    --track-fds=yes ./pipex infile "grep alpha" "wc -l" outfile
```

### Comprobar el estilo

```bash
norminette includes srcs libft
```

## 🔧 Funciones principales utilizadas

| Función | Finalidad |
|---|---|
| `open` | Abre los archivos de entrada y salida. |
| `close` | Cierra descriptores de archivo. |
| `pipe` | Crea el canal de comunicación entre procesos. |
| `fork` | Crea un nuevo proceso hijo. |
| `dup2` | Redirige la entrada o salida estándar. |
| `execve` | Sustituye el proceso hijo por el comando solicitado. |
| `access` | Comprueba si una ruta apunta a un ejecutable accesible. |
| `waitpid` | Espera a un proceso hijo y obtiene su estado. |
| `perror` | Muestra mensajes asociados a errores del sistema. |
| `exit` | Finaliza un proceso con un código de salida. |
| `malloc` / `free` | Gestionan memoria dinámica. |

## 📚 Recursos

### Documentación clásica

- [Linux man-pages: pipe(2)](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [Linux man-pages: fork(2)](https://man7.org/linux/man-pages/man2/fork.2.html)
- [Linux man-pages: dup2(2)](https://man7.org/linux/man-pages/man2/dup.2.html)
- [Linux man-pages: execve(2)](https://man7.org/linux/man-pages/man2/execve.2.html)
- [Linux man-pages: waitpid(2)](https://man7.org/linux/man-pages/man2/wait.2.html)
- [Linux man-pages: open(2)](https://man7.org/linux/man-pages/man2/open.2.html)
- [Linux man-pages: access(2)](https://man7.org/linux/man-pages/man2/access.2.html)
- [GNU Bash Manual: Pipelines](https://www.gnu.org/software/bash/manual/html_node/Pipelines.html)
- [The Open Group: Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)
- [Beej's Guide to Unix IPC](https://beej.us/guide/bgipc/)
- [Norminette de 42](https://github.com/42School/norminette)

También se consultaron las páginas de manual disponibles desde la terminal:

```bash
man 2 pipe
man 2 fork
man 2 dup2
man 2 execve
man 2 waitpid
man 2 open
man 2 access
```

### 🤖 Uso de inteligencia artificial

La inteligencia artificial se utilizó como **herramienta de apoyo al aprendizaje y a la documentación**, concretamente para:

- Obtener explicaciones conceptuales sobre procesos, tuberías y descriptores de archivo.
- Comprender el flujo de ejecución entre el proceso padre y los dos procesos hijos.
- Aclarar el funcionamiento y la relación entre `pipe`, `fork`, `dup2`, `execve` y `waitpid`.
- Analizar fragmentos del código para entender el propósito de cada función y detectar puntos que requerían una revisión más detallada.
- Explicar la búsqueda de ejecutables mediante la variable de entorno `PATH`.
- Revisar conceptos relacionados con códigos de salida, cierre de descriptores y gestión de errores.
- Proponer casos de prueba y situaciones límite para verificar el comportamiento del programa.

Las explicaciones obtenidas mediante IA se utilizaron como referencia educativa y se contrastaron con las páginas de manual y la documentación técnica indicadas anteriormente. La implementación, las pruebas y las decisiones finales del proyecto fueron revisadas y comprendidas por el autor.

## 👤 Autor

- **kcarrero** — Estudiante de 42 Madrid
