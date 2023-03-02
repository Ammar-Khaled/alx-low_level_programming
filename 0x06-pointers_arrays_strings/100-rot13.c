#include "main.h"

/**
 * is_separator - checks weather the character is a word separator
 * @ch: the character to be checked
 * Return: 1 if the char is separator, 0 otherwise.
 */
int is_separator(char ch)
{
	char separators[] = {' ', '\t', '\n', ',', ';', '.',
			     '!', '?', '\"', '(', ')', '{', '}'};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (ch == separators[i])
			return (1);
	}

	return (0);
}

/**
 * rot13 - encodes a string using rot13 algorithm
 * @s: string to be encoed
 * Return: pointer to the resulting encoded string
 */
char *rot13(char *s)
{
	int i, idx;
	char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
			   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
			   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_separator(s[i]) || (s[i] >= '0' && s[i] <= '9'))
			continue;
		for (idx = 0; idx < 52; idx++)
		{
			if (s[i] == alphabet[idx])
				break;
		}
		s[i] = alphabet[(idx + 26) % 52];
	}
	return (s);
}