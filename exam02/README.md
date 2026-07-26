*These exercises have been created by kcarrero as part of the ‘42’ curriculum.*

# 💻 Exam02 — Ejercicios de C

## 📖 Descripción

Este repositorio reúne soluciones de práctica para **Exam02**, organizadas por niveles de dificultad. El objetivo es reforzar los fundamentos de programación en C mediante ejercicios breves e independientes, similares a los que pueden aparecer durante un examen de la escuela 42.

Los ejercicios trabajan, entre otros, los siguientes conceptos:

- 🔤 Manipulación de cadenas y caracteres.
- 👉 Uso de punteros y gestión de memoria dinámica.
- 🔢 Operaciones matemáticas y conversión de bases.
- 🧩 Manipulación de bits.
- 🔗 Listas enlazadas.
- 🔁 Recursividad, ordenación y algoritmos básicos.
- ⌨️ Procesamiento de argumentos recibidos por línea de comandos.

Cada ejercicio se encuentra en su propia carpeta y contiene su correspondiente implementación en C. Algunos ejercicios son programas completos con una función `main`, mientras que otros implementan únicamente una función que debe probarse mediante un archivo de test independiente.

## 📂 Estructura del repositorio

```text
exam02/
├── level1/
├── level2/
├── level3/
└── level4/
```

El repositorio contiene un total de **57 ejercicios**, distribuidos en cuatro niveles.

### 🟢 Nivel 1

Ejercicios introductorios centrados principalmente en caracteres, cadenas, salida estándar y funciones básicas.

`first_word`, `fizz_buzz`, `ft_putstr`, `ft_strcpy`, `ft_strlen`, `ft_swap`, `repeat_alpha`, `rev_print`, `rot_13`, `rotone`, `search_and_replace` y `ulstr`.

### 🟡 Nivel 2

Ejercicios sobre transformación de cadenas, comparación, conversión numérica, búsqueda de caracteres y operaciones a nivel de bits.

`alpha_mirror`, `camel_to_snake`, `do_op`, `ft_atoi`, `ft_strcmp`, `ft_strcspn`, `ft_strdup`, `ft_strpbrk`, `ft_strrev`, `ft_strspn`, `inter`, `is_power_of_2`, `last_word`, `max`, `print_bits`, `reverse_bits`, `snake_to_camel`, `swap_bits`, `union` y `wdmatch`.

### 🟠 Nivel 3

Ejercicios de dificultad intermedia que incluyen matemáticas, asignación dinámica, conversión de bases, listas enlazadas y tratamiento avanzado de cadenas.

`add_prime_sum`, `epur_str`, `expand_str`, `ft_atoi_base`, `ft_list_size`, `ft_range`, `ft_rrange`, `hidenp`, `lcm`, `paramsum`, `pgcd`, `print_hex`, `rstr_capitalizer`, `str_capitalizer` y `tab_mult`.

### 🔴 Nivel 4

Ejercicios de mayor complejidad relacionados con recursividad, listas enlazadas, memoria dinámica, división de cadenas y algoritmos de ordenación.

`flood_fill`, `fprime`, `ft_itoa`, `ft_list_foreach`, `ft_list_remove_if`, `ft_split`, `rev_wstr`, `rostring`, `sort_int_tab` y `sort_list`.

## 🛠️ Instrucciones

### ✅ Requisitos

Para compilar y ejecutar los ejercicios se necesita:

- Un sistema compatible con Unix, como Linux o macOS.
- Un compilador de C, como `cc`, `gcc` o `clang`.
- Opcionalmente, `Norminette` para comprobar el estilo del código.

### 📥 Clonar el repositorio

```bash
git clone https://github.com/Kentliel/42Madrid_Student.git
cd 42Madrid_Student/exam02
```

### ⚙️ Compilar un programa completo

Los ejercicios que contienen una función `main` pueden compilarse directamente. Por ejemplo:

```bash
cd level1/first_word
cc -Wall -Wextra -Werror first_word.c -o first_word
```

Después se puede ejecutar el programa pasando los argumentos que requiera:

```bash
./first_word "Hola mundo"
```

### 🧪 Compilar una función sin `main`

Algunos ejercicios implementan únicamente una función. En ese caso, se puede comprobar primero que el archivo compila correctamente generando un archivo objeto:

```bash
cd level1/ft_strlen
cc -Wall -Wextra -Werror -c ft_strlen.c
```

Para ejecutar y probar la función es necesario crear un archivo `main.c` propio y compilarlo junto con la solución:

```bash
cc -Wall -Wextra -Werror main.c ft_strlen.c -o test
./test
```

Cuando el ejercicio incluya un archivo de cabecera, también debe conservarse en el mismo directorio o añadirse su ruta mediante la opción `-I`:

```bash
cc -Wall -Wextra -Werror main.c ft_list_size.c -I. -o test
```

### 📏 Comprobar el estilo

Si `Norminette` está instalada, se puede ejecutar sobre un archivo o sobre un nivel completo:

```bash
norminette level1/first_word/first_word.c
norminette level3/
```

### 🧠 Comprobar fugas de memoria

En los ejercicios que utilizan memoria dinámica, puede utilizarse `Valgrind` en Linux:

```bash
valgrind --leak-check=full ./test
```

Los argumentos y el resultado esperado dependen de cada ejercicio. Se recomienda revisar el código fuente y probar casos normales, entradas vacías, caracteres especiales y valores límite.

## 🚀 Ejemplos de uso

### `fizz_buzz`

```bash
cd level1/fizz_buzz
cc -Wall -Wextra -Werror fizz_buzz.c -o fizz_buzz
./fizz_buzz
```

### `do_op`

```bash
cd level2/do_op
cc -Wall -Wextra -Werror do_op.c -o do_op
./do_op 21 + 21
```

### 🔍 Probar una función con un archivo externo

Ejemplo de estructura para probar una función que no contiene `main`:

```text
ejercicio/
├── funcion.c
├── funcion.h
└── main.c
```

Compilación:

```bash
cc -Wall -Wextra -Werror main.c funcion.c -o test
./test
```

## 📚 Recursos

- [Referencia del lenguaje C — cppreference](https://en.cppreference.com/w/c/)
- [Manual del lenguaje C de GNU](https://www.gnu.org/software/c-intro-and-ref/manual/c-intro-and-ref.html)
- [Manual de la biblioteca estándar de GNU C](https://www.gnu.org/software/libc/manual/)
- [Linux man-pages](https://man7.org/linux/man-pages/)
- [Norminette de 42](https://github.com/42School/norminette)
- Manuales disponibles desde la terminal, especialmente `man 2 write`, `man 3 malloc`, `man 3 free` y `man 3 string`.
