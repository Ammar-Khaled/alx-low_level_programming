#include "lists.h"

/**
 * dlistint_len - find the length of a list
 * @h: pointer to the list
 *
 * Return: the number of elements in a linked `list_t` list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	return (count);
}

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to pointer to the list
 * @idx:  the index of the list where the new node should be added (0-based).
 * @n: the integer value of the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *head, *new;

	new = NULL;
	if (idx == 0)
		return (add_dnodeint(h, n));

	head = *h;
	i = 1;

	if (head)
	{
		while (head->prev)
			head = head->prev;

		while (head)
		{
			if (i == idx)
			{
				if (!head->next)
					new = add_dnodeint_end(h, n);
				else
				{
					new = malloc(sizeof(dlistint_t));
					if (!new)
						return (NULL);

					new->n = n;
					new->next = head->next;
					new->prev = head;
					head->next->prev = new;
					head->next = new;
				}
			}
			head = head->next;
			i++;
		}
	}

	return (new);
}
