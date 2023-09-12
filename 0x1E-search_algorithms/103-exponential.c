#include "search_algos.h"

/**
 * exponential_search - searches for a value in an ascendingly-sorted
 * array of integers using the Exponential search with powers of 2 as ranges.
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the `first` index where @value is located, or -1 otherwise
 * Time: O(log(i))
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, left, right, mid;

	if (!array || size < 1)
		return (-1);
	i = 1;
	while (i < size && array[i] < value)
	{
		printf("Value checked array[%lu] = [%i]\n", i, array[i]);
		i *= 2;
	}
	printf("Value found between indexes [%lu] and ", i / 2);
	left = i / 2;
	if (i >= size)
	{
		printf("[%lu]\n", size - 1);
		right = size - 1;
	}
	else
	{
		printf("[%lu]\n", i);
		right = i;
	}
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
