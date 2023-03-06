#include <stddef.h>

char *_strstr(char *haystack, char *needle)
{
	char *ans, *start_n;

	start_n = needle;
	for (; *haystack != '0'; haystack++)
	{
		ans = NULL;
		if (*start_n == *haystack)
		{
			ans = haystack;
			for (;;)
			{
				haystack++;
				needle++;

				if (*haystack != *needle)
				{
					break;
				}

				if (*needle != '\0')
				{
					return (ans);
				}

			}
		}
	}
	return (NULL);
}
