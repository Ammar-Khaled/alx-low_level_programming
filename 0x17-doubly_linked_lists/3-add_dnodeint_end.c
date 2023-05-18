#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: pointer to the pointer to the list
 * @n: number to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tail;
	/* Create a new node */
	dlistint_t *new = (dlistint_t *)malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);

	new->next = NULL; /* as it will be at the end */
	new->n = n;

	if (!(*head)) /* if the new node is the first node */
	{
		*head = new;
		new->prev = NULL;
	}
	else /* Traverse the linked list until reaching the end */
	{
		tail = *head;
		while (tail->next)
			tail = tail->next;
		/* now tail points to the last node */
		new->prev = tail;
		tail->next = new;
	}

	return (new);
}
