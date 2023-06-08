#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: the hash table you want to add or update the key/value to.
 * @key: the key, that can not be an empty string
 * @value: the value associated with the key. it can be duplicated or empty
 *
 * In case of collision, function adds new node at the beginning of the list
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long idx;
	hash_node_t *new_node;

	if (!ht)
		return (0);

	if (strcmp(key, "") == 0 || !key)
		return (0);

	idx = hash_djb2((const unsigned char *)key) % ht->size;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

	new_node->key = (char *) key;
	new_node->value = (char *) value;

	if (!ht->array[idx])
	{
		/*this is the first node at this idx*/
		ht->array[idx] = new_node;
		new_node->next = NULL;
	}
	else
	{
		/*add the new node at the begin of the list at idx*/
		new_node->next = ht->array[idx];
		ht->array[idx] = new_node;
	}

	return (1);
}
