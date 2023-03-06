#include <stddef.h>
#include <string.h>

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
