#include "lists.h"
/**
 * dlistint_len - find the length of a list
 * @h: pointer to the list
 *
 * Return: the number of elements in a linked `list_t` list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	return (count);
}
