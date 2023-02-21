#include "main.h"

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
_putchar((_abs(n) % 10) + '0');
return (_abs(n) % 10);
}
