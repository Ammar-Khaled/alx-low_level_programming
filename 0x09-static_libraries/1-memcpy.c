/**
 * _memcpy -  copies n bytes from memory area src to memory area dest
 * @dest: pointer to  the destination of copying
 * @src: pointer to  the source of copying
 * @n: number of bytes to be copied
 * Return: a pointer to dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *pd;

	pd = dest;
	while (n--)
	{
		*pd = *src;
		pd++;
		src++;
	}
	return (dest);
}
