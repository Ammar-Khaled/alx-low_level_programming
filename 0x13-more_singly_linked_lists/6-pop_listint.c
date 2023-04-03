#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to the pointer to the list
 *
 * Return: the head node’s data (n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *next_front;
	int n;

	if (!(*head))
		return (0);

	n = (*head)->n;
	next_front = (*head)->next;

	free(*head);
	*head = next_front;
	return (n);
}
