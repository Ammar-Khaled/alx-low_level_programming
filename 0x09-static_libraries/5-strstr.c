#include <stddef.h>
#include <string.h>

/**
 * _strstr - locates a substring.
 * @haystack: the main string to search
 * @needle: the substring to search for
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	size_t i, j;

	for (i = 0; i < strlen(haystack); i++)
	{
		for (j = 0; j < strlen(needle); j++)
		{
			if (haystack[j + i] != needle[j])
				break;
		}

		if (j == strlen(needle))
		{
			return (&haystack[i]);
		}
	}

	return (NULL);
}
