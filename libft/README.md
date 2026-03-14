# Libft
Este proyecto ha sido creado como parte del currículo de 42 por kcarrero

## Description / Descripción

Libft is the first project at 42. Its goal is to create a static library containing a collection of re-implemented standard C functions, as well as additional functions that will be useful throughout the entire curriculum.
Understanding how these functions work under the hood is crucial for mastering memory management and data manipulation in C. This library serves as the foundation for all subsequent projects.

Libft es el primer proyecto de 42. Su objetivo es crear una librería estática que contiene una colección de funciones estándar de C re-implementadas, así como funciones adicionales que serán útiles a lo largo de todo el currículo.
Comprender cómo funcionan estas funciones internamente es crucial para dominar la gestión de memoria y la manipulación de datos en C. Esta librería sirve como base para todos los proyectos posteriores.

## Instructions / Instrucciones

To compile the library (libft.a) / Para compilar la librería (libft.a):

Bash
```
make
```
---
To compile including bonus functions (linked lists) / Para compilar incluyendo las funciones bonus (listas enlazadas):

Bash
```
make bonus
```
---
To recompile everything from scratch / Para recompilar todo desde cero::

Bash
```
make re
```
---
To delete compiled objects (.o) / Para borrar los archivos objeto (.o):

Bash
```
make clean
```
---
To delete everything (objects and .a) / Para borrar los archivos objeto y el archivo de la librería (libft.a):

Bash
```
make fclean
```
---

## Functions / Funciones

### 🟢 Part 1: Libc Functions (Standard)

