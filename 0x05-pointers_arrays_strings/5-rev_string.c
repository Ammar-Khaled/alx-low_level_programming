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
 * rev_string - reverses a string.
 * @s: pointer to the string
 */
void rev_string(char *s)
{
	int len, i, j;

	len = _strlen(s);
	i = 0;
	j = len - 1;
	while (i <= j)
	{
		s[j] = s[i];
		i++;
		j--;
	}
}