#include "lists.h"
#include <stdio.h>

/**
 * length - finds the length of the list from `first` to `last`
 * @first: pointer to the first node
 * @last: pointer to the last node
 *
 * Return: the number of nodes between first and last
 */
size_t length(const listint_t *first, const listint_t *last)
{
	int count = 0;
	const listint_t *current = first;

	while (current != last)
	{
		current = current->next;
		count++;
	}

	return (count + 1);
}

/**
 * print_listint_safe - prints a listint_t linked list with a loop
 * @head: pointer to the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0, previous_length = 0;
	const listint_t *first, *last;

	first = last = head;
	while (last && length(first, last) > previous_length)
	{
		previous_length = length(first, last);

		printf("[%p] %i\n", (void *)last, last->n);
		count++;
		last = last->next;
	}

	if (last)
	{
		printf("-> [%p] %i\n", (void *)last, last->n);
	}

	return (count);
}
