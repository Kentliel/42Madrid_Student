*Este proyecto ha sido creado como parte del currículo de 42 por kcarrero.*

# 🖨️ ft_printf

> Porque `ft_putnbr()` y `ft_putstr()` no son suficientes.

## 📌 Descripción

`ft_printf` es una reimplementación parcial de la función `printf()` de la biblioteca estándar de C.

El objetivo del proyecto es crear una función capaz de interpretar una cadena de formato, procesar una cantidad variable de argumentos e imprimir cada valor según el especificador indicado.

La función principal tiene la siguiente firma:

```c
int	ft_printf(const char *format, ...);
```

La implementación genera una biblioteca estática llamada `libftprintf.a`, que puede enlazarse con otros programas escritos en C.

Durante el proyecto se trabajan conceptos como:

- Funciones variádicas y uso de `<stdarg.h>`.
- Interpretación de cadenas de formato.
- Conversión de números entre distintas bases.
- Escritura en la salida estándar con `write`.
- Gestión dinámica de memoria.
- Diseño modular.
- Creación y enlazado de bibliotecas estáticas.
- Uso de Makefiles.

> Esta implementación cubre las conversiones obligatorias del proyecto. No implementa flags, anchura de campo, precisión ni modificadores de longitud.

---

## 🎯 Conversiones soportadas

| Especificador | Tipo esperado | Descripción |
| :---: | :--- | :--- |
| `%c` | `int` | Imprime un carácter. |
| `%s` | `char *` | Imprime una cadena de caracteres. |
| `%p` | `void *` | Imprime la dirección de un puntero en hexadecimal, precedida por `0x`. |
| `%d` | `int` | Imprime un entero decimal con signo. |
| `%i` | `int` | Imprime un entero decimal con signo. |
| `%u` | `unsigned int` | Imprime un entero decimal sin signo. |
| `%x` | `unsigned int` | Imprime un número hexadecimal en minúsculas. |
| `%X` | `unsigned int` | Imprime un número hexadecimal en mayúsculas. |
| `%%` | Sin argumento | Imprime el carácter `%`. |

La función también gestiona algunos casos especiales:

- Una cadena `NULL` se representa como `(null)`.
- Un puntero nulo se representa como `(nil)`.
- Los valores hexadecimales distintos de cero se escriben utilizando las bases `0123456789abcdef` o `0123456789ABCDEF`.

---

## 🗂️ Estructura del proyecto

```text
libftprintf/
├── includes/
│   └── ft_printf.h
├── srcs/
│   ├── ft_printf.c
│   ├── ft_try_format.c
│   ├── ft_print_char.c
│   ├── ft_print_str.c
│   ├── ft_print_nbr.c
│   ├── ft_print_unsigned.c
│   ├── ft_print_hex.c
│   └── ft_print_ptr.c
├── Makefile
├── main.c
└── README.md
```

### Responsabilidad de cada archivo

| Archivo | Responsabilidad |
| :--- | :--- |
| `ft_printf.c` | Recorre la cadena de formato, imprime los caracteres normales y mantiene el contador total. |
| `ft_try_format.c` | Identifica el especificador y envía el argumento a la función correspondiente. |
| `ft_print_char.c` | Imprime caracteres y el símbolo `%`. |
| `ft_print_str.c` | Imprime cadenas y gestiona cadenas nulas. |
| `ft_print_nbr.c` | Convierte e imprime enteros con signo. |
| `ft_print_unsigned.c` | Convierte e imprime enteros sin signo. |
| `ft_print_hex.c` | Convierte e imprime números en base hexadecimal. |
| `ft_print_ptr.c` | Imprime direcciones de memoria en hexadecimal. |
| `ft_printf.h` | Contiene las inclusiones y los prototipos de las funciones. |
| `main.c` | Contiene pruebas comparativas con `printf()`. No forma parte de la biblioteca. |

---

## 🧠 Algoritmo seleccionado

### 1. Inicialización de los argumentos variádicos

Como `ft_printf` puede recibir un número variable de argumentos, se declara una variable de tipo `va_list`.

```c
va_list	args;

va_start(args, format);
```

`va_start` inicializa la lista utilizando `format`, que es el último parámetro fijo de la función.

Cuando termina el recorrido, se utiliza:

```c
va_end(args);
```

Esto completa correctamente el uso de la lista variádica.

### 2. Recorrido de la cadena de formato

La función recorre `format` carácter por carácter mediante un índice.

Mientras el carácter actual no sea `%`, se escribe directamente en la salida estándar:

```c
len += write(1, &format[i], 1);
```

El valor devuelto por la escritura se acumula en `len`, que representa el número total de caracteres impresos.

Cuando se encuentra `%`, el índice avanza hasta el carácter siguiente, que determina la conversión:

```c
i++;
len += ft_try_format(format[i], args);
```

### 3. Selección de la conversión

`ft_try_format` funciona como un despachador.

La función compara el especificador con las conversiones admitidas y obtiene el siguiente argumento mediante `va_arg` utilizando el tipo correspondiente.

Ejemplos:

```c
va_arg(args, int)
va_arg(args, char *)
va_arg(args, unsigned int)
```

