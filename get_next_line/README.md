*Este proyecto ha sido creado como parte del currículo de 42 por kcarrero.*

📖 # get_next_line

📝 ## Descripción

`get_next_line` es un proyecto de programación en C cuyo objetivo es implementar una función capaz de leer y devolver, en cada llamada, la siguiente línea disponible desde un descriptor de archivo.

La función trabaja con archivos, la entrada estándar y cualquier otro recurso que pueda leerse mediante un descriptor válido. Cada llamada devuelve una única línea, incluyendo el carácter de salto de línea (`\n`) cuando este existe. Al alcanzar el final del archivo o producirse un error, devuelve `NULL`.

La firma de la función es:

```c
char	*get_next_line(int fd);
```

El proyecto permite practicar conceptos fundamentales de programación en C:

- Uso de descriptores de archivo.
- Lectura mediante la llamada al sistema `read`.
- Gestión dinámica de memoria con `malloc` y `free`.
- Variables estáticas y persistencia de datos entre llamadas.
- Manipulación de cadenas.
- Prevención de fugas de memoria.
- Compilación con un tamaño de búfer configurable.

La carpeta `bonus` incluye una versión capaz de conservar una caché independiente para varios descriptores de archivo y, por tanto, permite alternar la lectura de varios archivos sin perder el estado de ninguno.

✨ ## Características

- Lectura de una línea por llamada.
- Compatibilidad con distintos valores de `BUFFER_SIZE`.
- Conservación del contenido leído que pertenece a la siguiente línea.
- Inclusión de `\n` en la línea devuelta cuando está presente.
- Gestión del final de archivo sin salto de línea final.
- Liberación de la memoria intermedia cuando deja de ser necesaria.
- Versión bonus compatible con múltiples descriptores de archivo.

🗂️ ## Estructura del proyecto

```text
get_next_line/
├── Makefile
├── includes/
│   └── get_next_line.h
├── srcs/
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   ├── main.c
│   └── prueba.txt
└── bonus/
    ├── get_next_line_bonus.c
    ├── get_next_line_bonus.h
    ├── get_next_line_utils_bonus.c
    ├── main.c
    ├── archivo1.txt
    └── archivo2.txt
```

Los archivos `main.c` y los archivos de texto se utilizan únicamente para realizar pruebas. No forman parte de la función que debe entregarse como implementación del proyecto.

🧠 ## Algoritmo seleccionado

💡 ### Idea general

La implementación utiliza un algoritmo de **lectura incremental con caché persistente**.

`read` no garantiza que una llamada devuelva una línea completa. Puede devolver menos caracteres, varias líneas a la vez o una parte de una línea. Por este motivo, la función mantiene una caché que almacena los datos leídos que todavía no se han devuelto.

El algoritmo se divide en cuatro fases principales:

1. Leer bloques de tamaño `BUFFER_SIZE`.
2. Acumular los bloques en una caché hasta encontrar `\n` o llegar al final del archivo.
3. Extraer de la caché la siguiente línea.
4. Conservar el contenido sobrante para la siguiente llamada.

✅ ### 1. Validación inicial

`get_next_line` comprueba que:

- El descriptor de archivo sea válido.
- `BUFFER_SIZE` sea mayor que cero.
- El descriptor esté dentro del límite contemplado por la implementación.

Si alguna condición no se cumple, la función devuelve `NULL`.

📥 ### 2. Lectura y construcción de la caché

La función auxiliar `ft_read_and_cache` comprueba si la caché ya contiene un salto de línea.

Mientras no exista un `\n`, se realizan los siguientes pasos:

1. Se reserva un búfer de `BUFFER_SIZE + 1` bytes.
2. Se llama a `read(fd, buffer, BUFFER_SIZE)`.
3. Se añade `'\0'` al final de los bytes leídos.
4. El contenido del búfer se copia o concatena con la caché.
5. Se libera el búfer temporal.
6. El proceso continúa hasta encontrar una línea completa o alcanzar el final del archivo.

Cuando `read` devuelve `0`, se ha alcanzado el final del archivo. En ese caso, la caché existente todavía puede contener una última línea sin `\n`, que debe devolverse antes de finalizar.

Si `read` devuelve un valor negativo, se considera un error de lectura y se libera la memoria asociada.

✂️ ### 3. Extracción de la línea

`ft_extract_line` recorre la caché desde el principio hasta encontrar:

- Un salto de línea.
- El carácter nulo que marca el final de la cadena.

Después reserva memoria para la línea, copia los caracteres correspondientes y añade el terminador `'\0'`.

Cuando existe un salto de línea, este se incluye en la cadena devuelta.

Ejemplo:

```text
Caché:          "Primera línea\nSegunda línea\n"
Línea devuelta: "Primera línea\n"
```

La memoria de la línea pertenece a quien llama a `get_next_line`, por lo que debe liberarse con `free`.

🔄 ### 4. Actualización de la caché

Después de extraer la línea, `ft_update_cache` elimina de la caché la parte que ya se ha devuelto.

