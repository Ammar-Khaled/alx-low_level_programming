#include "search_algos.h"

/**
 * bs - searches for a value within a range in a sorted array
 * using the Binary search algorithm.
 * @array: a pointer to the first element of the ascendingly sorted array
 * to search in
 * @left: the left index
 * @right: the right index
 * @value: the value to search for
 *
 * Return: the first index where @value is located, or -1 otherwise
 */
int bs(int *array, int value, int left, int right)
{
	int i, mid;

	if (left < right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%i, ", array[i]);
		printf("%i\n", array[right]);

		mid = left + (right - left) / 2;
		if (array[mid] == value)
		{
			if (mid >= 1 && array[mid - 1] == value)
			{
				return (bs(array, value, left, mid));
			}
			else
			{
				return (mid);
			}
		}
		else if (array[mid] < value)
			return (bs(array, value, mid + 1, right));
		else
			return (bs(array, value, left, mid));
	}
	else
	{
		if (left < 0 || left > right)
			return (-1);

		if (array[left] != value)
		{
			printf("Searching in array: %i\n", array[left]);
			return (-1);
		}

		return (left);
	}
}

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
	if (!array || size < 1)
		return (-1);

	return (bs(array, value, 0, size - 1));
}