Después llama a una función especializada:

```text
%c  ──> ft_print_char
%s  ──> ft_print_str
%p  ──> ft_print_ptr
%d  ──> ft_print_nbr
%i  ──> ft_print_nbr
%u  ──> ft_print_unsigned
%x  ──> ft_print_hex
%X  ──> ft_print_hex
%%  ──> ft_print_char
```

Cada función imprime su resultado y devuelve la cantidad de caracteres escritos.

### 4. Conversión de enteros con signo

Para `%d` y `%i`, `ft_print_nbr` utiliza `ft_itoa` de Libft:

1. Convierte el entero en una cadena.
2. Calcula la longitud de la cadena.
3. Escribe la cadena.
4. Libera la memoria reservada.
5. Devuelve la longitud impresa.

Este enfoque reutiliza una función ya comprobada de Libft y simplifica la gestión de números negativos y valores límite como `INT_MIN`.

### 5. Conversión de enteros sin signo

Para `%u`, primero se calcula la cantidad de dígitos decimales.

Después, el número se descompone utilizando:

```text
dígito = número % 10
número = número / 10
```

Los dígitos se introducen de derecha a izquierda en un búfer local de 11 caracteres, suficiente para almacenar cualquier valor de tipo `unsigned int` de 32 bits junto con el terminador nulo.

Finalmente, el búfer se escribe en una sola llamada a `write`.

### 6. Conversión hexadecimal

Para `%x` y `%X`, se selecciona una de estas bases:

```c
"0123456789abcdef"
"0123456789ABCDEF"
```

La conversión se realiza recursivamente:

1. Si el número es mayor o igual que 16, se procesa primero `n / 16`.
2. Se obtiene el dígito actual con `n % 16`.
3. Se escribe el carácter situado en esa posición de la base.

Este orden permite imprimir primero los dígitos más significativos.

La longitud se calcula por separado mediante divisiones sucesivas entre 16.

### 7. Conversión de punteros

Los punteros se representan en hexadecimal en minúsculas.

- Si el puntero es nulo, se imprime `(nil)`.
- En caso contrario, se imprime primero el prefijo `0x`.
- Después se convierte la dirección utilizando divisiones recursivas entre 16.

La longitud devuelta incluye tanto los dígitos de la dirección como los dos caracteres del prefijo.

### 8. Cálculo del valor de retorno

Todas las funciones auxiliares devuelven el número de caracteres que han impreso.

`ft_printf` acumula estos resultados:

```c
len += ft_try_format(format[i], args);
```

Al finalizar, devuelve `len`, siguiendo el comportamiento principal de `printf()` en condiciones normales de escritura.

---

## 🎯 Justificación del algoritmo

Se ha elegido un recorrido secuencial de la cadena de formato porque permite procesar la salida en el mismo orden en el que aparece en el texto.

La separación entre el recorrido principal y las funciones de conversión aporta varias ventajas:

- Cada función tiene una responsabilidad concreta.
- Las conversiones pueden probarse individualmente.
- El código principal permanece corto y legible.
- Añadir una nueva conversión requiere modificar principalmente el despachador y crear su función auxiliar.
- El contador de caracteres se mantiene de forma uniforme.
- No es necesario construir toda la salida en un búfer dinámico antes de imprimirla.

La recursividad utilizada para las conversiones hexadecimales permite escribir los dígitos desde el más significativo hasta el menos significativo sin invertir una cadena auxiliar.

Para `%u`, en cambio, se utiliza un búfer local porque el tamaño máximo de un `unsigned int` es conocido y se puede realizar la conversión sin reservar memoria dinámica.

Para `%d` e `%i`, se reutiliza `ft_itoa` de Libft. Esta decisión reduce la duplicación de lógica, aunque implica realizar una reserva dinámica que debe liberarse después de imprimir.

---

## 📊 Complejidad

Sea:

- `m` la longitud de la cadena de formato.
- `k` la longitud de una cadena impresa.
- `n` el valor numérico convertido.
- `b` la base utilizada.

### Complejidad temporal

- Recorrido del formato: `O(m)`.
- Impresión de una cadena: `O(k)`.
- Conversión numérica: `O(log_b(n))`.
- Procesamiento total: proporcional a la longitud del formato más la cantidad de caracteres generados.

### Complejidad espacial

- `%c` y `%%`: `O(1)`.
- `%s`: `O(1)` de espacio auxiliar.
- `%u`: `O(1)`, mediante un búfer local fijo.
- `%x`, `%X` y `%p`: `O(log16(n))` debido a la pila de llamadas recursivas.
- `%d` e `%i`: `O(log10(n))` por la cadena creada mediante `ft_itoa`.

---

## 🛠️ Instrucciones

### Requisitos

Para compilar el proyecto se necesita:

- Un compilador de C, como `cc`, `clang` o `gcc`.
- GNU Make.
- La biblioteca Libft.
- Un entorno compatible con `write`.
- Las flags `-Wall -Wextra -Werror`.

### Descargar el repositorio

```bash
git clone https://github.com/Kentliel/42Madrid_Student.git
cd 42Madrid_Student/libftprintf
```

