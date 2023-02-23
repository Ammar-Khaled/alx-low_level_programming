#include "main.h"
/**
 * print_number -  prints an integer
 * with only the putchar() function
 * Return: void
 */
void print_number(int n)
{
	int digit, copy_n, len;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}

	copy_n = n;
	while (copy_n)
	{
		len++;
		copy_n /= 10;
	}

	while (n > 9)
	{
		digit = n / (10 * (len - 1));
		_putchar(digit + '0');
		n -= (digit * (10 * (len - 1)));
		len--;
	}
	_putchar('0' + n);
}
