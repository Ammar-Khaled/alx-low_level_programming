/**
 * print_triangle - prints a right-side triangle with 90-degree angle
 *
 * Return: void
 */

void print_triangle(int size)
{
	int i, s, h;

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
