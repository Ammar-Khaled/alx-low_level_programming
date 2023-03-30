#include "lists.h"

/**
 * free_list - frees a list_t list.
 * @head: pointer to the list
 */
void free_list(list_t *head)
{
	list_t *next_node = head;

	if (!head)
		return;

	while (head)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
}
