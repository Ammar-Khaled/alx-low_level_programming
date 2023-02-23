/**
 * print_diagonal - draws a diagonal line on the terminal.
 *
 * Return: void
 */
void print_diagonal(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	int i, spaces;

	for (i = 0; i < n; i++)
	{
		spaces = i;
		while (spaces--)
			_putchar(' ');
		_putchar('\\');
		_putchar('\n');
	}
}
