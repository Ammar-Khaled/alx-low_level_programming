#include "lists.h"
/**
 * delete_dnodeint_at_index -  deletes the node at index `index`
 * of a dlistint_t linked list.
 * @head: pointer to pointer to the list
 * @index: the index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h1, *h2;
	unsigned int i;

	h1 = *head;
	h2 = NULL;
	if (h1)
	{
		while (h1->prev)
			h1 = h1->prev;
	}

	i = 0;

	if (h1)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = h1->next;
				if (*head)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;
				if (h1->next)
					h1->next->prev = h2;
			}
			free(h1);
			return (1);
		}
		h2 = h1;
		h1 = h1->next;
		i++;
	}


	return (-1);
}
