#include "lists.h"

/**
 * get_nodeint_at_index - gets the nth node of a listint_t linked list.
 * @head: pointer to the list
 * @index: the index of the desired node (starting from 0)
 *
 * Return: pointer to the desired node, or NULL if not exists
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current;
	unsigned int i;

	current = head;
	for (i = 0; current && i < index; i++)
	{
		current = current->next;
	}

	return (current);
}
