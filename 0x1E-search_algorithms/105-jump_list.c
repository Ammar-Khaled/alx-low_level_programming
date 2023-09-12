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
	int step, count;
	listint_t *i, *j;

	if (!list || size < 1)
		return (NULL);

	step = sqrt(size);

	i = j = list;
	count = step;
	while (count-- && i->next)
		i = i->next;

	while (1)
	{
		printf("Value checked array[%lu] = [%i]\n", i->index, i->n);
		if (i->n >= value)
			break;

		j = i;
		count = step;
		while (count-- && i->next)
			i = i->next;

		if (i->index >= size - 1)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", j->index, i->index);

	for (; j && j->index <= i->index && j->index < size; j = j->next)
	{
		printf("Value checked array[%lu] = [%i]\n", j->index, j->n);
		if (j->n == value)
		{
			return (j);
		}
	}

	return (NULL);
}
