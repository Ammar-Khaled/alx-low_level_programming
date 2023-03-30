#include "lists.h"
#include <string.h>
/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: pointer to the pointer to the list
 * @str: string to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	int nchar;
	list_t *tail;
	/* Create a new node */
	list_t *new = (list_t *)malloc(sizeof(list_t));

	if (!new)
		return (NULL);

	new->next = NULL; /* as it will be at the end */
	new->str = strdup(str);
	for (nchar = 0; str[nchar]; nchar++);
	new->len = nchar;
	
	if (!(*head)) /* if the new node is the first node */
	{
		*head = new;
	}
	else /* Traverse the linked list until reaching the end */
	{
		tail = *head;
		while (tail->next)
			tail = tail->next;
		tail->next = new;
	}

	return (new);
}
