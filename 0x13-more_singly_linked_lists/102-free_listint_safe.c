#include "lists.h"

/**
 * len - finds the length of the list from `first` to `last`
 * @first: pointer to the first node
 * @last: pointer to the last node
 *
 * Return: the number of nodes between first and last
 */
size_t len(listint_t *first, listint_t *last)
{
	int count = 0;
	listint_t *current = first;

	while (current != last)
	{
		current = current->next;
		count++;
	}

	return (count + 1);
}

/**
 * free_listint_safe - free a listint_t linked list with a loop
 * @head: pointer to pointer to the list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *tmp;

	current = *h;
	while (current->next)
	{
		tmp = current->next;
		free(current);
		current = tmp;
		count++;
	}
	*h = NULL;
	return (count);
}
