#include "main.h"
/**
 * print_triangle - prints a right-side triangle with 90-degree angle
 * @size: size of triangle
 * Return: void
 */

void print_triangle(int size)
{
	int i, s, h;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (i = 1; i <= size; i++)
	{
		s = size - i;
		while (s--)
			_putchar(' ');
		h = i;
		while (h--)
			_putchar('#');
		_putchar('\n');
	}
}
