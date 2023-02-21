#include "main.h"
/**
 * len - finds the length of a number
 * @n: the number 
 * Return: How many digits the number consists of
 */
int len(int n)
{
	int ans = 0;
	while (n)
	{
		ans++;
		n /= 10;
	}
	return n;
}


/**
 * times_table - prints the 9 times table, starting with 0.
 */
void times_table(void)
{
int i, j, spaces, nn;
for (i = 0; i < 10; i++)
{
	for (j = 0; j < 10; j++)
	{
		nn = i * j;
		spaces = 3 - len(nn);
		if (nn < 10)
			_putchar(nn + '0');
		else
		{
			_putchar((nn / 10) + '0');
			_putchar((nn % 10) + '0');
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
