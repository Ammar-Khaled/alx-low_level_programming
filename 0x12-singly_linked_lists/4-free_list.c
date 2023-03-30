#include "lists.h"

/**
 * free_list - frees a list_t list.
 * @head: pointer to the list
 */
void free_list(list_t *head)
{
	list_t *next_node;

	while (head)
	{
		/* Save the next pointer to a temporary variable */
		next_node = head->next;

		/* Free the current node */
		free(head->str);
		free(head);

		/* Set the current pointer to the next node */
		head = next_node;
	}
}
