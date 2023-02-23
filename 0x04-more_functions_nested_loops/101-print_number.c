#include "main.h"
/**
 * print_number -  prints an integer
 * with only the putchar() function.
 * recursive implementation.
 * Return: void
 */
void print_number(int n)
{
	int digit;

	if (n < 10)
	{
		if (n < 0)
		{
			_putchar('-');
			n *= -1;
		}
		_putchar('0' + n);
		return;
	}
	digit = n % 10;
	print_number(n / 10);
	if (digit >= 0)
		_putchar('0' + digit);
	else
		_putchar('0' + (-1 * digit));
}
