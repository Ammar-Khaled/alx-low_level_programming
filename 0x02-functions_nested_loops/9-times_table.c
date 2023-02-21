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
		return 1;
	
	while (n)
	{
		ans++;
		n /= 10;
	}
	return (ans);
}


/**
 * times_table - prints the 9 times table, starting with 0.
 */
void times_table(void)
{
int i, j, spaces, n, nn;
for (i = 0; i < 10; i++)
{
	for (j = 0; j < 10; j++)
	{
		n = i * j;
		nn = i * (j + 1);
		spaces = 3 - len(nn);
		if (n < 10)
			_putchar(n + '0');
		else
		{
			_putchar((n / 10) + '0');
			_putchar((n % 10) + '0');
		}
		if (j != 9)
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
