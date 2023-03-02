#include "main.h"
/**
 * print_number - prints an integer in a recursive way
 * @n: the integer to be printed
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}

	if ((n / 10) > 0)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}