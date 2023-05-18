#include "lists.h"

/**
 * get_dnodeint_at_index - gets the nth node of a dlistint_t linked list.
 * @head: pointer to the list
 * @index: the index of the desired node (starting from 0)
 *
 * Return: pointer to the desired node, or NULL if not exists
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	current = head;
	for (i = 0; current && i < index; i++)
	{
		current = current->next;
	}

	return (current);
}
