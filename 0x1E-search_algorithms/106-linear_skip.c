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
	skiplist_t *go;

	if (list == NULL)
		return (NULL);

	go = list;

	do {
		list = go;
		go = go->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)go->index, go->n);
	} while (go->express && go->n < value);

	if (go->n < value)
	{
		list = go;
		while (go->next)
			go = go->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)go->index);

	while (list != go->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
