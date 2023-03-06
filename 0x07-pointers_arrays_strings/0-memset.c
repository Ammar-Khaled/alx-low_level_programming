/**
 * _memset -  fills the first n bytes of the memory area pointed to by s
 * with the constant byte b
 * @s: pointer to the memory area to fill
 * @b: the char to fill with
 * @n: number of bytes to be filled
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *ps;

	ps = s;
	while (n--)
	{
		*ps = b;
		ps++;
	}
	return (s);
}
