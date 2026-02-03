# README

## Este proyecto ha sido creado como parte del currículo de 42 por kcarrero

# Description / Descripcion


**push_swap** is an algorithmic project whose goal is to sort a list of integers using
two stacks (`a` and `b`) and a very limited set of allowed operations.

The program receives a sequence of integers as arguments, stores them in stack **a**
(the first argument being at the top of the stack), and outputs to standard output the
smallest possible sequence of instructions that sorts the stack in ascending order.

The challenge of this project is not only to sort correctly, but to do so **efficiently**,
minimizing the number of operations. This requires careful algorithmic choices and a
good understanding of data structures and complexity.

----------------------------------------------------------------------

**push_swap** es un proyecto algorítmico cuyo objetivo es ordenar una lista de números enteros utilizando
dos pilas (`a` y `b`) y un conjunto muy limitado de operaciones permitidas.

El programa recibe una secuencia de números enteros como argumentos, los almacena en la pila **a**
(el primer argumento se encuentra en la parte superior de la pila) y envía a la salida estándar la
secuencia más pequeña posible de instrucciones que ordena la pila en orden ascendente.

El reto de este proyecto no es solo ordenar correctamente, sino hacerlo de forma **eficiente**,
minimizando el número de operaciones. Esto requiere una cuidadosa elección de los algoritmos y un
buen conocimiento de las estructuras de datos y la complejidad.


# Instructions / Instrucciones

**To compile the project:**

* make

**To recompile:**
* make re

**To delete compiled content:**
* make clean

**To delete everything:**
* make fclean

**Usage**
* ./push_swap 3 2 1

**To verify the correctness of the output, you can use the provided checker:**
* ./push_swap 3 2 1 | ./checker_linux 3 2 1

**Result**
* OK / KO (Error) 

You need the checker depending on whether it is for Mac or Linux. To test if you want to.

------------------------------------------------------------------------

**Para compilar el proyecto:**
* make

**Para recompilar:**
* make re

**Para borrar contenido compilado:**
* make clean

**Para borrar todo:**
* make fclean

**Uso**
* ./push_swap 3 2 1

**Para vereficar que son correctos los resultados, tienes que usar el checker:**
* ./push_swap 3 2 1 | ./checker_linux 3 2 1

**Resultado**
* OK / KO (Error)

Se necesita el checker dependiendo si es para mac o linux. Para hacer pruebas si quieres

# Resources / Recursos

**Algorithm & Data Structures**

Stack abstract data type:

* https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

Sorting algorithms overview:
* https://en.wikipedia.org/wiki/Sorting_algorithm

Radix sort:
* https://en.wikipedia.org/wiki/Radix_sort

**42 Documentation**

* push_swap subject (42 Intranet)

* Norminette rules

**Use of Artificial Intelligence**

AI tools (ChatGPT) were used as a learning and assistance resource during the
development of this project.
Specifically, AI was used to:

Clarify algorithmic concepts (radix sort, chunk-based sorting)

Review code structure and design decisions

Help debug logical errors and optimise performance.

All design decisions, code implementation, debugging, and final validation were
performed and understood by the author.

------------------------------------------------------------------------------
**Algoritmos y estructuras de datos**

Tipo de datos abstractos de pila:

* https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

Descripción general de los algoritmos de ordenación:
* https://en.wikipedia.org/wiki/Sorting_algorithm

Ordenación por radix:
* https://en.wikipedia.org/wiki/Radix_sort

**42 Documentación**

* Tema push_swap (42 Intranet)

* Reglas de Norminette

**Uso de inteligencia artificial**

Se utilizaron herramientas de IA (ChatGPT) como recurso de aprendizaje y asistencia durante el
desarrollo de este proyecto.
En concreto, la IA se utilizó para:

Aclarar conceptos algorítmicos (clasificación por radix, clasificación basada en fragmentos).

Revisar la estructura del código y las decisiones de diseño.

Ayudar a depurar errores lógicos y optimizar el rendimiento.

Todas las decisiones de diseño, la implementación del código, la depuración y la validación final fueron
realizadas y comprendidas por el autor.


# Extras

**Linked lists**
* https://www.tutorialesprogramacionya.com/estructurasdedatos/listasenlazadasc/tema8.html?utm_source=copilot.com

**atol**
* https://www.geeksforgeeks.org/c/atol-atoll-and-atof-functions-in-c-c/?utm_source=copilot.com

**Chunk**
* https://deepwiki.com/nach131/push_swap/4.3-chunk-based-sorting?utm_source=copilot.com

