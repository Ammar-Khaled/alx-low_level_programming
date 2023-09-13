#include "search_algos.h"

/**
 * jump_list - searches for a value in an ascendingly-sorted
 * singly-linked list of integers using the Jump search
 * with a jump step = sqrt(n).
 * @list: a pointer to the head of the list to search in.
 * @size: the number of nodes in @list.
 * @value: the value to search for
 *
 * Return: a pointer to the node with @value, or NULL otherwise
 * Time: O(?)
 * Note: compile with -lm to link <math.h>
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, limit;
	listint_t *prev;

	if (!list || size < 1)
		return (NULL);

	step = (size_t)sqrt((double)size);
	limit = 0;
	do
	{
		prev = list;

		limit += step;
		while (list->index < limit && list->next)
			list = list->next;

		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
	} while (list->n < value && list->next);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->index, (int)list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
