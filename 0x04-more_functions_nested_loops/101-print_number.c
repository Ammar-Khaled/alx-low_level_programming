#include "main.h"
/**
 * print_number - prints an integer in a recursive way
 * @n: the integer to be printed
 */
void print_number(int n)
{
	unsigned int num;

	num = n;
	if (n < 0)
	{
		_putchar('-');
		num *= -1;
	}

	if ((num / 10) > 0)
		print_number(num / 10);

	_putchar((num % 10) + '0');
}
