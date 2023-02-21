#include "main.h"
/**
 * len - finds the length of a number
 * @n: the number
 * Return: How many digits the number consists of
 */
int len(int n)
{
	int ans;

	ans = 0;

	if (n == 0)
		return (1);

	while (n)
	{
		ans++;
		n /= 10;
	}
	return (ans);
}


/**
 * times_table - prints the xth times table, starting with 0.
 */
void print_times_table(int x)
{
int i, j, spaces, n, nn;
	
if (x > 15 || x < 0)
{
	_putchar('\n');
	return;
}

for (i = 0; i <= x; i++)
{
	for (j = 0; j <= x; j++)
	{
		n = i * j;
		nn = i * (j + 1);
		spaces = 4 - len(nn);
		if (n < 10)
			_putchar(n + '0');
		else if (n < 100)
		{
			_putchar((n / 10) + '0');
			_putchar((n % 10) + '0');
		}
		else
		{
			_putchar((n / 100) + '0');
			_putchar(((n / 10) % 10) + '0');
			_putchar((n % 10) + '0');
		}

		if (j != x)
		{
		_putchar(',');
		while (spaces--)
			_putchar(' ');
		}
		else
			_putchar('\n');
	}
}
}
