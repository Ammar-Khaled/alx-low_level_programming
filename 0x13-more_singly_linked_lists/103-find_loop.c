#include "lists.h"

/**
 * distance - finds the length of the list from `first` to `last`
 * @first: pointer to the first node
 * @last: pointer to the last node
 *
 * Return: the number of nodes between first and last
 */
size_t distance(listint_t *first, listint_t *last)
{
	int count = 0;
	listint_t *current = first;

	while (current != last)
	{
		current = current->next;
		count++;
	}

	return (count + 1);
}

/**
 * find_listint_loop - finds the loop in a linked list by storing the length
 * @head: pointer to the list
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *last;
	size_t previous_length;

	last = head;
	previous_length = 0;

	while (last && distance(head, last) > previous_length)
	{
		previous_length = distance(head, last);
		last = last->next;
	}

	return (last);
}
