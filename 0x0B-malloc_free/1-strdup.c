#include <stdlib.h>

/**
 * _strdup - duplicate a string
 * @str: pointer to the string to be duplicated
 * Return: NULL if str = NULL, otherwise returns a pointer to a
 * newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 */
char *_strdup(char *str)
{
	char *p;
	int size, i;

	if (str == NULL)
		return (NULL);

	i = 0;
	size = 0;
	while (str[i++] != '\0')
		size++;

	p = malloc(size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		p[i] = str[i];
	}

	return (p);
}
