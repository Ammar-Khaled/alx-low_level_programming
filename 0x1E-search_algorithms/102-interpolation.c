#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an ascendingly-sorted and
 * uniformly distributed array of integers using the Interpolation search.
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the `first` index where @value is located, or -1 otherwise
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t l, h, pos;

	if (!array || size < 1)
		return (-1);

	l = 0;
	h = size - 1;
	while (l <= h)
	{
		pos = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));

		printf("Value checked array[%lu]", pos);
		if (pos >= size)
		{
			printf(" is out of range\n");
			return (-1);
		}
		else
			printf(" = [%i]\n", array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			l = pos + 1;
		else
			h = pos - 1;
	}

	return (-1);
}
