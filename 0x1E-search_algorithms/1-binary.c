#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: a pointer to the first element of the ascendingly sorted array
 * to search in
 * @size: the number of elements in the array
 * @value: the distinct value to search for
 *
 * Return: the index where @value is located, or -1 otherwise
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, left, right, mid;

	if (!array || size < 1)
		return (-1);

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%i, ", array[i]);

		printf("%i\n", array[right]);

		mid = left + (right - left) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
