#include "main.h"

/**
 * rot13 - encodes a string using rot13 algorithm
 * @s: string to be encoed
 * Return: pointer to the resulting encoded string
 */
char *rot13(char *s)
{

	char letters[] = {'a', 'e', 'o', 't', 'l', 'A', 'E', 'O', 'T', 'L'};
	char encoded[] = {'4', '3', '0', '7', '1'};
	int i, j;


	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_separator(s[i]))
			continue;

		

	}
	
}