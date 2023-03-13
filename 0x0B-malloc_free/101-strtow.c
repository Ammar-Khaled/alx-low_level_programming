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
	char word[INT_MAX];

	if (str == NULL || *str == '\0') return (NULL);

	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i + 1] == ' ')
			count++;
	}

	p = malloc((count * sizeof(char *)) + 1);
	if (p == NULL)
		return (NULL);

	count = j = index = 0;
	*word = '\0';
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			word[j++] = str[i];
			count++;
		}	
		else if (*word != '\0')
		{
			p[index] = malloc((sizeof(char) * count) + 1);
			for (k = 0; k < count; k++)
			{
				p[index][k] = word[k];
			}
			p[index][k] = '\0';
			index++;
			count = j = 0;
			*word = '\0';
		}
	}
	p[index] = NULL;
	return (p);
}
