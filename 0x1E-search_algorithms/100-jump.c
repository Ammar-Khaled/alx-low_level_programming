#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm with a jump step = sqrt(n).
 * @array: a pointer to the first element of the ascendingly sorted array
 * to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the first index where @value is located, or -1 otherwise
 * Note: compile with -lm to link <math.h>
 */
int jump_search(int *array, size_t size, int value)
{
	int step, i, j;

	if (!array || size < 1)
		return (-1);

	step = (int) sqrt(size);
	i = 0;
	while (array[i] < value)
	{
		printf("Value checked array[%i] = [%i]\n", i, array[i]);
		i += step;

		if (i > (int) size - 1)
			break;
	}
	printf("Value found between indexes [%i] and [%i]\n", i - step, i);

	for (j = i - step; j <= i && j < (int) size; j++)
	{
		printf("Value checked array[%i] = [%i]\n", j, array[j]);
		if (array[j] == value)
		{
			return (j);
		}
	}

	return (-1);
}
