#include "hash_tables.h"

/**
 * hash_table_delete- deletes a hash table.
 * @ht: is the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long i;
    hash_node_t *cur, *prev;

    if (!ht)
        return;

    /*free lists*/
    for (i = 0; i < ht->size; i++)
    {
        if (ht->array[i])
        {
            cur = ht->array[i];
            while ((prev = cur) != NULL)
            {
                cur = cur->next;
                if (prev->key)
                    free(prev->key);
                if (prev->value)
                    free(prev->value);
                free(prev);
            }
        }
    }

    /*free the table*/
    free(ht->array);
    free(ht);
}