El contenido posterior al primer `\n` se copia a una nueva zona de memoria:

```text
Caché anterior: "Primera línea\nSegunda línea\n"
Nueva caché:    "Segunda línea\n"
```

Si no queda ningún contenido pendiente, la caché se libera y pasa a ser `NULL`.

💾 ### 5. Persistencia entre llamadas

En la parte obligatoria se utiliza una variable estática:

```c
static char	*cache;
```

Una variable estática conserva su valor entre llamadas. Gracias a ello, el contenido leído de más no se pierde cuando `get_next_line` devuelve una línea.

En la versión bonus se utiliza un array de cachés:

```c
static char	*cache[1024];
```

Cada descriptor dispone de su propio espacio de almacenamiento. Esto permite alternar llamadas como:

```c
line1 = get_next_line(fd1);
line2 = get_next_line(fd2);
line1 = get_next_line(fd1);
```

sin mezclar el contenido pendiente de los distintos archivos.

🎯 ## Justificación del algoritmo

La estrategia de lectura incremental con caché se ha elegido porque responde directamente al comportamiento de `read`.

Una lectura basada únicamente en llamadas individuales a `read` no sería suficiente, ya que:

- Una línea puede ser mayor que `BUFFER_SIZE`.
- Un bloque puede contener varias líneas.
- Un bloque puede terminar en mitad de una línea.
- La última línea puede no terminar en `\n`.

La caché resuelve estos casos al separar el proceso de lectura del proceso de devolución de líneas. La función lee únicamente hasta disponer de suficiente información para construir la siguiente línea y conserva el resto para futuras llamadas.

Esta solución también permite modificar `BUFFER_SIZE` sin cambiar el comportamiento observable de la función. Un búfer pequeño provoca más llamadas a `read`, mientras que uno grande puede leer varias líneas de una vez, pero el resultado devuelto al programa sigue siendo una línea por llamada.

La variable estática es adecuada porque evita que el programa que utiliza `get_next_line` tenga que gestionar manualmente el estado interno de la lectura.

📊 ## Complejidad

Sea `n` la cantidad de caracteres acumulados para producir una línea.

- 💾 **Espacio auxiliar:** `O(n + BUFFER_SIZE)`.
- 🔍 **Búsqueda del salto de línea:** `O(n)`.
- ✂️ **Extracción de la línea:** `O(n)`.
- 🔄 **Actualización de la caché:** `O(n)` en el peor caso.

La implementación realiza nuevas reservas y copias al concatenar cada bloque con la caché. Por ello, para líneas muy largas y valores pequeños de `BUFFER_SIZE`, el coste acumulado de las concatenaciones puede aproximarse a `O(n²)`.

En la versión bonus, la memoria total depende de la suma del contenido pendiente en todos los descriptores activos.

🛠️ ## Instrucciones

📋 ### Requisitos

Para compilar y probar el proyecto se necesita:

- Un sistema compatible con llamadas POSIX.
- Un compilador de C, como `cc`, `clang` o `gcc`.
- Las funciones estándar `read`, `malloc` y `free`.

📦 ### Descargar el repositorio

```bash
git clone https://github.com/Kentliel/42Madrid_Student.git
cd 42Madrid_Student/get_next_line
```

⚙️ ### Compilar la parte obligatoria

La implementación puede compilarse junto con el archivo de prueba incluido:

```bash
cc -Wall -Wextra -Werror \
	-D BUFFER_SIZE=42 \
	-I includes \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c \
	srcs/main.c \
	-o gnl
```

▶️ ### Ejecutar la prueba

```bash
./gnl srcs/prueba.txt
```

También se puede utilizar cualquier otro archivo:

```bash
./gnl ruta/al/archivo.txt
```

🧪 ### Probar distintos tamaños de búfer

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 \
	-I includes \
	srcs/get_next_line.c srcs/get_next_line_utils.c srcs/main.c \
	-o gnl_buffer_1
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 \
	-I includes \
	srcs/get_next_line.c srcs/get_next_line_utils.c srcs/main.c \
	-o gnl_buffer_9999
```

El comportamiento funcional debe mantenerse independientemente del tamaño elegido, siempre que `BUFFER_SIZE` sea mayor que cero.

⭐ ### Compilar la versión bonus

```bash
cc -Wall -Wextra -Werror \
	-D BUFFER_SIZE=42 \
	-I bonus \
	bonus/get_next_line_bonus.c \
	bonus/get_next_line_utils_bonus.c \
	bonus/main.c \
	-o gnl_bonus
