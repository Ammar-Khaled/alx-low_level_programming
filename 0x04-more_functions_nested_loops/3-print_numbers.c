/**
 * print_numbers - prints the numbers, from 0 to 9, followed by a new line.
 *
 * Return: void
 */
void print_numbers(void)
{
	int i;

	i = -1;
	while (++i < 10)
		_putchar(i + '0');
	_putchar('\n');
}
