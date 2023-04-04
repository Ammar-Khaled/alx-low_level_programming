#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: pointer to the pointer to the list
 */
void free_listint2(listint_t **head)
{
	listint_t *next_node, *current;

	if (head)
	{

		current = *head;
		while (current)
		{
			/* Save the next pointer to a temporary variable */
			next_node = current->next;

			/* Free the current node */
			free(current);

			/* Set the current pointer to the next node */
			current = next_node;
		}

		*head = NULL;
	}
}
