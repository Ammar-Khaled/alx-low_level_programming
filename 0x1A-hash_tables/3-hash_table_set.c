#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: the hash table you want to add or update the key/value to.
 * @key: the key, that can not be an empty string
 * @value: the value associated with the key. it is duplicated and can be empty
 *
 * In case of collision, function adds new node at the beginning of the list
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long idx;
	hash_node_t *new_node, *ptr;

	if (!ht)
		return (0);

	if ( (*key) == '\0' || !key)
		return (0);

	idx = key_index((unsigned char *)key, ht->size);
	ptr = ht->array[idx];

	/*if `key` is already exists, just update its corresponding value.*/
	while (ptr)
	{
		if (strcmp(ptr->key, key) == 0)
		{
			free(ptr->value);
			ptr->value = strdup(value);
			return (1);
		}
		ptr = ptr->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	return (1);
}
