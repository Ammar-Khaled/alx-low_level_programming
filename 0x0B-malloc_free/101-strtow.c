#include <stdlib.h>
#include <limits.h>

/**
 * strtow - splits a string into words.
 * @str: pointer to the string to be splited
 * Return: pointer to the array of strings (words),
 * returns NULL if str is NULL or empty or failure
 */
char **strtow(char *str)
{
	char **p;
	int i, j, index, k, count;

	if (str == NULL || *str == '\0')
		return (NULL);

	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	if (count == 0)
		return (NULL);

	p = malloc((count * sizeof(char *)) + 1);
	if (p == NULL)
		return (NULL);

	count = j = index = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			count++;
		}
		else if (count != 0)
		{
			p[index] = malloc((sizeof(char) * count) + 1);
			for (j = 0, k = i - count; k < i; j++, k++)
			{
				p[index][j] = str[k];
			}
			p[index][j] = '\0';
			index++;
			count = j = 0;
		}
	}
	p[index] = NULL;
	return (p);
}
