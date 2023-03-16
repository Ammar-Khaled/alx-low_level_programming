#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
 * _realloc - reallocates a memory block using malloc and free
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *tmp;
	int i;

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
	strncpy(tmp, ptr, min(old_size, new_size));
	free(ptr);
	return (tmp);
}
