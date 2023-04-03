#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: pointer to the list
 */
void free_listint(listint_t *head)
{
	listint_t *next_node;

	while (head)
	{
		/* Save the next pointer to a temporary variable */
		next_node = head->next;

		/* Free the current node */
		free(head);

		/* Set the current pointer to the next node */
		head = next_node;
	}
}
