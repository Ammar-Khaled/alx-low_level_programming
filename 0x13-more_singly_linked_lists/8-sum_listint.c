#include "lists.h"

/**
 * sum_listint - sum of all the data (n) of a listint_t linked list.
 * @head: pointer to the list
 *
 * Return: the sum, or 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	const listint_t *current = head;

	while (current)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
