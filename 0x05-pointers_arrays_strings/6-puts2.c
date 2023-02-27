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
 * puts2 -  prints every other character of a string, starting with the first character,
 * followed by a new line.
 * @str: pointer to the string
 */
void puts2(char *str)
{
	int i;

	for (i = 0; i < _strlen(str); i+=2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