```

🚀 ### Ejecutar la versión bonus

```bash
./gnl_bonus bonus/archivo1.txt bonus/archivo2.txt
```

El programa de prueba alterna la lectura de los archivos proporcionados y muestra las líneas obtenidas desde cada descriptor.

💻 ### Uso dentro de otro programa

```c
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		write(1, line, ft_strlen_gnl(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Compilación:

```bash
cc -Wall -Wextra -Werror \
	-D BUFFER_SIZE=42 \
	-I includes \
	programa.c srcs/get_next_line.c srcs/get_next_line_utils.c \
	-o programa
```

🏗️ ## Makefile

El `Makefile` incluido está preparado para crear la biblioteca estática `get_next_line.a`, pero actualmente hace referencia a estos nombres:

```make
srcs/ft_get_next_line.c
srcs/ft_get_next_line_utils.c
```

Los archivos presentes en el repositorio se llaman:

```make
srcs/get_next_line.c
srcs/get_next_line_utils.c
```

Para poder utilizar `make`, las variables `SRCS` y `OBJS` deben coincidir con los nombres reales:

```make
SRCS = srcs/get_next_line.c \
       srcs/get_next_line_utils.c

OBJS = objs/get_next_line.o \
       objs/get_next_line_utils.o
```

Después de realizar esa corrección:

```bash
make
make BUFFER_SIZE=1
make clean
make fclean
make re
```

↩️ ## Valor de retorno

`get_next_line` devuelve:

- ✅ La siguiente línea leída, incluyendo `\n` cuando existe.
- ✅ La última línea aunque no termine con `\n`.
- 🛑 `NULL` cuando se alcanza el final del archivo y no queda contenido pendiente.
- ⚠️ `NULL` cuando se produce un error de lectura o de reserva de memoria.

Toda cadena devuelta correctamente debe liberarse:

```c
char	*line;

line = get_next_line(fd);
if (line)
{
	/* Utilizar la línea. */
	free(line);
}
```

🧪 ## Casos de prueba recomendados

Se recomienda probar la función con:

- Un archivo vacío.
- Un archivo con una sola línea.
- Una línea sin salto de línea final.
- Varias líneas cortas.
- Una línea mucho mayor que `BUFFER_SIZE`.
- Varias líneas vacías consecutivas.
- `BUFFER_SIZE=1`.
- Un `BUFFER_SIZE` muy grande.
- Un descriptor inválido.
- Lectura desde la entrada estándar.
- Varios descriptores alternados en la versión bonus.

Ejemplo con la entrada estándar:

```c
char	*line;

line = get_next_line(STDIN_FILENO);
while (line)
{
	write(STDOUT_FILENO, line, ft_strlen_gnl(line));
	free(line);
	line = get_next_line(STDIN_FILENO);
}
```

🔎 ## Observaciones técnicas

- La parte obligatoria conserva una única caché estática y está diseñada para continuar la lectura del descriptor utilizado.
- La versión bonus utiliza un array de 1024 cachés.
- Para evitar un acceso fuera de los límites del array bonus, la validación del descriptor debería rechazar valores mayores o iguales que `1024`.
- Los programas `main.c` son herramientas de prueba y no deben incluirse en la entrega mínima si el subject solicita únicamente los archivos de la función.
- El ejecutable `srcs/a.out` es un archivo generado y normalmente debería excluirse del repositorio mediante `.gitignore`.

📚 ## Recursos

🔗 ### Documentación

- [`read(2)` — Linux manual page](https://man7.org/linux/man-pages/man2/read.2.html): documentación de la llamada al sistema utilizada para leer desde un descriptor.
- [`open(2)` — Linux manual page](https://man7.org/linux/man-pages/man2/open.2.html): apertura de archivos y obtención de descriptores.
- [`close(2)` — Linux manual page](https://man7.org/linux/man-pages/man2/close.2.html): cierre correcto de descriptores.
- [`malloc(3)` — Linux manual page](https://man7.org/linux/man-pages/man3/malloc.3.html): reserva y liberación dinámica de memoria.
- [Storage duration — cppreference](https://en.cppreference.com/w/c/language/storage_duration.html): explicación de la duración estática y de las variables que conservan su valor entre llamadas.
- [File descriptor — The Open Group Base Specifications](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap03.html): definición de descriptor de archivo en POSIX.

🤖 ### Uso de inteligencia artificial

Como recurso de aprendizaje y asistencia durante el desarrollo de este proyecto. En concreto, la IA se utilizó para:

- Comprender el funcionamiento de conceptos nuevos relacionados con get_next_line, como el uso de variables estáticas, descriptores de archivo, BUFFER_SIZE y la función read.
- Aclarar el propósito y el comportamiento de funciones concretas de la implementación.
- Entender cómo gestionar casos especiales, como archivos vacíos, líneas sin salto de línea final, errores de lectura y distintos tamaños de búfer.
- Analizar el funcionamiento de la versión bonus y el uso de una caché independiente para cada descriptor de archivo.

Para la documentación de este proyecto se ha utilizado inteligencia artificial como apoyo en las siguientes tareas:

- Revisión de la estructura pública del repositorio.
- Análisis y explicación del algoritmo ya implementado.
- Identificación de instrucciones de compilación coherentes con los nombres reales de los archivos.
- Detección de observaciones técnicas relacionadas con el `Makefile` y los límites de los descriptores.

Durante esta revisión, la inteligencia artificial no ha modificado los archivos fuente de la implementación. Toda la implementación final y la comprensión del código fueron realizadas por el autor.
