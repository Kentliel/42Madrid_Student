# ft_printf
#### Porque ft_putnbr() y ft_putstr() no son suficientes

### *Este proyecto ha sido creado como parte del currículo de 42 por kcarrero 👨‍💻*

## 📌 Descripción (Description)

El objetivo de este proyecto es reimplementar la función `printf()` de la librería estándar de C (`libc`). Este desafío permite profundizar en el uso de **funciones variádicas** y en la creación de código bien estructurado y extensible. La librería final `libftprintf.a` se genera utilizando el comando `ar`.

---

## 🎯 Conversiones (Conversions)

La función gestiona los siguientes especificadores de formato:

| Especificador | Descripción |
| :--- | :--- |
| `%c` | Imprime un solo carácter. |
| `%s` | Imprime una cadena de caracteres. |
| `%p` | Imprime un puntero void en formato hexadecimal. |
| `%d` | Imprime un número decimal (base 10). |
| `%i` | Imprime un entero en base 10. |
| `%u` | Imprime un número decimal sin signo. |
| `%x` | Imprime un número hexadecimal (base 16) en minúsculas. |
| `%X` | Imprime un número hexadecimal (base 16) en mayúsculas. |
| `%%` | Imprime el símbolo del porcentaje. |

---

## 🛠️ Instrucciones (Instructions)

### Compilación
El `Makefile` entrega el archivo `libftprintf.a` en la raíz del repositorio y no realiza **relink**.

* **make**: Compila la librería.
```
make
```
* **make clean**: Elimina los archivos objeto.
```
make clean
```
* **make fclean**: Elimina objetos y la librería compilada.
```
make fclean
```
* **make re**: Recompila todo el proyecto.
```
make re
```
* **make bonus**: Compila las funciones bonus (si están incluidas).
```
make bonus
```

---

## 🕹️ Uso
Para utilizar la librería, incluye el header en tu código y enlaza el archivo `.a` al compilar:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola %s\n", "42 Madrid");
    return (0);
}
```

---

## 🧠 Algoritmo y Estructura (Algorithm & Structure)

* **Elección del Algoritmo:** He utilizado una estructura de control que identifica el especificador tras el símbolo `%`. La lógica se apoya en las macros de `<stdarg.h>` (`va_start`, `va_arg`, `va_end`) para gestionar los argumentos variables.

* **Estructura de Datos:** Se ha optado por un diseño modular donde cada conversión es manejada por una función específica, facilitando que el código sea extensible y fácil de mantener.

* **Retorno:** La función devuelve el número total de caracteres impresos, siguiendo el comportamiento de la función original.

---

## 📚 Recursos (Resources)

* **Documentación:** Referencias sobre funciones variádicas en C.

* **Norminette:** El código cumple estrictamente con la Norma de 42.
