#include <string.h>

/**
 * _is_palindrome - checks whether the array could be read from both ends
 * the same way or not
 * @s: the string
 * @len: the length of the string
 * Return: 1 if a string is a palindrome and 0 if not.
 */
int _is_palindrome(char *s, int len)
{
	if (len <= 1)
		return (1);
	return ((s[0] == s[len - 1] && _is_palindrome(s + 1, len - 2)));
}

/**
 * is_palindrome - checks whether the array could be read from both ends
 * the same way or not
 * @s: the string
 * Return: 1 if a string is a palindrome and 0 if not.
 */
int is_palindrome(char *s)
{
	int len;

	len = strlen(s);
	return (_is_palindrome(s, len));
}