### Configurar la dependencia de Libft

El código y el Makefile esperan encontrar Libft dentro de:

```text
libftprintf/libft/
```

En este repositorio, `libft` se encuentra al mismo nivel que `libftprintf`. Para utilizar la estructura actual sin duplicar la carpeta, se puede crear un enlace simbólico:

```bash
ln -s ../libft libft
```

La estructura resultante será:

```text
42Madrid_Student/
├── libft/
└── libftprintf/
    └── libft -> ../libft
```

Otra opción es copiar una versión completa de Libft dentro de `libftprintf/libft`.

### Compilar la biblioteca

```bash
make
```

Este comando:

1. Compila Libft mediante su regla `bonus`.
2. Compila los archivos de `ft_printf`.
3. Copia `libft.a` como base de `libftprintf.a`.
4. Añade los objetos de `ft_printf` mediante `ar rcs`.

El resultado es:

```text
libftprintf.a
```

### Reglas disponibles

```bash
make
```

Compila la biblioteca.

```bash
make clean
```

Elimina los archivos objeto de `ft_printf` y ejecuta la limpieza de Libft.

```bash
make fclean
```

Elimina los objetos, `libftprintf.a` y los archivos compilados de Libft.

```bash
make re
```

Ejecuta una recompilación completa.

> El Makefile actual no contiene una regla `make bonus` para `ft_printf`. La referencia a `bonus` pertenece a la compilación interna de Libft.

---

## 🕹️ Uso

### Programa de ejemplo

```c
#include "ft_printf.h"

int	main(void)
{
	int	printed;

	printed = ft_printf(
			"Hola %s | decimal: %d | hexadecimal: %x | puntero: %p\n",
			"42 Madrid",
			42,
			42,
			(void *)&printed);
	ft_printf("Caracteres impresos: %d\n", printed);
	return (0);
}
```

### Compilar el programa

Después de generar `libftprintf.a`:

```bash
cc -Wall -Wextra -Werror \
	-I includes \
	programa.c \
	-L. -lftprintf \
	-o programa
```

También puede enlazarse indicando directamente el archivo:

```bash
cc -Wall -Wextra -Werror \
	-I includes \
	programa.c \
	libftprintf.a \
	-o programa
```

### Ejecutar

```bash
./programa
```

---

## 🧪 Pruebas

El archivo `main.c` incluido compara el resultado y el valor de retorno de `ft_printf` con los de `printf`.

Para compilarlo:

```bash
make
cc -Wall -Wextra -Werror \
	-I includes \
	main.c \
	-L. -lftprintf \
	-o test_printf
```

Para ejecutar las pruebas:

```bash
./test_printf
```

Se recomienda comprobar, al menos:

- Caracteres normales y caracteres nulos.
- Cadenas vacías y cadenas `NULL`.
- Enteros positivos, negativos, `INT_MIN` e `INT_MAX`.
- Cero y `UINT_MAX`.
- Hexadecimales en minúsculas y mayúsculas.
- Punteros válidos y punteros nulos.
- Varios especificadores en una misma cadena.
- El valor de retorno.
- Porcentajes consecutivos.

Para detectar problemas de memoria:

```bash
valgrind --leak-check=full ./test_printf
```

---

## ⚠️ Limitaciones

Esta versión no reproduce todas las funcionalidades de `printf`.

No se incluyen:

- Flags como `-`, `0`, `#`, espacio o `+`.
- Anchura mínima de campo.
- Precisión.
- Modificadores como `h`, `hh`, `l`, `ll` o `z`.
- Conversiones como `%f`, `%e`, `%g`, `%o` o `%n`.
- Escritura en descriptores distintos de la salida estándar.

Estas funcionalidades no forman parte de las conversiones obligatorias implementadas en este proyecto.

---

## 📚 Recursos

### Documentación técnica

- [POSIX `printf` y familia de funciones](https://pubs.opengroup.org/onlinepubs/9799919799/functions/fprintf.html): comportamiento general de las cadenas de formato y las conversiones.
- [POSIX `<stdarg.h>`](https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/stdarg.h.html): documentación de `va_list`, `va_start`, `va_arg` y `va_end`.
- [`write(2)` — Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html): escritura de bytes en un descriptor de archivo.
- [GNU `ar` — Binary Utilities](https://sourceware.org/binutils/docs/binutils/ar.html): creación y mantenimiento de bibliotecas estáticas.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html): reglas, dependencias y automatización de la compilación.

### 🤖 Uso de inteligencia artificial

La inteligencia artificial se utilizó como recurso de aprendizaje y asistencia durante el desarrollo y la documentación de este proyecto. En concreto, se empleó para:

- Comprender el funcionamiento de las funciones variádicas y de las macros `va_start`, `va_arg` y `va_end`.
- Aclarar cómo los especificadores de formato determinan el tipo que debe extraerse de la lista de argumentos.
- Resolver dudas técnicas puntuales sobre la conversión de números decimales y hexadecimales.
- Entender el uso de la recursividad para imprimir números en base 16.
- Comprender la representación de punteros y el uso del prefijo `0x`.
