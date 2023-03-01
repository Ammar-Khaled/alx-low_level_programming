/**
 * _strncat - appends n bytes from the src string to the dest string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the destination string
 */
char *_strncat(char *dest, char *src, int n)
{
	char *tmp;

	tmp = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0' && n--)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (tmp);
}