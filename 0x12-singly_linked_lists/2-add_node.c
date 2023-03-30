#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: pointer to the pointer to the list
 * @str: string to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	int nchar;
	list_t *new = malloc(sizeof(list_t));

	if (!new)
		return (NULL);

	new->next = *head;
	*head = new;
	new->str = strdup(str);
	for (nchar = 0; str[nchar]; nchar++)
		;
	new->len = nchar;

	return (new);
}
