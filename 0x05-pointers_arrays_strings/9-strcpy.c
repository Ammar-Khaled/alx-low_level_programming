/**
 * _strlen - computes the length of a string.
 * @s: pointer to string.
 * Return: How many characters the string contains.
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	for ( i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}