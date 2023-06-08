#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into.
 * @key: the key you are looking for.
 *
 * Retrun: value associated with element, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long idx;

	if (!ht)
		return (NULL);

	if (strcmp(key, "") == 0 || !key)
		return (NULL);

	idx = hash_djb2((const unsigned char *)key) % ht->size;

	if (!ht->array[idx])
		return (NULL);

	return (ht->array[idx]->value);
}
