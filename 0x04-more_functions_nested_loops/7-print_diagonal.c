#include "main.h"
/**
 * print_diagonal - draws a diagonal line on the terminal.
 * @n: hight of the diagonal
 * Return: void
 */
void print_diagonal(int n)
{
	int i;
	int spaces;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
	{
		spaces = i;
		while (spaces--)
			_putchar(' ');
		_putchar('\\');
		_putchar('\n');
	}
}
