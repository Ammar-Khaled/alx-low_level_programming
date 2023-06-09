#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *ptr;
	unsigned long i;
	char *separator;

	if (!ht)
		return;

	printf("{");
	separator = "";
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			ptr = ht->array[i];
			while (ptr)
			{
				printf("%s'%s': '%s', ", separator, ptr->key, ptr->value);
				separator = ", ";
				ptr = ptr->next;
			}
		}
	}

	printf("}\n");
}
