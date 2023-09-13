#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Note: A node of the express lane is placed every index which is
 * a multiple of the square root of the size of the list.
 *
 * Return: a pointer to the first node with @value, or NULL otherwise
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev;

	if (!list)
		return (NULL);

	do {
		prev = list;

		if (list->express)
			list = list->express;
		else
			while (list->next)
				list = list->next;

		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
	} while (list->n < value && list->next);

	printf("Value found between indexes ");
	printf("[%lu] and [%lu]\n", prev->index, list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
