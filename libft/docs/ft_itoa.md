# ES
## ft\_itoa, ft\_ltoa\_base, ft\_itopa
### Prototipo y descripción
```c
char	*ft_itoa(int n);
char	*ft_ltoa_base(long lnbr, char *base);
char	*ft_ltopa(long lnbr);
```
#### Descripción
ft\_itoa (y sus derivados) tiene como función principal devolver en formato string estandar (según ANSI C89) los dígitos del entero **n** o su equivalente **lnbr**.

ft\_ltoa\_base entiende la base como la representación de los dígitos y se encuentran en orden de valor según el TFN teniendo 5 en 01234567 el valor absoluto de 5 y el valor posicional correspondiente a su posición multiplicada por la longitud de la base. La base de ft\_ltoa\_base no puede ni los caracteres '+', '-' ni contener caracteres duplicados.

ft\_ltopa usa la base hexadecimal minuscula "0123456789abcdef" y añade 0x al principio.
#### Retorno
Todas las funciones devuelven una cadena de caracteres que contiene, bajo el estandar ASCI los caracteres equivalentes a los digitos en el mismo orden de aparición en el entero, la cadena se reserva en heap mediante malloc(2), en caso de no poderse reservar memoria devuelve un puntero nulo.
#### Errores conocidos
No se conoce ningún error en este momento.
#### Detalles de implementación.
Todas las funciones usan malloc(2).

La función ft\_ltopa usa por dentro ft\_ltoa\_base y ft\_strjoin.
