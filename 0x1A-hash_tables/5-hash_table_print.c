#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *ptr;
	unsigned long i;
	int is_there_any = 0;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			ptr = ht->array[i];
			while (ptr)
			{
				printf("'%s': '%s', ", ptr->key, ptr->value);
				is_there_any = 1;
				ptr = ptr->next;
			}
		}
	}
	if (is_there_any)
	{
		printf("\b\b}\n");
	}
	else
	{
		printf("}\n");
	}
}
