#include <stdlib.h>

/**
 * _calloc-  allocates memory for an array, using malloc.
 * @nmemb: nuber of elements in the array
 * @size: size of each element
 * Return: pointer to the allocated memory for an array of nmemb elements
 * each element is of size bytes
 * or NULL when failure or nmemb = 0 or size = 0
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	int i, n;

	if (nmemb == 0 || size == 0)
		return (NULL);

	n = nmemb * size;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);

	for (i = 0; i < n; i++)
		*((int *)ptr + i) = 0;

	return ((void *)ptr);
}
