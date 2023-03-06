#include <stddef.h>
/**
 * accepted - checks whether the char c is in the string accept
 * @c: the character to be looked for
 * @accept: pointer to the string to be searched
 * Return: 1 if c exists in accept, 0 otherwise
 */
int accepted(char c, char *accept)
{
	while (*accept != '\0')
	{
		if (c == *accept)
			return (1);
		accept++;
	}
	return (0);
}

/**
 * _strpbrk - function locates the first occurrence in the string s
 * of any of the bytes in the string accept
 * @s: pointer to the string
 * @accept: pointer to the allowed string
 * Return: pointer to the first occurrence in the string s
 * of any of the bytes in the string accept
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		if (accepted(*s, accept))
			return s;
		s++;
	}
	return (NULL);
}
