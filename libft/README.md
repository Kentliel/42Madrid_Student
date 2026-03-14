Libft
Este proyecto ha sido creado como parte del currículo de 42 por kcarrero

Description / Descripción
Libft is the first project at 42. Its goal is to create a static library containing a collection of re-implemented standard C functions, as well as additional functions that will be useful throughout the entire curriculum.
Understanding how these functions work under the hood is crucial for mastering memory management and data manipulation in C. This library serves as the foundation for all subsequent projects.

Libft es el primer proyecto de 42. Su objetivo es crear una librería estática que contiene una colección de funciones estándar de C re-implementadas, así como funciones adicionales que serán útiles a lo largo de todo el currículo.
Comprender cómo funcionan estas funciones internamente es crucial para dominar la gestión de memoria y la manipulación de datos en C. Esta librería sirve como base para todos los proyectos posteriores.

Instructions / Instrucciones
To compile the library:

Bash
make
To compile including bonus functions (linked lists):

Bash
make bonus
To recompile:

Bash
make re
To delete compiled objects (.o):

Bash
make clean
To delete everything (objects and .a):

Bash
make fclean
Para compilar la librería:

Bash
make
Para compilar incluyendo las funciones bonus (listas enlazadas):

Bash
make bonus
Para recompilar:

Bash
make re
Para borrar contenido compilado:

Bash
make clean
Para borrar todo:

Bash
make fclean

Functions / Funciones
🟢 Part 1: Libc Functions (Standard)

Function,Relevancia / Relevance
"ft_memset, ft_bzero, ft_memcpy, ft_memmove",Gestión directa de bloques de memoria. / Direct memory block management.
"ft_memchr, ft_memcmp",Búsqueda y comparación de bytes. / Byte searching and comparison.
"ft_strlen, ft_strlcpy, ft_strlcat",Manipulación básica de strings y seguridad de buffers. / Basic string manipulation and buffer safety.
"ft_strchr, ft_strrchr, ft_strnstr, ft_strncmp",Búsqueda y comparación de cadenas de texto. / String searching and comparison.
"ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint",Clasificación de caracteres (ASCII). / Character classification (ASCII).
"ft_toupper, ft_tolower",Conversión de mayúsculas/minúsculas. / Uppercase/lowercase conversion.
ft_atoi,Conversión de string a entero (fundamental para input). / String to integer conversion (key for input).
"ft_calloc, ft_strdup",Reserva de memoria dinámica segura (Heap). / Safe dynamic memory allocation (Heap).

🟡 Part 2: Additional Functions

Function,Relevancia / Relevance
"ft_substr, ft_strjoin, ft_strtrim",Creación y recorte de nuevas cadenas de texto. / Creation and trimming of new strings.
ft_split,División de strings por delimitador (Crucial en parsing). / String splitting by delimiter (Crucial for parsing).
ft_itoa,Conversión de entero a string. / Integer to string conversion.
"ft_strmapi, ft_striteri",Aplicación de funciones a cada carácter de un string. / Applying functions to each character of a string.
"ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd",Salida de datos utilizando File Descriptors. / Data output using File Descriptors.

🔵 Bonus: Linked Lists (Listas Enlazadas)
Functions: ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap.

Relevance: These functions allow managing dynamic data structures, essential for projects like push_swap or minishell.

Relevancia: Estas funciones permiten gestionar estructuras de datos dinámicas, esenciales para proyectos como push_swap o minishell.

Resources / Recursos
C Programming
C Library Functions: https://www.tutorialspoint.com/c_standard_library/index.htm

Memory Management: https://en.wikipedia.org/wiki/C_dynamic_memory_allocation

42 Documentation
Libft subject (42 Intranet)

Norminette rules

Use of Artificial Intelligence / Uso de Inteligencia Artificial
AI tools (ChatGPT/Gemini) were used as a learning and assistance resource during the development of this project. Specifically, AI was used to:

Clarify logic for complex functions like ft_split or ft_memmove.

Help debug edge cases (Null pointers, empty strings).

Review memory management and prevent potential leaks.
All final implementation and understanding of the code were performed by the author.

Se utilizaron herramientas de IA (ChatGPT/Gemini) como recurso de aprendizaje y asistencia durante el desarrollo de este proyecto. En concreto, la IA se utilizó para:

Aclarar la lógica de funciones complejas como ft_split o ft_memmove.

Ayudar a depurar casos límite (Punteros nulos, strings vacíos).

Revisar la gestión de memoria y evitar posibles fugas (leaks).
Toda la implementación final y la comprensión del código fueron realizadas por el autor.

Extras
Linked lists in C: https://www.geeksforgeeks.org/linked-list-set-1-introduction/

File Descriptors explained: https://en.wikipedia.org/wiki/File_descriptor
