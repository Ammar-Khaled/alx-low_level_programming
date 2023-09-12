#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the advanced Binary search algorithm
 * @array: a pointer to the first element of the ascendingly sorted array
 * to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the `first` index where @value is located, or -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i, left, right, mid;

	if (!array || size < 1)
		return (-1);

	left = 0;
	right = size - 1;
	while (left < right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%i, ", array[i]);
		printf("%i\n", array[right]);

		mid = left + (right - left) / 2;
		if (array[mid] == value)
			right = mid;
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	if (left < 0 || left >= (int) size)
		return (-1);

	if (array[left] != value)
	{
		printf("Searching in array: %i\n", array[left]);
		return (-1);
	}

	return (left);
}
