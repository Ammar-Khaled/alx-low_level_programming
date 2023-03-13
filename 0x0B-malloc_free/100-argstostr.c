#include <stdlib.h>

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
		i++;

	return (i);
}

/**
 * argstostr - concatenates all the arguments
 * of the program with new line in between.
 * @ac: number of arguments
 * @av: pointer to the array of arguments
 * Return: NULL if ac == 0 or av == NULL,
 * a pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int index, len, i, j;

	if (ac == 0 || av == NULL)
		return (NULL);

	len = 0;
	for (i = 0; i < ac; i++)
		len += _strlen(av[i]) + 1;
	len++;

	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

	index = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			str[index++] = av[i][j];
		str[index++] = '\n';
	}
	str[index] = '\0';

	return (str);
}
