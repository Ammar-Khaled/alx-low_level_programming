#include <stdlib.h>
#include <string.h>
/**
 * min - find min of two nums
 * @a: first num
 * @b: second num
 * Return: min of a and b
*/
int min(int a, int b)
{
	return (a < b) ? (a) : (b);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *tmp;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size == new_size)
		return (ptr);

	tmp = malloc(new_size);
	memcpy(tmp, ptr, min(old_size, new_size));
	free(ptr);
	return (tmp);
}
