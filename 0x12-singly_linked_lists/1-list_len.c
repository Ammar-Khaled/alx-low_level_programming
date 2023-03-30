#include "lists.h"
/**
 * list_len - find the length of a list
 * @h: pointer to the list
 *
 * Return: the number of elements in a linked `list_t` list.
 */
size_t list_len(const list_t *h)
{
	const list_t *current = h;
	size_t count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	return (count);
}
