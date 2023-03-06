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
 * _strspn -  gets the length of a prefix substring.
 * @s: pointer to the main string
 * @accept: pointer to the prefix string
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int ans;

	ans = 0;
	while (*s != '\0')
	{
		if (accepted(*s, accept))
		{
			ans++;
			s++;
		}
		else
			break;
	}
	return (ans);
}
