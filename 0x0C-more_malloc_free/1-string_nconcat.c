#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of characters to be concatenated from s2
 * Return: pointer to a newly allocated space in memory, which contains s1,
 * followed by the first n bytes of s2, and null terminated
 * or NULL when failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	int i, j, n1;

	if (s1)
		n1 = strlen(s1);
	else
		n1 = 0;
	
	if (s2 && n > strlen(s2))
		n = strlen(s2);
	else if (!s2)
		n = 0;
	
	ptr = malloc((n1 + n + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);

	i = 0;
	for (; n1--; i++)
		ptr[i] = s1[i];

	for (j = 0; n--; j++, i++)
		ptr[i] = s2[j];

	ptr[i] = '\0';

	return (ptr);
}
