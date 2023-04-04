#include "lists.h"

/**
 * reverse_listint -  reverses a listint_t linked list.
 * @head: pointer to pointer to the list
 *
 * Return: pointer to the new reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prevNode, *curNode;

	if (!(*head))
		return (NULL);

	prevNode = (*head);
	*head = (*head)->next;
	curNode = *head;

	prevNode->next = NULL; /*disconnect first node*/

	while (*head)
	{
		*head = (*head)->next;
		curNode->next = prevNode;
		prevNode = curNode;
		curNode = (*head);
	}
	*head = prevNode;
	return (*head);
}
