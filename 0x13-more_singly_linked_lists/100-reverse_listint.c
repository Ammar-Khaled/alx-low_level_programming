#include "lists.h"

/**
 * reverse_listint -  reverses a listint_t linked list.
 * @head: pointer to pointer to the list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next, *tmp;

	if (!(*head))
		return (NULL);

	next = (*head)->next;
	tmp = next->next;
	(*head)->next = NULL;
	while (tmp)
	{
		next->next = *head;
		*head = next;
		next = tmp;
		tmp = tmp->next;
	}
	next->next = *head;
	*head = next;

	return (NULL);
}