| Function  | Description |
| ------------- |:-------------:|
| Memory     | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`     |
| Strings      | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`     |
| Is/To      | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`     |
| Conversion      | `ft_atoi`     |

#### Memoria (Memory)

<details>
<summary>ft_memset</summary>

- Llena un bloque de memoria con un byte específico.
- Fills a block of memory with a specific byte.

</details>

<details>
<summary>ft_bzero</summary>

- Pone a cero (nulos) un bloque de memoria. 
- Sets a block of memory to zero (nulls).
</details>

<details>
<summary>ft_memcpy</summary>

- Copia un área de memoria a otra (sin solapamiento). 
- Copies one area of memory to another (without overlap).
</details>

<details>
<summary>ft_memmove</summary>

- Copia memoria de forma segura incluso si las áreas se solapan. 
- Copies memory safely even if the areas overlap.
</details>

<details>
<summary>ft_memchr</summary>

- Busca un carácter específico dentro de un bloque de memoria. 
- Searches for a specific character within a block of memory.
</details>

<details>
<summary>ft_memcmp</summary>

- Compara dos bloques de memoria byte a byte. 
- Compares two blocks of memory byte by byte.
</details>

<details>
<summary>ft_calloc</summary>

- Reserva memoria en el heap y la inicializa a cero. 
- Allocates memory on the heap and initialises it to zero.
</details>


#### Cadenas (Strings)

<details>
<summary>ft_strlen</summary>

- Calcula la longitud de una cadena (sin contar el nulo). 
- Calculates the length of a string (excluding the null terminator).
</details>

<details>
<summary>ft_strlcpy</summary>

- Copia una cadena a un tamaño de buffer específico (segura). 
- Copies a string to a buffer of a specific size (safe).
</details>

<details>
<summary>ft_strlcat</summary>

- Concatena cadenas garantizando la terminación en nulo. 
- Concatenates strings, ensuring null termination.
</details>

<details>
<summary>ft_strchr</summary>

- Busca la primera aparición de un carácter en una cadena. 
- Finds the first occurrence of a character in a string.
</details>

<details>
<summary>ft_strrchr</summary>

- Busca la última aparición de un carácter en una cadena. 
- Finds the last occurrence of a character in a string.
</details>

<details>
<summary>ft_strncmp</summary>

- Compara dos cadenas hasta un número n de caracteres. 
- Compares two strings up to a specified number of characters.
</details>

<details>
<summary>ft_strnstr</summary>

- Busca una subcadena dentro de otra, limitando la búsqueda. 
- Finds a substring within another, limiting the search.
</details>

<details>
<summary>ft_strdup</summary>

- Duplica una cadena reservando nueva memoria con `malloc`. 
- Duplicates a string by allocating new memory with `malloc`.
</details>


#### Clasificación y Conversión (Is/To & Conversion)

<details>
<summary>ft_isalpha / ft_isdigit / ft_isalnum</summary>

- Verifica si es letra, número o ambos. 
- Checks whether a character is a letter, a digit, or both.
</details>

<details>
<summary>ft_isascii / ft_isprint</summary>

- Verifica si es un carácter ASCII o si es imprimible. 
- Checks whether a character is ASCII or printable.
</details>

<details>
<summary>ft_toupper / ft_tolower</summary>

- Convierte caracteres a mayúsculas o minúsculas. 
- Converts characters to uppercase or lowercase.
</details>

<details>
<summary>ft_atoi</summary>

- Convierte una cadena de caracteres (ASCII) a un número entero (int). 
- Converts a character string (ASCII) to an integer (int).
</details>

### 🟡 Part 2: Additional Functions

| Function  | Description |
| ------------- |:-------------:|
| String Manipulation     | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`     |
| Conversion      | `ft_itoa`     |
| File Descriptors      | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`     |

### 🔵 Bonus: Linked Lists

| Function      | Description     |
| ------------- |:-------------:|
| structure `t_list`      | `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`     |

## Resources / Recursos

* C Programming & Data Structures
* Dynamic Memory Allocation:

Linked Lists:
![explicacion](https://encrypted-tbn0.gstatic.com/licensed-image?q=tbn:ANd9GcS4kDWRkCx3Vz2Ra8IZ2IbrdEv_KY-0mYlDswys95986I8pkaBxaexyieECx-dkKyfBdh0TVMSg_f7F0iN9fROOvM6WVeBhc9JX_NrDeOm1Zd9k0WY)

<details>
<summary>Overview</summary>

- The visualization uses block diagrams to illustrate the concept of redundancy in engineering and system design. Redundancy is the duplication of critical components or functions of a system with the intention of increasing reliability. These diagrams contrast a simple serial system with a more resilient parallel system.

</details>

<details>
<summary>Serial System</summary>

- The top diagram depicts a serial system. In this configuration, components are arranged in a single line, where the output of one component becomes the input for the next. This type of system is vulnerable because the failure of any single component will cause the entire system to fail.

</details>

<details>
<summary>Parallel System Introduction</summary>

- The bottom diagram introduces a parallel system, demonstrating a method to enhance reliability. Unlike the serial system, this design provides alternative paths for the process to continue. The white arrows indicate that the components from the serial system have been rearranged into a new configuration.

</details>

<details>
<summary>Parallel Redundancy</summary>

- Specifically, components 1 and 2 are now in a parallel arrangement. This means that if one of these components fails, the system can continue to function using the other. This is a common form of redundancy used to protect against single points of failure for critical functions at the beginning of a process.

</details>

<details>
<summary>Another Parallel Group</summary>

- Similarly, components 3 and 5 are also arranged in parallel. This redundancy ensures that the system can continue to operate even if one of these components fails. The system has multiple layers of protection.

</details>

<details>
<summary>System Resilience in Action</summary>

- The crossed-out block labeled '4' illustrates the resilience of the parallel system. Despite the failure of this component, the overall system can still function because there are alternative paths available. This highlights the key benefit of redundancy: increased system availability and fault tolerance.

</details>

* Makefiles: https://www.gnu.org/software/make/manual/make.html
* C Library Functions: https://www.tutorialspoint.com/c_standard_library/index.htm
* Memory Management: https://en.wikipedia.org/wiki/C_dynamic_memory_allocation

* 42 Documentation
* Libft subject (42 Intranet)
* Norminette: Code style compliance.

* Static Libraries: Understanding `ar rcs` and indexing.

## Use of Artificial Intelligence / Uso de Inteligencia Artificial

AI tools (ChatGPT/Gemini) were used as a learning and assistance resource during the development of this project. Specifically, AI was used to:

* Clarify logic for complex functions like `ft_split`.

* Help debug edge cases and memory management.

* Review the structure of the `Makefile`.

**All final implementation and understanding of the code were performed by the author.**

---
Se utilizaron herramientas de IA (ChatGPT/Gemini) como recurso de aprendizaje y asistencia durante el desarrollo de este proyecto. En concreto, la IA se utilizó para:

* Aclarar la lógica de funciones complejas como `ft_split`.

* Ayudar a depurar casos límite y gestión de memoria.

* Revisar la estructura del `Makefile`.

**Toda la implementación final y la comprensión del código fueron realizadas por el autor.**

## Extras

Linked lists in C: https://www.geeksforgeeks.org/linked-list-set-1-introduction/

File Descriptors explained: https://en.wikipedia.org/wiki/File_descriptor


