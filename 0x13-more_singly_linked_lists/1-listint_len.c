#include "lists.h"
/**
 * listint_len - find the length of a list
 * @h: pointer to the list
 *
 * Return: the number of elements in a linked `listint_t` list.
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *current = h;
	size_t count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	return (count);
}
