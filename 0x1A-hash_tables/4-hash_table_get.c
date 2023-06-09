#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into.
 * @key: the key you are looking for.
 *
 * Return: value associated with element, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long idx;
	hash_node_t *ptr;

	if (!ht)
		return (NULL);

	if (*key == '\0' || !key)
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);
	ptr = ht->array[idx];

	while (ptr)
	{
		if (strcmp(ptr->key, key) == 0)
			return (ptr->value);
		ptr = ptr->next;
	}

	return (NULL);
}
