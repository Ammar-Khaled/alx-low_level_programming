#include "main.h"

#include <unistd.h>
/**
 *
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.  
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1)); 
}

/**
 * _abs - computes the absolute value of an integer.
 * @n: the number to get its absolute
 * Return: the absolute value of an integer.
 */
int _abs(int n)
{
if (n >= 0)
	return (n);
else
	return (-1 * n);
}

/**
 * print_last_digit -  prints the last digit of a number.
 * @n: the number
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
int digit;
  
digit = _abs(n) % 10;
_putchar(digit);
return (digit);
}
