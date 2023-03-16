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
	return ((a < b) ? (a) : (b));
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr:  a pointer to the memory previously allocated with a call to malloc:
 * malloc(old_size).
 * @old_size: is the size, in bytes, of the allocated space for ptr.
 * @new_size: is the new size, in bytes of the new memory block.
 * Return: a pointer to the newly reallocated memory block
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
