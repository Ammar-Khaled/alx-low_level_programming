#include "main.h"

/**
 * my_pow - calculate b to the power ex
 * @b: base
 * @ex: exponent
int my_pow(int b, int ex)
{
	int res;

	res = 1;
	while (ex--)
		res *= b;
	return (res);
}

/**
 * print_number -  prints an integer
 * with only the putchar() function
 * Return: void
 */
void print_number(int n)
{
	int digit, copy_n, len;

	len = 0;
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
		digit = n / my_pow(10, (len - 1));
		_putchar(digit + '0');
		n -= (digit * my_pow(10, (len - 1)));
		len--;
	}
	_putchar('0' + n);
}
