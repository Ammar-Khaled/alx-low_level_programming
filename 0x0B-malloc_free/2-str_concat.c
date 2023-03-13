#include <stdlib.h>
/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 * Return: a pointer to a newly allocated space in memory which contains
 * the contents of s1, followed by the contents of s2, and null terminated
 * and NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	int size, i, j;
	char *p;

	i = 0;
	size = 0;
	if (s1 != NULL)
	{
		while (s1[i++] != '\0')
			size++;
	}

	i = 0;
	if (s2 != NULL)
	{
		while (s2[i++] != '\0')
			size++;
	}
	/* increase size for the null byte */
	size++;

	p = malloc(size);
	if (p == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		p[i] = s1[i];

	for (j = 0; s2[j] != '\0'; j++, i++)
	{
		p[i] = s2[j];
	}

	p[i] = '\0';
	return (p);
}
