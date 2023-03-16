#include <stdlib.h>

/**
 * array_range - creates an array of integers of specific range
 * @min: the lower bound of the range
 * @max: the upper bound of the range
 * Return: the pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int n, i, val;
	int *ptr;

	if (min > max)
		return (NULL);

	n = max - min + 1;

	ptr = malloc(n * sizeof(int));
	if (!ptr)
		return (NULL);

	val = min;
	for (i = 0; i < n; i++, val++)
		ptr[i] = val;

	return (ptr);
}
