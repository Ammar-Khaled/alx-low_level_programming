#include "main.h"
/**
 * _strlen - computes the length of a string.
 * @s: pointer to string.
 * Return: How many characters the string contains.
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * puts_half - prints the second half of a string,
 * followed by a new line.
 * @str: pointer to the string
 */
void puts_half(char *str)
{
	int i, len;

	len = _strlen(str);
	i = len / 2;
	if (len % 2 == 1)
		i++;

	for (; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}